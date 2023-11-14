/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:49:17 by vcornill          #+#    #+#             */
/*   Updated: 2023/11/14 15:24:14 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_columns(game);
	ft_count_map_parameters(game);
	ft_verify_map_parameters(game);
}

void	ft_check_rows(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error("Invalid Map. Wall missing from the first row.\n", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error("Invalid Map. Wall missing from the last row.\n", game);
	}
}

void	ft_check_columns(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error("Invalid Map. Wall missing from the first col.\n", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error("Invalid Map. Wall missing from the last col.\n", game);
	}
}

void	ft_count_map_parameters(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				ft_error("Invalid Map. Wrong parameters.", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COINS)
				game->map.coins++;
			else if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
		}
	}
}

void	ft_verify_map_parameters(t_game *game)
{
	if (game->map.coins == 0)
		ft_error("Invalid Map. No Coins!", game);
	else if (game->map.exit == 0)
		ft_error("Invalid Map. No Exit!", game);
	else if (game->map.players != 1)
		ft_error("Invalid Map. Single player authorized.", game);
}
