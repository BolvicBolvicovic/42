#include "cub.h"

void	init_floor_cast(int y, t_game *game)
{
	game->ray0.x = game->dir_pos.x - game->plane_pos.x;
	game->ray0.y = game->dir_pos.y - game->plane_pos.y;
	game->ray1.x = game->dir_pos.x + game->plane_pos.x;
	game->ray1.y = game->dir_pos.y + game->plane_pos.y;
	game->p = y - HEIGHT / 2;
	game->pos_z = 0.5 * HEIGHT;
	game->row_distance = game->pos_z / game->p;
	game->floor_step.x = game->row_distance
		* (game->ray1.x - game->ray0.x) / WIDTH;
	game->floor_step.y = game->row_distance
		* (game->ray1.y - game->ray0.y) / WIDTH;
	game->floor.x = game->pos.x + game->row_distance * game->ray0.x;
	game->floor.y = game->pos.y + game->row_distance * game->ray0.y;
}

void	floor_cast(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < HEIGHT)
	{
		x = -1;
		init_floor_cast(y, game);
		while (++x < WIDTH)
		{
			game->cell.x = (int)(game->floor.x);
			game->cell.y = (int)(game->floor.y);
			game->texture_floor.x = (int)(TEXTUREWIDTH * (game->floor.x - game->cell.x)) & (TEXTUREWIDTH - 1);
			game->texture_floor.y = (int)(TEXTUREHEIGHT * (game->floor.y - game->cell.y)) & (TEXTUREHEIGHT - 1);
			game->floor.x += game->floor_step.x;
			game->floor.y += game->floor_step.y;
		}
	}
}

void	raycast(t_game *game)
{
	static int			i = 0;
	static mlx_t_image	image;

	if (count > 0)
		mlx_delete_image(game->mlx, image);
	image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	floor_cast(game);
}
