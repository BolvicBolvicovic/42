/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:38:17 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/06 16:49:20 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

extern int	g_status;

t_oken	*error_if_heredoc(t_command *c, t_oken *lst)
{
	c->error = 1;
	g_status = 2;
	printf("minishell: synthaxe error\n");
	lst = NULL;
	return (lst);
}

void	else_statment_cd(char *str, t_env *env)
{
	char	**path;

	path = malloc(sizeof(char *) * 3);
	path[0] = ft_strdup("export");
	path[1] = str;
	path[2] = NULL;
	ft_export(path, env);
	free(path[1]);
	str = NULL;
	str = malloc(PATH_MAX + 1);
	str = getcwd(str, PATH_MAX);
	path[1] = malloc(ft_strlen(str) + 5);
	path[1][0] = '\0';
	ft_strcat(path[1], "PWD=");
	ft_strcat(path[1], str);
	ft_export(path, env);
	free_tab(path);
	free(str);
}
