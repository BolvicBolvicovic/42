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

void	*ft_realloc(char *ptr, size_t size)
{
	char	*str;
	
	str = ft_calloc(size, 0);
	free(ptr);
	return (str);
}

void	free_tab(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

void	exec_command_flag(token *t_argv, char *cpy)
{
	int		i;
	char	**path;
	char	*final_path;

	path = ft_split(cpy, ':');
	i = -1;
	final_path = malloc(1);
	while (path[++i])
	{
		final_path = ft_realloc(final_path, ft_strlen
				(path[i]) + ft_strlen(t_argv->value) + 2);
		ft_strlcat(final_path, path[i], ft_strlen(final_path));
		ft_strlcat(final_path, t_argv->value, ft_strlen(final_path));
		if (access(final_path, X_OK) == 0)
		{
			t_argv->type = T_CMD_ENVP;
			break ;
		}
	}
	free_tab(path);
	free(final_path);
}
