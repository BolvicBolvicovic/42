/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:23:48 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 16:41:10 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int n)
{
	int		test;
	int		i;
	char	*nb;

	i = 1;
	if (n < 0)
		i++;
	test = n;
	while (test > 9)
	{
		test /= 10;
		i++;
	}
	nb = malloc(i + 1);
	if (!nb)
		return (NULL);
	nb[i] = '\0'; 
	while (n)
	{
		nb[--i] = n%10 + '0';
		n /= 10;
	}
	return (nb);
}
