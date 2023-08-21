/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:25:45 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/20 16:28:51 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	clu_rl(int grid[4][4], int clu[4][4], int row)
{
	int	i;
	int	view_left;
	int	bigger_left;

	i = -1;
	view_left = 0;
	bigger_left = 0;
	while (++i < 4)
	{
		if (grid[row][i] > bigger_left)
		{
			bigger_left = grid[row][i];
			view_left++;
		}
	}
	if (view_left == clu[2][row])
		return (1);
	return (0);
}

int	clu_rr(int grid[4][4], int clu[4][4], int row)
{
	int	i;
	int	view_right;
	int	bigger_right;

	i = 4;
	view_right = 0;
	bigger_right = 0;
	while (--i >= 0)
	{
		if (grid[row][i] > bigger_right)
		{
			bigger_right = grid[row][i];
			view_right++;
		}
	}
	if (view_right == clu[3][row])
		return (1);
	return (0);
}

int	clu_cu(int grid[4][4], int clu[4][4], int col)
{
	int	i;
	int	view_up;
	int	bigger_up;

	i = -1;
	view_up = 0;
	bigger_up = 0;
	while (++i < 4)
	{
		if (grid[i][col] > bigger_up)
		{
			bigger_up = grid[i][col];
			view_up++;
		}
	}
	if (view_up == clu[0][col])
		return (1);
	return (0);
}

int	clu_cd(int grid[4][4], int clu[4][4], int col)
{
	int	i;
	int	view_down;
	int	bigger_down;

	view_down = 0;
	bigger_down = 0;
	i = 4;
	while (--i >= 0)
	{
		if (grid[i][col] > bigger_down)
		{
			bigger_down = grid[i][col];
			view_down++;
		}
	}
	if (view_down == clu[1][col])
		return (1);
	return (0);
}
