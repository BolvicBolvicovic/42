/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deck <deck@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:57:57 by acasamit          #+#    #+#             */
/*   Updated: 2024/02/06 20:14:24 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

extern int	g_status;

t_oken	*handle_special_char(t_command *c, t_oken *lst)
{
	while (lst != NULL && (lst->type >= 7 && lst->type <= 11))
	{
		if (lst && lst->type == 7)
			lst = if_pipe_do(c, lst);
		if (c->piped)
			break ;
		if (lst != NULL && lst->type == 8)
			lst = if_in_do(c, lst);
		if (lst != NULL && lst->type == 9)
			lst = if_out_do(c, lst);
		if (lst != NULL && lst->type == 10)
			lst = if_append_do(c, lst);
		if (lst != NULL && lst->type == 11)
			lst = if_heredoc_do(c, lst);
	}
	return (lst);
}

void	child_process_do(t_command *c, char *path, t_env *env)
{
	free_child_process(c, env);
	if (c->piped == 1)
	{
		close(c->fd_tab[0]);
		if (!c->out)
			dup2(c->fd_tab[1], STDOUT_FILENO);
		close(c->fd_tab[1]);
		c->piped = 0;
	}
	if (!c->heredoc)
		dup2(c->rd_fd, STDIN_FILENO);
	free_tokens(c->lst_cpy);
	exec_command(c->args, path, env->env_cpy, c->is_dir);
	dup2(c->stdout_backup, STDOUT_FILENO);
	free_tab(env->env_cpy);
	free_tab(c->args);
	exit(EXIT_FAILURE);
}

void	if_built_in_do(t_command *c, t_env *env)
{
	if (c->builtin && !c->error)
	{
		c->pid = fork();
		if (c->pid == 0)
		{
			if (c->piped == 1)
			{
				close(c->fd_tab[0]);
				if (!c->out)
					dup2(c->fd_tab[1], STDOUT_FILENO);
				close(c->fd_tab[1]);
				c->piped = 0;
				if (!c->heredoc)
					dup2(c->rd_fd, STDIN_FILENO);
				if ((!ft_strcmp(c->args[0], "export") && !c->args[1])
					|| ft_strcmp(c->args[0], "export"))
					do_built_in_command(c->args, env, c);
			}
			free_built_in(c, env);
			exit(EXIT_SUCCESS);
		}
		if (!c->piped || (!ft_strcmp(c->args[0], "export") && c->args[1]))
			do_built_in_command(c->args, env, c);
	}
}

t_oken	*parent_process_do(t_command *c, t_oken *lst, char *path, t_env *env)
{
	if_built_in_do(c, env);
	if (c->heredoc || c->redirect)
	{
		dup2(c->stdin_backup, STDIN_FILENO);
		dup2(c->stdout_backup, STDOUT_FILENO);
		if ((!c->heredoc || (c->heredoc && c->redirect))
			&& c->fd != -1)
			close(c->fd);
		c->redirect = 0;
		c->heredoc = 0;
		c->out = 0;
	}
	close(c->stdin_backup);
	close(c->stdout_backup);
	if (c->piped == 1)
	{
		close(c->fd_tab[1]);
		if (lst)
			do_pipe(c, lst, path, env);
	}
	waitpid(c->pid, &g_status, 0);
	g_status = WEXITSTATUS(g_status);
	return (lst);
}

t_oken	*do_command(t_oken *lst, int rd_fd, char *path, t_env *env)
{
	t_command	c;

	is_exec(1);
	c = var_init(rd_fd, lst);
	lst = fill_arg_tab(&c, lst);
	if (!c.error)
		lst = handle_special_char(&c, lst);
	if (!c.error)
		c.pid = fork();
	if (!c.error && !c.pid)
		child_process_do(&c, path, env);
	else
		lst = parent_process_do(&c, lst, path, env);
	free_tab(c.args);
	is_exec(0);
	free_tokens(c.lst_cpy);
	c.lst_cpy = NULL;
	return (lst);
}
