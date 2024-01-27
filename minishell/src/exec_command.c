/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:52:51 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/26 22:48:19 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	execute_heredoc(const char *end_str, int fd_write)
{
	char	*line;
	char	*final_line;

	final_line = malloc(1);
	final_line[0] = '\0';
	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, end_str) == 0)
		{
			free(line);
			break ;
		}
		final_line = realloc(final_line,
				ft_strlen(final_line) + ft_strlen(line) + 2);
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
}

t_command	var_init(int rd)
{
	t_command	c;

	c.arg_num = 1;
	c.stdout_backup = dup(STDOUT_FILENO);
	c.stdin_backup = dup(STDIN_FILENO);
	c.args = malloc(sizeof(char *));
	c.args[0] = NULL;
	c.piped = 0;
	c.redirect = 0;
	c.heredoc = 0;
	c.builtin = 0;
	c.rd_fd = rd;
	c.is_dir = 0;
	c.error = 0;
	c.command = 0;
	c.out = 0;
	return (c);
}

t_oken	*fill_arg_tab_utils(t_command *c, t_oken *lst)
{
	while (lst != NULL && (lst->type == 0 || lst->type == 3 || lst->type == 4))
	{
		if (lst->type == 3 || lst->type == 4)
		{
			c->arg_num++;
			c->temp = realloc(c->args, c->arg_num * sizeof(char *));
			if (!c->temp)
			{
				perror("realloc");
				free(c->args);
				exit(EXIT_FAILURE);
			}
			c->args = c->temp;
			c->args[c->arg_num - 1] = ft_strdup(lst->value);
			lst = lst->next;
		}
		else if (lst->type == 0)
			lst = lst->next;
	}
	return (lst);
}

t_oken	*fill_arg_tab(t_command *c, t_oken *lst)
{
	lst = handle_special_char(c, lst);
	if (c->heredoc || c->out || c->error || !lst)
		return (lst);
	c->command = (lst->type == 6 || lst->type == 5);
	c->builtin = (lst->type == 6);
	c->args[0] = ft_strdup(lst->value);
	c->is_dir = (lst->type == 4);
	lst = lst->next;
	lst = fill_arg_tab_utils(c, lst);
	c->temp = realloc(c->args, (c->arg_num + 1) * sizeof(char *));
	if (!c->temp)
	{
		perror("realloc");
		free(c->args);
		exit(EXIT_FAILURE);
	}
	c->args = c->temp;
	c->args[c->arg_num] = NULL;
	return (lst);
}
