/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_execv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:08:06 by acasamit          #+#    #+#             */
/*   Updated: 2024/02/01 12:34:49 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

/*void	free_tab(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}*/

int	no_slash(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '/')
			return (0);
	return (1);
}

char	*build_final_path(t_oken *t_av, char *path, int i)
{
	char	*final_path;

	final_path = ft_calloc(1, 1);
	final_path = ft_realloc(final_path, ft_strlen
			(path) + ft_strlen(t_av->value) + 10);
	if (!i)
		final_path = ft_strcat(final_path, &path[5]);
	else
		final_path = ft_strcat(final_path, path);
	final_path = ft_strcat(final_path, "/");
	final_path = ft_strcat(final_path, t_av->value);
	return (final_path);
}

void	exec_command_flag(t_oken *t_argv, char *cpy)
{
	int		i;
	char	**path;
	char	*final_path;

	path = ft_split(cpy, ':');
	i = -1;
	while (path && path[++i])
	{
		final_path = build_final_path(t_argv, path[i], i);
		if (!no_slash(t_argv->value))
		{
			t_argv->type = T_DIR_OR_FILE;
			free(final_path);
			break ;
		}
		else if (access(final_path, X_OK) == 0)
		{
			t_argv->type = T_CMD_ENVP;
			free(final_path);
			break ;
		}
		free(final_path);
	}
	free_tab(path);
}
