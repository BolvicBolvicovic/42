/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:27:40 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/27 12:29:57 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ourlib.h"

int	is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	modthree(char *str)
{
	int	mod;

	if (ft_strlen(str) % 3 > 0)
		mod = 1;
	else
		mod = 0;
	return (mod);
}
