/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:59:53 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/09 12:59:56 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	number;

	if (n < 0)
	{
		number = 'N';
		write(1, &number, 1);
	}
	else
	{
		number = 'P';
		write(1, &number, 1);
	}
}
