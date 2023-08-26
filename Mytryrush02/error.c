/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:13:57 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/26 12:47:31 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mixlib.h"

int	checknum(char *num)
{
	int	i;

	i = -1;
	while (num[++i])
	{
		if (num[i] < '0' || num[i] > '9')
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	if (i > 12 || !num)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	error(int argc, char **argv)
{
	if (argc == 2)
		return (checknum(argv[1]);
	else
		return (checknum(argv[2]);
}
