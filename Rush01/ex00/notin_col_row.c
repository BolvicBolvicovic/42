/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notin_col_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:21:46 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/20 16:23:03 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	notin_c(int grid[4][4], int col, int num)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (grid[i][col] == num)
			return (0);
	return (1);
}

int	notin_r(int grid[4][4], int row, int num)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (grid[row][i] == num)
			return (0);
	return (1);
}
