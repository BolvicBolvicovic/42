/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_execv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:08:06 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/03 15:05:42 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	free_tab(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

int	no_slash(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '/')
			return (0);
	return (1);
}

void	exec_command_flag(token *t_argv, char *cpy)
{
	int		i;
	char	**path;
	char	*final_path;

	path = ft_split(cpy, ':');
	i = -1;
	while (path[++i])
	{
		final_path = ft_calloc(1, 1);
		final_path = ft_realloc(final_path, ft_strlen
				(path[i]) + ft_strlen(t_argv->value) + 10);
		final_path = ft_strcat(final_path, path[i]);
		final_path = ft_strcat(final_path, "/");
		final_path = ft_strcat(final_path, t_argv->value);
		if (access(final_path, X_OK) == 0 && no_slash(t_argv->value))
		{
			t_argv->type = T_CMD_ENVP;
			free(final_path);
			break ;
		}
		free(final_path);
	}
	free_tab(path);
}
