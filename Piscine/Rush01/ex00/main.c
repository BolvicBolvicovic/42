/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:12:51 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/20 15:15:43 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	printgrid(int grid[4][4]);
void	tosolve(int clues[4][4]);
int		solved(int grid[4][4], int clues[4][4], int row, int col);
int		notgoodstr(char *argv);

int	main(int argc, char **argv)
{
	int	clues[4][4];
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (argc != 2 || notgoodstr(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (argv[1][++i])
	{
		if (argv[1][i] != ' ')
		{
			clues[j / 4][j % 4] = argv[1][i] - '0';
			j++;
		}
	}
	tosolve(clues);
	return (0);
}

void	tosolve(int clues[4][4])
{
	int	i;
	int	grid[4][4];

	i = -1;
	while (++i < 16)
		grid[i / 4][i % 4] = 0;
	if (solved(grid, clues, 0, 0))
		printgrid(grid);
	else
		write(1, "Error\n", 6);
}
