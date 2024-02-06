/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deck <deck@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:41 by acasamit          #+#    #+#             */
/*   Updated: 2024/02/03 15:37:54 by deck             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	**ft_export(char **arg_tab, t_env *env)
{
	t_export	e;

	e.i = 0;
	e.j = -1;
	e.empty = 1;
	e.equal = 0;
	e.completed = 0;
	if (!arg_tab[1])
		return (ft_export_print(env->env_cpy));
	while (arg_tab[++e.i])
	{
		e.k = 0;
		while (arg_tab[e.i][++e.j])
		{
			if (arg_tab[e.i][e.j] == '=')
			{
				e.equal = 1;
				if (arg_tab[e.i][e.j + 1] != '\0')
					e.empty = 0;
			}
		}
		e = ft_export_main(e, env, arg_tab);
	}
	return (env->env_cpy);
}

void	echo_utils(char **arg_tab)
{
	int	j;

	j = 0;
	while (arg_tab[++j] && arg_tab[j + 1] != NULL)
	{
		printf("%s", arg_tab[j]);
		printf(" ");
	}
	if (arg_tab[j] && arg_tab[j + 1] == NULL)
		printf("%s\n", arg_tab[j]);
	return ;
}

void	ft_echo(char **arg_tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!arg_tab[1])
	{
		printf("\n");
		return ;
	}
	if (arg_tab[1][0] == '-' && arg_tab[1][1] == 'n')
	{
		while (arg_tab[1][++i])
		{
			if (arg_tab[1][i] != 'n')
				return (echo_utils(arg_tab));
		}
	}
	else
		return (echo_utils(arg_tab));
	j = 1;
	while (arg_tab[++j] && arg_tab[j + 1] != NULL)
		printf("%s ", arg_tab[j]);
	if (arg_tab[j] && arg_tab[j + 1] == NULL)
		printf("%s", arg_tab[j]);
}

char	*ft_realloc_s(char *str, int size)
{
	int		i;
	char	*new_str;

	i = -1;
	new_str = malloc(size);
	while (str[++i])
		new_str[i] = str[i];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
