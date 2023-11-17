/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:00:18 by vcornill          #+#    #+#             */
/*   Updated: 2023/11/16 13:43:13 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
 
int	on_keypress(int keysym, t_game *data)
{
	ft_printf("%d\n", keysym);
	(void)data;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_check_command_line_arguments(argc, argv, game);
	ft_init_map(game, argv[1]);
	ft_init_vars(game);
	//ft_check_map(game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_init_image(game);
 
	mlx_loop(game->mlx_ptr);
	mlx_terminate(game->mlx_ptr);
	free(game);
	return (0);
}
