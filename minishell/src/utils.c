/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:36:52 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/12 15:18:18 by vcornill         ###   ########.fr       */
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
		if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
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

int	only_space(token *node)
{
	int	i;

	i = -1;
	while (node->value[++i])
		if (node->value[i] != ' ' && !(node->value[i] >= '\t' && node->value[i] <= '\r'))
			return (0);
	node->type = T_SPACE;
	return (1);
}
