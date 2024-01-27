#include "cub.h"

void	ft_free_exit(t_game *game, char *str)
{
	free_game(game);
	ft_exit(str);
}

void	ft_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	while (game->instructions[++i])
		free(game->instructions[i]);
	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
	free(game->instructions);
	free(game);
}
