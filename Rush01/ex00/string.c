/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:15:51 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/20 15:16:06 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printgrid(int grid[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putchar(grid[i][j] + '0');
			if (j != 3)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	notgoodstr(char *argv)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (argv[++i])
	{
		if (i % 2 == 0 && (argv[i] < '1' || argv[i] > '4'))
			return (1);
		else if (i % 2 == 1 && argv[i] != ' ')
			return (1);
		if (argv[i] != ' ')
			count++;
	}
	if (count != 16)
		return (1);
	return (0);
}
