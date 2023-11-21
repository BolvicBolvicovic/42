//OUBLIE PAS TON HEADER

#include "so_long.h"

void	draw_floor(t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			mlx_image_to_window(game->mlx_ptr, image->floor1, x * 16, y * 16);
			if (game->map.full[y][x] == WALL)
				mlx_image_to_window(game->mlx_ptr, image->wall, x * 16, y * 16);
			if (game->map.full[y][x] == MAP_EXIT)
			{
				mlx_image_to_window(game->mlx_ptr, image->exit_closed, x * 16, y * 16);
				mlx_image_to_window(game->mlx_ptr, image->open_exit, x * 16, y * 16);
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game, t_images *image)
{
	int	x;
	int	y;

	draw_floor(game, image);
	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == COINS)
				mlx_image_to_window(game->mlx_ptr, image->coins, x * 16, y * 16);

			if (game->map.full[y][x] == PLAYER)
				mlx_image_to_window(game->mlx_ptr, image->player_front, x * 16, y * 16);
			x++;
		}
		y++;
	}
}

void	ft_init_image(t_game *game)
{
	game->images = ft_calloc(1, sizeof(t_images));
	game->images->floor1 = mlx_texture_to_image(game->mlx_ptr, &game->floor1->texture);
        game->images->floor2 = mlx_texture_to_image(game->mlx_ptr, &game->floor2->texture);
	game->images->wall = mlx_texture_to_image(game->mlx_ptr, &game->wall->texture);
	game->images->coins = mlx_texture_to_image(game->mlx_ptr, &game->coins->texture);
	game->images->player_front = mlx_texture_to_image(game->mlx_ptr, &game->player_front->texture);
        game->images->player_left = mlx_texture_to_image(game->mlx_ptr, &game->player_left->texture);
        game->images->player_right = mlx_texture_to_image(game->mlx_ptr, &game->player_right->texture);
        game->images->player_back = mlx_texture_to_image(game->mlx_ptr, &game->player_back->texture);
	game->images->open_exit = mlx_texture_to_image(game->mlx_ptr, &game->open_exit->texture);
	game->images->exit_closed = mlx_texture_to_image(game->mlx_ptr, &game->exit_closed->texture);
}

