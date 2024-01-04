/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:36:52 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/19 17:03:02 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	*ft_realloc(char *ptr, size_t size)
{
	char	*str;
	
	str = ft_calloc(1, size);
	free(ptr);
	return (str);
}

int	is_str(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (0);
	return (1);
}

int	is_one_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			return (1);
	return (0);
}

int	no_quote(char *str)
{
	while (str++)
		if (*str == '\'' || *str == '\"')
			return (0);
	return (1);
}

int	only_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ' || !(str[i] >= '\r' && str[i] <= '\t'))
			return (0);
	return (1);
}
