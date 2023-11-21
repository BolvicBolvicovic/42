/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:49:35 by vcornill          #+#    #+#             */
/*   Updated: 2023/11/09 15:49:36 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map.full[game->images->player_front->instances->y /  16 - 1]
		[game->images->player_front->instances->x / 16] != WALL)
	{
		game->images->player_front->instances->y -= 16;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_right(t_game *game)
{
	if (game->map.full[game->images->player_front->instances->y / 16]
		[game->images->player_front->instances->x / 16 + 1] != WALL)
	{
		game->images->player_front->instances->x += 16;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_down(t_game *game)
{
	if (game->map.full[game->images->player_front->instances->y / 16 + 1]
		[game->images->player_front->instances->x / 16] != WALL)
	{
		game->images->player_front->instances->y += 16;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_left(t_game *game)
{
	if (game->map.full[game->images->player_front->instances->y / 16]
		[game->images->player_front->instances->x / 16 - 1] != WALL)
	{
		game->images->player_front->instances->x -= 16;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx_ptr);
	collec_keys(game);
}
