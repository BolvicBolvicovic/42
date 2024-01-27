#pragma once

#include "ft_printf.h"
#include "MLX42.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
typedef struct	s_game
{
	char	**instructions;
	char	**map;
}	t_game;

// Error
void	ft_exit(char *str);
void	free_game(t_game *game);
void	ft_free_exit(t_game *game, char *str);

// Parsing
void	parsing(t_game **game, int argc, char **argv);

// Utils parsing
int	check_format(char *str, char *cmp);
