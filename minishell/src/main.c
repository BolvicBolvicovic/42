/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:49 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/17 18:34:25 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	g_status;

char	*ft_strcat_path(char *dest, char *src)
{
	int	i;
	int	j;

	j = -1;
	i = ft_strlen(dest);
	if (dest[0] != '\0')
	{
		dest[i] = '/';
		while (src[++j])
			dest[++i] = src[j];
	}
	else
	{
		while (src[++j])
			dest[i++] = src[j];
	}
	dest[++i] = '\0';
	return (dest);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

void	ft_put_str_fd(int fd, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

char **copy_string_array(char **original)
{
	int		i;
	int		count;
	char	**copy;

	count = 0;
	i = -1;
	while (original[count])
		count++;
	copy = (char **)malloc(sizeof(char *) * (count + 1));
	if (!copy)
		return (NULL);
	while (++i < count)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
	}
	copy[count] = NULL;
	return (copy);
}

void	exec_command(char **arg_tab, char *cpy, char **envp)
{
	int		i;
	char	**path;
	char	*final_path;

	execve(arg_tab[0], arg_tab, envp);
	path = ft_split(cpy, ':');
	i = -1;
	final_path = malloc(1);
	while (path[++i])
	{
		final_path = ft_realloc(final_path, ft_strlen
				(path[i]) + ft_strlen(arg_tab[0]) + 2);
		ft_strcat_path(final_path, path[i]);
		ft_strcat_path(final_path, arg_tab[0]);
		if (access(final_path, X_OK) == 0)
		{
			free_tab(path);
			execve(final_path, arg_tab, envp);
		}
	}
	free_tab(path);
	free(final_path);
	perror("");
}

void execute_heredoc(const char *end_str, int fd_write)
{
	char *line;
	char *final_line = malloc(1);
	final_line[0] = '\0';

	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, end_str) == 0)
		{
			free(line);
			break;
		}
		final_line = realloc(final_line, ft_strlen(final_line) + ft_strlen(line) + 2);
		strcat(final_line, line);
		strcat(final_line, "\n");
		free(line);
	}
	ft_put_str_fd(fd_write, final_line);
	free(final_line);
}

void	do_built_in_command(char **args, t_env *env_cpy)
{
	if (!ft_strcmp(args[0], "echo"))
		ft_echo(args);
	if (!ft_strcmp(args[0], "cd"))
		ft_cd(args);
	if (!ft_strcmp(args[0], "pwd"))
		ft_pwd();
	if (!ft_strcmp(args[0], "export"))
		ft_export(args, env_cpy);
	if (!ft_strcmp(args[0], "unset"))
		ft_unset(args, env_cpy);
	if (!ft_strcmp(args[0], "env"))
		ft_env(env_cpy, 0);
	//exit(EXIT_SUCCESS);
}

struct soken *do_command(struct soken *lst, int rd_fd, char *path, t_env *env)
{
	char **args;
	int arg_num = 1;
	int fd_tab[2];
	pid_t pid;
	int stdout_backup = dup(STDOUT_FILENO);
	int stdin_backup = dup(STDIN_FILENO);
	int	fd;
	int	piped = 0;
	int	redirect = 0;
	int heredoc = 0;
	int	builtin = 0;

	args = malloc(sizeof(char *));
	if (lst != NULL && lst->type == 8)
	{
		fd = open(lst->next->value, O_RDONLY);
		lst = lst->next;
		lst = lst->next;
		rd_fd = fd;
		redirect = 1;
	}
	if (lst->type == 6)
		builtin = 1;
	args[0] = ft_strdup(lst->value);
	lst = lst->next;
	while (lst != NULL && (lst->type == 0 || lst->type == 3 || lst->type == 4))
	{
		if (lst->type == 3 || lst->type == 4)
		{
			arg_num++;
			char **temp = realloc(args, arg_num * sizeof(char *));
			if (!temp)
			{
				perror("realloc");
				free(args);
				exit(EXIT_FAILURE);
			}
			args = temp;
			args[arg_num - 1] = ft_strdup(lst->value); // Utilisation de strdup pour dupliquer la valeur
			lst = lst->next;
		}
		else if (lst->type == 0)
			lst = lst->next;
	}

	// Ajouter NULL à la fin du tableau d'arguments pour execv
	char **temp = realloc(args, (arg_num + 1) * sizeof(char *));
	if (!temp)
	{
		perror("realloc");
		free(args);
		exit(EXIT_FAILURE);
	}
	args = temp;
	args[arg_num] = NULL;
	while (lst != NULL && (lst->type >= 7 && lst->type <= 11))
	{
		if (lst != NULL && lst->type == 7)
		{
			if (lst->next->type == 7)
			{
				lst = NULL;
				break ;
			}
			if (!redirect)
			{
				pipe(fd_tab);
				piped = 1;
			}
			lst = lst->next;
		}
		if (lst != NULL && lst->type == 8)
		{
			fd = open(lst->next->value, O_RDONLY);
			lst = lst->next;
			lst = lst->next;
			rd_fd = fd;
			redirect = 1;
		}
		if (lst != NULL && lst-> type == 9)
		{
			fd = open(lst->next->value, O_WRONLY | O_CREAT | O_TRUNC, 0666);
			dup2(fd, STDOUT_FILENO); // Redirection de stdout vers le fichier
			lst = lst->next;
			lst = lst->next;
			redirect = 1;
		}
		if (lst != NULL && lst->type == 10)
		{
			fd = open(lst->next->value, O_WRONLY | O_CREAT | O_APPEND, 0666);
			dup2(fd, STDOUT_FILENO); // Redirection de stdout vers le fichier
			lst = lst->next;
			lst = lst->next;
			redirect = 1;
		}
		if (lst != NULL && lst->type == 11)
		{
			pipe(fd_tab);
			execute_heredoc(lst->next->value, fd_tab[1]);
			close(fd_tab[1]); // Fermer l'extrémité d'écriture après avoir écrit les données
			dup2(fd_tab[0], STDIN_FILENO); // Rediriger stdin vers l'extrémité de lecture du pipe
			close(fd_tab[0]); // Fermer l'extrémité de lecture après la redirection
			lst = lst->next;
			lst = lst->next;
			heredoc = 1;
		}
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{ // Processus enfant
		if (builtin)
			exit(EXIT_SUCCESS);
		if (piped == 1)
		{
			close(fd_tab[0]); // Fermer l'extrémité de lecture du pipe dans le processus enfant
			dup2(fd_tab[1], STDOUT_FILENO); // Rediriger stdout vers l'extrémité d'écriture du pipe
			close(fd_tab[1]);
			piped = 0;
		}
		if (!heredoc)
			dup2(rd_fd, STDIN_FILENO); // Redirection de stdin si nécessaire
		exec_command(args, path, env->env_cpy);
		dup2(stdout_backup, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (builtin)
		{
			pid = fork();
			if (pid == 0)
			{
				if (piped == 1)
				{
					close(fd_tab[0]); // Fermer l'extrémité de lecture du pipe dans le processus enfant
					dup2(fd_tab[1], STDOUT_FILENO); // Rediriger stdout vers l'extrémité d'écriture du pipe
					close(fd_tab[1]);
					piped = 0;
				if (!heredoc)
					dup2(rd_fd, STDIN_FILENO); // Redirection de stdin si nécessaire
				if ((!ft_strcmp(args[0], "export") && !args[1]) || ft_strcmp(args[0], "export"))
					do_built_in_command(args, env);
				}
				exit(EXIT_SUCCESS);
			}
			if (!piped || (!ft_strcmp(args[0], "export") && args[1]))
					do_built_in_command(args, env);
		}
		if (redirect || heredoc)
		{
			dup2(stdout_backup, STDOUT_FILENO);
			dup2(stdin_backup, STDIN_FILENO);
			close(fd);
			redirect = 0;
			heredoc = 0;
		}
		if (piped == 1)
		{
			close(fd_tab[1]); // Fermer l'extrémité d'écriture du pipe dans le processus parent
			if (lst->type == 6 || lst->type == 5)
			{
				lst = do_command(lst, fd_tab[0], path, env);
				piped = 0;
				close(fd_tab[0]);
			}
		}
		waitpid(pid, NULL, 0); // Attendre la fin du processus enfant
	}
	// Libérer la mémoire
	for (int i = 0; i < arg_num; i++) {
		free(args[i]);
	}
	free(args);
	return (lst);
}

void	check_redirect(t_oken **token_list)
{
	t_oken	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (tmp->value[0] == '<'
			&& !(!tmp->value[1] || (tmp->value[1] == '<' && !tmp->value[2])))
			tmp->type = T_ERROR;
		if (tmp->value[0] == '>'
			&& !(!tmp->value[1] || (tmp->value[1] == '>' && !tmp->value[2])))
			tmp->type = T_ERROR;
		tmp = tmp->next;
	}
}

t_oken	*parsing(char **envp)
{
	t_oken	*tmp;
	t_oken	*t_argv;
	char	*input;

	t_argv = NULL;
	input = readline("➜ MiniFeur$ ");
	if (input && ft_strlen(input) > 0)
	{
		t_argv = tokenize(input, envp);
		add_flags(&t_argv);
		check_redirect(&t_argv);
		join_string(&t_argv);
		add_envp_var(&t_argv, envp);
		if (t_argv->type == T_S_QUOTE
			|| t_argv->type == T_D_QUOTE || t_argv->type == T_SPACE)
		{
			tmp = t_argv->next;
			free(t_argv->value);
			free(t_argv->path);
			free(t_argv);
			t_argv = tmp;
		}
		free(input);
	}
	return (t_argv);
}

int	main(int argc, char **argv, char **envp)
{
	t_oken	*t_argv;
	char	*cpy;
	t_env	env;
	int		i;

	i = -1;
	env.env_cpy = copy_string_array(envp);
	sig_init();
	(void)argc;
	(void)argv;
	while (envp[++i])
	{
		if (ft_strncmp(env.env_cpy[i], "PATH=", 5) == 0)
		{
			cpy = envp[i] + 5;
			break ;
		}
	}
	printf("\033c");
	printf("\033]0;MiniFeur\a");
	while (1)
	{
		t_argv = parsing(env.env_cpy);
		if (!t_argv)
			break ;
		if (!ft_strcmp(t_argv->value, "exit"))
			break ;
		while (t_argv)
		{
			if (t_argv->type == 5 || t_argv->type == 6 || t_argv->type == 8 || t_argv->type == 4)
				t_argv = do_command(t_argv, STDIN_FILENO, cpy, &env);
			else if (t_argv->type == 3)
			{
				printf("minifeur: %s: command not found\n", t_argv->value);
				break ;
			}
		}
	}
	return (0);
}
