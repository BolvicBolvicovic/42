/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:16:40 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/20 15:16:55 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	notin_c(int grid[4][4], int col, int num);
int	notin_r(int grid[4][4], int row, int num);
int	clu_rl(int grid[4][4], int clu[4][4], int row);
int	clu_rr(int grid[4][4], int clu[4][4], int row);
int	clu_cu(int grid[4][4], int clu[4][4], int col);
int	clu_cd(int grid[4][4], int clu[4][4], int col);

int	solved2(int grid[4][4], int clu[4][4], int *row, int *col)
{
	if (*row == 4)
	{
		*row = 0;
		if (clu_cu(grid, clu, *col) && clu_cd(grid, clu, *col))
		{
			*col = *col + 1;
			if (*col == 4)
				return (1);
		}
		else
			return (0);
	}
	return (2);
}

int	solved(int g[4][4], int cl[4][4], int r, int c)
{
	int	num;
	int	boool;

	boool = solved2(g, cl, &r, &c);
	if (boool != 2)
		return (boool);
	num = 0;
	while (++num <= 4)
	{
		if (notin_c(g, c, num) && notin_r(g, r, num))
		{
			g[r][c] = num;
			if (c == 3 && (!clu_rl(g, cl, r) || !clu_rr(g, cl, r)))
			{
				g[r][c] = 0;
				return (0);
			}
			if (solved(g, cl, r + 1, c))
				return (1);
			g[r][c] = 0;
		}
	}
	return (0);
}
