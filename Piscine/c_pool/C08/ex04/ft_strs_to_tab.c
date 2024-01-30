/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:43:11 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/23 16:02:30 by vcornill         ###   ########.fr       */
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

char	*ft_strdup(char *src, int size)
{
	int		i;
	char	*tampon;

	tampon = malloc(size + 1);
	if (!tampon)
		return (NULL);
	i = -1;
	while (src[++i])
		tampon[i] = src[i];
	tampon[i] = '\0';
	return (tampon);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			i;

	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(stock[i].str, stock[i].size);
	}
	stock[i].str = 0; 
	return (stock);
}
