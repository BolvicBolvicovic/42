#include "cub.h"

int	main(int argc, char **argv )
{
	t_game	*game;

	parsing(&game, argc, argv);
	free_game(game);
	return (0);
}
