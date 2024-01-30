#include "cub.h"

void	init_raycasting(t_game *game)
{
	
}

void	init_game(t_game *game)
{
	mlx_set_cursor_mode(game.mlx, MLX_MOUSE_HIDDEN);
	init_raycasting(game);
}
