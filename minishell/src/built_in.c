/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:40:48 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/25 10:33:56 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_equal(const char *entry)
{
	int	i;

	i = 0;
	while (entry[i])
	{
		if (entry[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_cd(char **arg_tab)
{
	if (!arg_tab[1])
		chdir(getenv("HOME"));
	else if (chdir(arg_tab[1]) == -1)
		perror("");
}

void	ft_pwd(void)
{
	char	*path;

	path = malloc(PATH_MAX + 1);
	path = getcwd(path, PATH_MAX);
	printf("%s\n", path);
	free(path);
}

void	ft_env(t_env *envp, int is_export)
{
	int	i;

	i = -1;
	while (envp->env_cpy[++i])
	{
		if (!is_equal(envp->env_cpy[i]) && !is_export)
			continue ;
		if (is_export)
			printf("declare -x ");
		if (is_export && is_equal(envp->env_cpy[i])
			&& envp->env_cpy[i][strcspn(envp->env_cpy[i], "=") + 2] == '\0')
			printf("%s\"\"\n", envp->env_cpy[i]);
		else
			printf("%s\n", envp->env_cpy[i]);
	}
}

size_t	var_exist(char *full_name, char **envp)
{
	size_t	j;
	char	*var_name;
	size_t	i;

	i = -1;
	var_name = malloc(strcspn(full_name, "=") + 1);
	while (++i != strcspn(full_name, "="))
		var_name[i] = full_name[i];
	var_name[i] = '\0';
	j = -1;
	while (envp[++j])
	{
		if ((!ft_strncmp(var_name, envp[j], ft_strlen(var_name)))
			&& envp[j][ft_strlen(var_name)] == '=')
		{
			return (j);
		}
	}
	return (-1);
}
