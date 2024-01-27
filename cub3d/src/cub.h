#pragma once

#include "ft_printf.h"
#include "MLX42.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_game
{
	char	**map;
}	t_game;

// Error

// Parsing
void	parsing(t_game **game);
void	free_game(t_game *game);
