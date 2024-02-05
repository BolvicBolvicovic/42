/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:01:55 by acasamit          #+#    #+#             */
/*   Updated: 2024/02/01 15:38:03 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	g_status;

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

void	free_token(t_oken **list)
{
	t_oken	*tmp;

	tmp = (*list)->next;
	free((*list)->value);
	free((*list)->path);
	free((*list));
	*list = tmp;
}

t_oken	*parsing(char **envp)
{
	t_oken	*t_argv;
	char	*input;

	t_argv = NULL;
	if (g_status == 0)
		input = readline("\033[0;32m➜\033[0;35m MiniFeur$ \033[1;33m");
	else
		input = readline("\033[0;31m➜\033[0;35m MiniFeur$ \033[1;33m");
	if (input && ft_strlen(input) > 0)
	{
		add_history(input);
		t_argv = tokenize(input, envp);
		add_flags(&t_argv);
		check_redirect(&t_argv);
		join_string(&t_argv, envp);
		if (t_argv->type == T_S_QUOTE
			|| t_argv->type == T_D_QUOTE || t_argv->type == T_SPACE)
			free_token(&t_argv);
		if (!t_argv)
			add_token(&t_argv, 1, 0, "");
		free(input);
	}
	else if (input)
		add_token(&t_argv, 1, 0, "");
	return (t_argv);
}

void	rc(void)
{
	pid_t	pid;

	printf("\033c\033]0;MiniFeur\a\n");
	pid = fork();
	if (pid == 0)
	{
		execve("./.minifeurrc", (char *[]){"./.minifeurrc", NULL}, NULL);
		exit(1);
	}
	waitpid(0, NULL, 0);
	g_status = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_oken	*t_argv;
	char	*cpy;
	t_env	env;
	int		i;

	i = -1;
	t_argv = NULL;
	cpy = NULL;
	env.env_cpy = copy_string_array(envp);
	sig_init();
	(void)argc;
	(void)argv;
	rc();
	while (envp[++i])
	{
		if (ft_strncmp(env.env_cpy[i], "PATH=", 5) == 0)
		{
			cpy = envp[i] + 5;
			break ;
		}
	}
	do_main_loop(&env, t_argv, cpy);
	free_tab(env.env_cpy);
	return (0);
}
