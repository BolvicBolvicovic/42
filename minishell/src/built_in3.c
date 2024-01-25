/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:08:25 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/23 15:24:32 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_unset_utils(int i, int j, char **arg_tab, t_env *envp)
{
	while (envp->env_cpy[++j])
	{
		if (!ft_strncmp(arg_tab[i], envp->env_cpy[j], ft_strlen
				(arg_tab[i])) && envp->env_cpy[j][ft_strlen
			(arg_tab[i])] == '=')
		{
			free(envp->env_cpy[j]);
			while (envp->env_cpy[j])
			{
				envp->env_cpy[j] = envp->env_cpy[j + 1];
				j++;
			}
			free(envp->env_cpy[j]);
			break ;
		}
	}
}

void	ft_unset(char **arg_tab, t_env *envp)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (arg_tab[1] == NULL)
	{
		printf("unset: not enough arguments\n");
		return ;
	}
	while (arg_tab[++i])
	{
		while (arg_tab[i][++j])
		{
			if (arg_tab[i][j] == '=' || arg_tab[i][j] == ':')
			{
				printf("unset: `%s': not a valid identifier\n", arg_tab[i]);
				return ;
			}
		}
		j = -1;
		ft_unset_utils(i, j, arg_tab, envp);
	}
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_realloc_tab(char **tab, int size)
{
	char	**new_tab;
	int		i;

	i = -1;
	new_tab = malloc((size + 1) * sizeof(char *));
	while (tab[++i])
		new_tab[i] = ft_strdup(tab[i]);
	new_tab[size - 1] = NULL;
	new_tab[size] = NULL;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (new_tab);
}
