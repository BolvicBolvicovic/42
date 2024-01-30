/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:48:44 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/17 16:58:29 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tableau;
	int	i;
	int	size;

	size = max - min;
	if (0 >= size)
	{
		*range = NULL;
		return (0);
	}
	tableau = malloc(sizeof(int) * size);
	if (!tableau)
		return (-1);
	i = -1;
	while (min < max)
	{
		tableau[++i] = min;
		min++;
	}
	*range = tableau;
	return (size);
}
