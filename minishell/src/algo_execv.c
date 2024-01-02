/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_execv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:08:06 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/02 19:05:11 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	*ft_realloc(char *ptr, size_t size)
{
	char	*str;
	int		i;
	
	i = -1;
	str = malloc(size);
	free(ptr);
	str[0] = '\0';
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

void	exec_command(char **arg_tab, char *cpy)
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
				(path[i]) + ft_strlen(arg_tab[0]) + 2);
		ft_strcat(final_path, path[i]);
		ft_strcat(final_path, arg_tab[0]);
		if (access(final_path, X_OK) == 0)
		{
			free_tab(path);
			execv(final_path, arg_tab);
		}
	}
	free_tab(path);
	free(final_path);
	perror("");
}
