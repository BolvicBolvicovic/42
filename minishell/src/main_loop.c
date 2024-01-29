/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:10:38 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/29 12:10:41 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

extern int	g_status;

int	ft_error(t_oken *t_argv)
{
	if (!*t_argv->value)
		return (1);
	if (t_argv->type == 12 || t_argv->type == 7
		|| ((t_argv->type >= 8 && !t_argv->next)
			&& (t_argv->type <= 11 && !t_argv->next)))
	{
		g_status = 2;
		printf("minishell: synthaxe error\n");
		return (1);
	}
	return (0);
}

void	do_main_loop(t_env *env, t_oken *t_argv, char *cpy)
{
	t_oken	*tmp;

	while (1)
	{
		t_argv = parsing(env->env_cpy);
		tmp = t_argv;
		if (!t_argv || !ft_strcmp(t_argv->value, "exit"))
			break ;
		while (t_argv)
		{
			if (ft_error(t_argv))
				break ;
			if (t_argv->type >= 4 && t_argv->type <= 11)
			{
				do_command(t_argv, STDIN_FILENO, cpy, env);
				break ;
			}
			else if (t_argv->type == 3)
			{
				g_status = 127;
				printf("minifeur: %s: command not found\n", t_argv->value);
				break ;
			}
		}
		free_tokens(tmp);
	}
	free_tokens(tmp);
}
