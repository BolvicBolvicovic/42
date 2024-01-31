#pragma once

#include "ft_printf.h"
#include "MLX42.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

# define WIDTH	640
# define HEIGHT	480
# define TEXTUREWIDTH	32
# define TEXTUREHEIGHT	32


typedef struct s_coord
{
	double	x;
	double	y;
}		t_coord;

typedef struct s_int_coord
{
	int	x;
	int	y;
}		t_int_coord;

typedef struct	s_game
{
	char			**instructions;
	char			**map;
	t_coord			player_pos;
	t_coord			plane_pos;
	t_coord			dir_pos;
	t_int_coord		cell;
	t_int_coord		texture_floor;
	t_coord			ray0;
	t_coord			ray1;
	t_coord			floor_step;
	t_coord			floor;
	int				p;
	float			pos_z;
	float			row_distance;
	int				starting_dir;	
	

	mlx_t			*mlx;
	mlx_texture_t	*tab_texture[4];
}	t_game;

// Error
void	ft_exit(char *str);
void	free_game(t_game *game);
void	ft_free_exit(t_game *game, char *str);

// Utils general
void	ft_free_tab(char **tab);
int		only_w_spaces(char *str);

// Parsing
void	parsing(t_game **game, int argc, char **argv);

// Utils parsing
int		check_format(char *str, char *cmp);
int		is_map(char *line);
char	**add_line(char **tab, char *line);
void	valid_instruction(t_game **game, char *line, char *id, int indexText);
void	valid_color(t_game **game, char *line, char *id);
void	is_valid_map(t_game **game);

// Init game
void	init_game(t_game *game);
