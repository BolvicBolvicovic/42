#include "cub.h"

void	ft_free_exit(t_game *game, char *str)
{
	free_game(game);
	ft_exit(str);
}

void	ft_exit(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	while (game->instructions && game->instructions[++i])
		free(game->instructions[i]);
	i = -1;
	while (game->map && game->map[++i])
		free(game->map[i]);
	i = -1;
	while (++i < 4)
		if (game->tab_texture[i])
			mlx_delete_texture(game->tab_texture[i]);
	
	mlx_terminate(game->mlx);
	free(game->map);
	free(game->instructions);
	free(game);
}
