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
	mlx_t	*mlx;
	mlx_texture_t	*tab_texture[4];
}	t_game;

// Error
void	ft_exit(char *str);
void	free_game(t_game *game);
void	ft_free_exit(t_game *game, char *str);

//Utils general
void	ft_free_tab(char **tab);

// Parsing
void	parsing(t_game **game, int argc, char **argv);

// Utils parsing
int		check_format(char *str, char *cmp);
int		is_map(char *line);
char	**add_line(char **tab, char *line);
void	valid_instruction(t_game **game, char *line, char *id, int indexText);
void	valid_color(t_game **game, char *line, char *id);
