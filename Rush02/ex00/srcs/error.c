/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:07:26 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/27 12:25:40 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ourlib.h"

void	puterror(char *err)
{
	while (*err != 0)
		write(2, err++, 1);
}

int	error(char *str)
{
	if (!is_number(str))
	{
		puterror("Error\n");
		return (1);
	}
	if (ft_strlen(str) > 12)
	{
		puterror("Dict Error\n");
		return (1);
	}
	return (0);
}
