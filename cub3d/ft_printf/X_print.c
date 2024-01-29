/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:59:35 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/24 15:29:41 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	xx_print(long long int ap, int *i)
{
	ft_putnbr_base((unsigned int)ap, "0123456789ABCDEF", i);
}