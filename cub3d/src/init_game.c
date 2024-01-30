#include "cub.h"

void	rotate_left(t_game *game, double rotation_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_pos.x;
	old_plane_x = game->dir_plane.x;
	game->dir_pos.x = game->dir_pos.x * cos(rotation_angle) - game->rc.dir.y
		* sin(rotation_angle);
	game->dir_pos.y = old_dir_x * sin(rotation_angle) + game->rc.dir.y
		* cos(rotation_angle);
	game->rc.plane.x = game->rc.plane.x * cos(rotation_angle) - game->rc.plane.y
		* sin(rotation_angle);
	game->rc.plane.y = old_plane_x * sin(rotation_angle) + game->rc.plane.y
		* cos(rotation_angle);
}

void	rotate_right(t_game *game, double rotation_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_pos.x;
	old_plane_x = game->rc.plane.x;
	game->dir_pos.x = game->rc.dir.x * cos(-rotation_angle) - game->rc.dir.y
		* sin(-rotation_angle);
	game->dir_pos.y = old_dir_x * sin(-rotation_angle) + game->rc.dir.y
		* cos(-rotation_angle);
	game->rc.plane.x = game->rc.plane.x * cos(-rotation_angle)
		- game->rc.plane.y * sin(-rotation_angle);
	game->rc.plane.y = old_plane_x * sin(-rotation_angle) + game->rc.plane.y
		* cos(-rotation_angle);
}

void	set_dir_pos(t_game *game)
{
	if (starting_dir == 'S')
		rotate_right(game, PI);
	if (starting_dir == 'E')
		rotate_right(game, PI / 2);
	if (starting_dir == 'W')
		rotate_left(game, PI / 2);
}

void	init_raycasting(t_game *game)
{
	(*game)->dir_pos.x = -0.5;
	(*game)->dir_pos.y = 0;
	set_dir_pos(t_game *game)	
	(*game)->plane_pos = 0;
	(*game)->plane_pos = 0.90;
}

void	init_game(t_game *game)
{
	mlx_set_cursor_mode(game.mlx, MLX_MOUSE_HIDDEN);
	init_raycasting(game);
}
