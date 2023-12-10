/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:36:15 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/24 14:19:41 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_print(char *ap, int *i)
{
	int	j;

	j = -1;
	if (!ap)
	{
		write(1, "(null)", 6);
		*i = *i + 6;
		return ;
	}
	while (ap[++j])
		c_print(ap[j], i);
}
