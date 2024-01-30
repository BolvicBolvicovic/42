/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:33:58 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/30 19:06:05 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	free_exec_command(char **path, char *final_path)
{
	free_tab(path);
	free(final_path);
}

void	free_built_in(t_command *c, t_env *env)
{
	free_tab(c->args);
	free_tab(env->env_cpy);
	free_tokens(c->lst_cpy);
	close(c->stdin_backup);
	close(c->stdout_backup);
	if (c->redirect)
		close(c->fd);
}

void	free_child_process(t_command *c, t_env *env)
{
	if (!c->args[0] || c->builtin)
	{
		if (c->redirect)
			close(c->fd);
		if (c->piped)
		{
			close(c->fd_tab[0]);
			close(c->fd_tab[1]);
		}
		free_tokens(c->lst_cpy);
		free_tab(env->env_cpy);
		free_tab(c->args);
		close(c->stdin_backup);
		close(c->stdout_backup);
		exit(EXIT_SUCCESS);
	}
}

void	do_pipe(t_command *c, t_oken *lst, char *path, t_env *env)
{
	t_oken	*feur;

	free_tab(c->args);
	c->args = NULL;
	feur = copy_token_list(lst);
	free_tokens(c->lst_cpy);
	c->lst_cpy = NULL;
	do_command(feur, c->fd_tab[0], path, env);
	c->piped = 0;
	close(c->fd_tab[0]);
}
