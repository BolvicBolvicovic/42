/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:00:18 by vcornill          #+#    #+#             */
/*   Updated: 2023/11/08 17:05:41 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int	on_keypress(int keysym, t_game *data)
{
	ft_printf("%d\n", keysym);
	(void)data;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	(void)argc;
	(void)argv;
	game = malloc(sizeof(t_game));
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 600, 400, "SO_DEEEEEP");
	if (!game->win_ptr)
		return (free(game->mlx_ptr), 1);
	// Register key release hook
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);
 
	// Register destroy hook
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
 
	// Loop over the MLX pointer
	mlx_loop(game->mlx_ptr);
	free(game);
	return (0);
}
