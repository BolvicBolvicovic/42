/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:43:11 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/22 12:49:25 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			j;
	int			i;
	char		*buffer;

	stock = malloc(sizeof(t_stock_str) * ac);
	if (!stock)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		buffer = malloc(stock[i].size + 1);
		if (!buffer)
			return (NULL);
		j = -1;
		while (stock[i].str[++j])
			buffer[j] = stock[i].str[j];
		stock[i].copy = buffer;
	}
	return (stock);
}
