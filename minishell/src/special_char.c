/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:54:54 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/30 19:46:28 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

extern int	g_status;

t_oken	*if_in_do(t_command *c, t_oken *lst)
{
	if (!lst->next || lst->next->type < 3 || lst->next->type > 6)
	{
		c->error = 1;
		g_status = 2;
		printf("minishell: synthaxe error\n");
		while (lst)
			lst = lst->next;
		return (lst);
	}
	c->fd = open(lst->next->value, O_RDONLY);
	if (c->fd == -1)
	{
		g_status = 1;
		perror("");
		c->error = 1;
		close(c->fd);
		lst = NULL;
		return (lst);
	}
	lst = lst->next->next;
	c->rd_fd = c->fd;
	c->redirect = 1;
	return (lst);
}

t_oken	*if_pipe_do(t_command *c, t_oken *lst)
{
	if (!lst->next)
	{
		c->error = 1;
		lst = lst->next;
		printf("minishell: synthaxe error\n");
		return (lst);
	}
	if (lst != NULL && lst->type == 7)
	{
		if (lst->next->type == 7)
			return (NULL);
		pipe(c->fd_tab);
		c->piped = 1;
		lst = lst->next;
	}
	return (lst);
}

t_oken	*if_out_do(t_command *c, t_oken *lst)
{
	if (!lst->next || lst->next->type < 3 || lst->next->type > 6)
	{
		c->error = 1;
		g_status = 2;
		printf("minishell: synthaxe error\n");
		while (lst)
			lst = lst->next;
		return (lst);
	}
	c->fd = open(lst->next->value, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if ((!lst->next->next && !c->command))
	{
		lst = lst->next;
		lst = lst->next;
		close(c->fd);
		c->error = 1;
		return (lst);
	}
	dup2(c->fd, STDOUT_FILENO);
	lst = lst->next;
	lst = lst->next;
	c->redirect = 1;
	c->out = 1;
	return (lst);
}

t_oken	*if_append_do(t_command *c, t_oken *lst)
{
	if (!lst->next || lst->next->type < 3 || lst->next->type > 6)
	{
		c->error = 1;
		g_status = 2;
		printf("minishell: synthaxe error\n");
		while (lst)
			lst = lst->next;
		return (lst);
	}
	c->fd = open(lst->next->value, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if ((!lst->next->next && !c->command))
	{
		close(c->fd);
		c->error = 1;
		return (lst);
	}
	dup2(c->fd, STDOUT_FILENO);
	lst = lst->next;
	lst = lst->next;
	c->redirect = 1;
	c->out = 1;
	return (lst);
}

t_oken	*if_heredoc_do(t_command *c, t_oken *lst)
{
	if (!lst->next || lst->next->type < 3 || lst->next->type > 6)
	{
		c->error = 1;
		g_status = 2;
		printf("minishell: synthaxe error\n");
		lst = NULL;
		return (lst);
	}
	if (lst != NULL && lst->type == 11)
	{
		pipe(c->fd_tab);
		execute_heredoc(lst->next->value, c->fd_tab[1]);
		close(c->fd_tab[1]);
		if (!lst->next->next && !c->command)
		{
			close(c->fd_tab[0]);
			c->error = 1;
			return (lst);
		}
		dup2(c->fd_tab[0], STDIN_FILENO);
		close(c->fd_tab[0]);
		lst = lst->next->next;
		c->heredoc = 1;
	}
	return (lst);
}
