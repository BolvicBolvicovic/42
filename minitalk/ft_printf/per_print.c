/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:06:21 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/24 12:15:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	per_print(int *i)
{
	write(1, "%", 1);
	*i = *i + 1;
}
