/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envpvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:24:35 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/31 20:31:02 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*get_new_str(char *str, char *value, int *i, char *v)
{
	char	*new_str;
	int		l;
	int		k;
	int		j;

	new_str = ft_calloc(1,
			ft_strlen(str) + ft_strlen(value) - ft_strlen(v) + 1);
	j = -1;
	l = 0;
	while (++j < *i)
		new_str[j] = str[l++];
	k = -1;
	while (value[++k])
		new_str[j++] = value[k];
	l = l + ft_strlen(v);
	while (str[++l])
		new_str[j++] = str[l];
	new_str[j] = '\0';
	free(str);
	free(value);
	*i = *i + k - 1;
	return (new_str);
}

char	*transform_value(char *str, int *i, char **ev, char *v)
{
	int		l;
	int		k;
	int		j;
	char	*value;

	j = -1;
	value = NULL;
	if (ft_strnstr(&str[*i], "$?", 2))
		return (get_new_str(str, v, i, v));
	while (ev[++j])
	{
		if (ft_strnstr(ev[j], v, ft_strlen(v)) && ev[j][ft_strlen(v)] == '=')
		{
			value = ft_calloc(1, ft_strlen(ev[j]) - ft_strlen(v));
			k = 0;
			while (ev[j][k] && ev[j][k] != '=')
				k++;
			l = 0;
			while (ev[j][++k])
				value[l++] = ev[j][k];
			value[l] = '\0';
			break ;
		}
	}
	return (get_new_str(str, value, i, v));
}

int	is_envp(char *str, char **envp, char **viable)
{
	int		i;
	char	*v;

	i = 1;
	while (str[i] && ft_isalnum(str[i]))
		i++;
	v = ft_calloc(1, i);
	i = 1;
	while (str[i] && ft_isalnum(str[i]))
	{
		v[i - 1] = str[i];
		i++;
	}
	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], v, ft_strlen(v))
			&& envp[i][ft_strlen(v)] == '=')
		{
			*viable = v;
			return (1);
		}
	}
	free(v);
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
