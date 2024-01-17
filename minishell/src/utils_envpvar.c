/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envpvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:24:35 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/17 18:49:56 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*get_new_str(char *str, char *value, int *i, char *var)
{
	char	*new_str;
	int		l;
	int		k;
	int		j;

	new_str = ft_calloc(1,
			ft_strlen(str) + ft_strlen(value) - ft_strlen(var) + 1);
	j = -1;
	l = 0;
	while (++j < *i)
		new_str[j] = str[l++];
	k = -1;
	while (value[++k])
		new_str[j++] = value[k];
	l = l + ft_strlen(var);
	while (str[++l])
		new_str[j++] = str[l];
	new_str[j] = '\0';
	free(str);
	free(value);
	*i = *i + j - 1;
	return (new_str);
}

char	*transform_value(char *str, int *i, char **envp, char *var)
{
	int		l;
	int		k;
	int		j;
	char	*value;

	j = -1;
	value = NULL;
	while (envp[++j])
	{
		if (ft_strnstr(envp[j], var, ft_strlen(var)))
		{
			value = ft_calloc(1, ft_strlen(envp[j]) - ft_strlen(var));
			k = 0;
			while (envp[j][k] && envp[j][k] != '=')
				k++;
			l = 0;
			while (envp[j][++k])
				value[l++] = envp[j][k];
			value[l] = '\0';
			break ;
		}
	}
	return (get_new_str(str, value, i, var));
}

int	is_envp(char *str, char **envp, char **variable)
{
	int		i;
	char	*var;

	i = 1;
	while (str[i] && ft_isalnum(str[i]))
		i++;
	var = ft_calloc(1, i);
	i = 1;
	while (str[i] && ft_isalnum(str[i]))
	{
		var[i - 1] = str[i];
		i++;
	}
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], var, ft_strlen(var))
			&& envp[i][ft_strlen(var)] == '=')
		{
			*variable = var;
			return (1);
		}
	}
	free(var);
	return (0);
}

char	*del_backslash(char *str, int i)
{
	char	*new_str;
	int		j;

	j = -1;
	new_str = ft_calloc(1, ft_strlen(str));
	while (++j < i)
		new_str[j] = str[j];
	while (str[++j])
		new_str[j - 1] = str[j];
	free(str);
	return (new_str);
}
