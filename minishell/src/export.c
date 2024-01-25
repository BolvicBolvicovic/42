/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:21 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/18 19:03:33 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	**ft_export_print(char **env_cpy)
{
	int	i;

	i = -1;
	while (env_cpy[++i])
		printf("declare -x %s\n", env_cpy[i]);
	return (env_cpy);
}

int	ft_export_utils1(t_env *env, char **arg_tab, int j, int i)
{
	free(env->env_cpy[j]);
	env->env_cpy[j] = malloc(ft_strlen(arg_tab[i]) + 2);
	env->env_cpy[j][0] = '\0';
	ft_strcat(env->env_cpy[j], arg_tab[i]);
	ft_strcat(env->env_cpy[j], "\"\"");
	return (1);
}

int	ft_export_utils2(t_env *env, char **arg_tab, int i, int j)
{
	free(env->env_cpy[j]);
	env->env_cpy[j] = malloc(ft_strlen(arg_tab[i]) + 2);
	env->env_cpy[j][0] = '\0';
	ft_strcat(env->env_cpy[j], arg_tab[i]);
	return (1);
}

t_export	ft_export_master(t_export e, char **arg_tab, t_env *env)
{
	if (!e.empty && !e.completed)
	{
		while (env->env_cpy[e.k])
			e.k++;
		env->env_cpy = ft_realloc_tab(env->env_cpy, e.k + 1);
		env->env_cpy[e.k] = ft_strdup(arg_tab[e.i]);
	}
	else if (e.empty && !e.completed)
	{
		while (env->env_cpy[e.k])
			e.k++;
		env->env_cpy = ft_realloc_tab(env->env_cpy, e.k + 1);
		env->env_cpy[e.k] = malloc(ft_strlen(arg_tab[e.i]) + 2);
		env->env_cpy[e.k][0] = '\0';
		ft_strcat(env->env_cpy[e.k], arg_tab[e.i]);
		ft_strcat(env->env_cpy[e.k], "\"\"");
		env->env_cpy[e.k + 1] = NULL;
	}
	return (e);
}

t_export	ft_export_main(t_export e, t_env *env, char **arg_tab)
{
	if (!e.equal)
	{
		arg_tab[e.i] = realloc(arg_tab[e.i], ft_strlen(arg_tab[e.i]) + 2);
		ft_strcat(arg_tab[e.i], "=");
	}
	e.j = 0;
	while (env->env_cpy[++e.j])
	{
		while (arg_tab[e.i][e.k] != '=')
			e.k++;
		if (!ft_strncmp(arg_tab[e.i], env->env_cpy[e.j], e.k + 1))
		{
			if (e.empty && e.equal)
				e.completed = ft_export_utils1(env, arg_tab, e.j, e.i);
			else
				e.completed = ft_export_utils2(env, arg_tab, e.i, e.j);
		}
	}
	e.k = 0;
	e = ft_export_master(e, arg_tab, env);
	e.completed = 0;
	e.empty = 1;
	e.equal = 0;
	e.j = -1;
	return (e);
}
