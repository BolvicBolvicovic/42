/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:49:41 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/30 18:35:24 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_strcat_path(char *dest, char *src)
{
	int	i;
	int	j;

	j = -1;
	i = ft_strlen(dest);
	if (dest[0] != '\0')
	{
		dest[i] = '/';
		while (src[++j])
			dest[++i] = src[j];
	}
	else
	{
		while (src[++j])
			dest[i++] = src[j];
	}
	dest[++i] = '\0';
	return (dest);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

void	ft_put_str_fd(int fd, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

char	**copy_string_array(char **original)
{
	int		i;
	int		count;
	char	**copy;

	count = 0;
	i = -1;
	while (original[count])
		count++;
	copy = (char **)malloc(sizeof(char *) * (count + 1));
	if (!copy)
		return (NULL);
	while (++i < count)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
	}
	copy[count] = NULL;
	return (copy);
}

void	exec_command(char **arg_tab, char *cpy, char **envp, int is_dir)
{
	int		i;
	char	**path;
	char	*final_path;

	execve(arg_tab[0], arg_tab, envp);
	if (!is_dir)
	{
		path = ft_split(cpy, ':');
		i = -1;
		final_path = malloc(1);
		while (path[++i])
		{
			final_path = ft_realloc(final_path, ft_strlen
					(path[i]) + ft_strlen(arg_tab[0]) + 2);
			ft_strcat_path(final_path, path[i]);
			ft_strcat_path(final_path, arg_tab[0]);
			if (access(final_path, X_OK) == 0)
			{
				free_tab(path);
				execve(final_path, arg_tab, envp);
			}
		}
		free_exec_command(path, final_path);
	}
	perror("");
}
