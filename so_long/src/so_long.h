/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:31:57 by vcornill          #+#    #+#             */
/*   Updated: 2023/11/16 13:57:11 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include "ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include "MLX42.h"
# include <stdlib.h>
# include "libft.h"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct	images
{
	mlx_image_t		*wall;
        mlx_image_t		*floor1;
        mlx_image_t		*floor2;
        mlx_image_t		*coins;
        mlx_image_t		*open_exit;
        mlx_image_t		*exit_closed;
        mlx_image_t		*player_front;
        mlx_image_t		*player_left;
        mlx_image_t		*player_right;
        mlx_image_t		*player_back;
}	t_images;

typedef struct s_game
{
	void		*mlx_ptr;
	int			movements;
	int			player_sprite;
	t_map			map;
	bool			map_alloc;
	t_images			*images;
	xpm_t		*wall;
	xpm_t		*floor1;
	xpm_t		*floor2;
	xpm_t		*coins;
	xpm_t		*open_exit;
	xpm_t		*exit_closed;
	xpm_t		*player_front;
	xpm_t		*player_left;
	xpm_t		*player_right;
	xpm_t		*player_back;
}	t_game;
# define WALL_XPM			"assets/ground/tileset_1bit-5.png.xpm42"
# define FLOOR1_XPM			"assets/ground/tileset_1bit-64.png.xpm42"
# define FLOOR2_XPM			"assets/ground/tileset_1bit-37.png.xpm42"
# define COINS_XPM			"assets/ground/tileset_1bit-48.png.xpm42"
# define PLAYER_FRONT_XPM	"assets/characters/front-1.png.xpm42"
# define PLAYER_LEFT_XPM	"assets/characters/left-37.png.xpm42"
# define PLAYER_RIGHT_XPM	"assets/characters/right-25.png.xpm42"
# define PLAYER_BACK_XPM	"assets/characters/back-13.png.xpm42"
# define OPEN_EXIT_XPM		"assets/ground/tileset_1bit-51.png.xpm42"
# define EXIT_CLOSED_XPM	"assets/ground/tileset_1bit-50.png.xpm42"

//Window Handler
int     ft_win(t_game *game);
int     ft_error(char *message, t_game *game);

//Map Checker
void    ft_check_map(t_game *game);
void    ft_check_rows(t_game *game);
void    ft_check_columns(t_game *game);
void    ft_count_map_parameters(t_game *game);
void    ft_verify_map_parameters(t_game *game);

//Utils
void    ft_check_command_line_arguments(int argc, char **argv, t_game *game);
char	*ft_strappend(char **s1, const char *s2);

//Free
void    ft_free_all_allocated_memory(t_game *game);
void    ft_destroy_images(t_game *game);
void    ft_free_map(t_game *game);

//Init Map
void    ft_init_map(t_game *game, char *argv);
void    ft_check_for_empty_line(char *map, t_game *game);

//Init Game
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
void    ft_init_image(t_game *game);

#endif
