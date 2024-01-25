/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:54:54 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/20 17:55:04 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_oken	*if_in_do(t_command *c, t_oken *lst)
{
	if (lst != NULL && lst->type == 8)
	{
		c->fd = open(lst->next->value, O_RDONLY);
		if (c->fd == -1 || (!lst->next->next
				&& !c->command))
		{
			if (c->fd == -1)
				perror("");
			c->error = 1;
			close(c->fd);
			return (lst);
		}
		lst = lst->next;
		lst = lst->next;
		c->rd_fd = c->fd;
		c->redirect = 1;
	}
	return (lst);
}

t_oken	*if_pipe_do(t_command *c, t_oken *lst)
{
	if (lst != NULL && lst->type == 7)
	{
		if (lst->next->type == 7)
			return (NULL);
		if (!c->redirect)
		{
			pipe(c->fd_tab);
			c->piped = 1;
		}
		lst = lst->next;
	}
	return (lst);
}

t_oken	*if_out_do(t_command *c, t_oken *lst)
{
	if (lst != NULL && lst->type == 9)
	{
		c->fd = open(lst->next->value, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if ((!lst->next->next && !c->command) || c->fd == -1)
		{
			if (c->fd == -1)
				perror("");
			close(c->fd);
			c->error = 1;
			return (lst);
		}
		dup2(c->fd, STDOUT_FILENO);
		lst = lst->next;
		lst = lst->next;
		c->redirect = 1;
	}
	return (lst);
}

t_oken	*if_append_do(t_command *c, t_oken *lst)
{
	if (lst != NULL && lst->type == 10)
	{
		c->fd = open(lst->next->value, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if ((!lst->next->next && !c->command) || c->fd == -1)
		{
			if (c->fd == -1)
				perror("");
			close(c->fd);
			c->error = 1;
			return (lst);
		}
		dup2(c->fd, STDOUT_FILENO);
		lst = lst->next;
		lst = lst->next;
		c->redirect = 1;
	}
	return (lst);
}

t_oken	*if_heredoc_do(t_command *c, t_oken *lst)
{
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
		lst = lst->next;
		lst = lst->next;
		c->heredoc = 1;
	}
	return (lst);
}
