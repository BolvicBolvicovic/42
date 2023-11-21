/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:34:24 by vcornill          #+#    #+#             */
/*   Updated: 2023/11/16 19:44:00 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

xpm_t	*ft_new_sprite(char *path, t_game *game);

void	ft_init_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->move_count = 0;
	game->map.columns = ft_strlen(game->map.full[0]) - 1;
	game->n_collec = total_collec(game);
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init(666, 666, "DEMON", true);
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error("Couldn't find mlx pointer. Try it using a VNC.", game);
	}
}

void	ft_init_sprites(t_game *game)
{
	game->wall = ft_new_sprite(WALL_XPM, game);
	game->floor1 = ft_new_sprite(FLOOR1_XPM, game);
	game->floor2 = ft_new_sprite(FLOOR2_XPM, game);
	game->coins = ft_new_sprite(COINS_XPM, game);
	game->player_front = ft_new_sprite(PLAYER_FRONT_XPM, game);
	game->player_left = ft_new_sprite(PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(PLAYER_RIGHT_XPM, game);
	game->player_back = ft_new_sprite(PLAYER_BACK_XPM, game);
	game->open_exit = ft_new_sprite(OPEN_EXIT_XPM, game);
	game->exit_closed = ft_new_sprite(EXIT_CLOSED_XPM, game);
}
xpm_t	*ft_new_sprite(char *path, t_game *game)
{
	xpm_t	*sprite;

	sprite = mlx_load_xpm42(path);
	if (sprite == NULL)
		ft_error("Couldn't find a sprite. Does it exist?", game);
	return (sprite);
}
