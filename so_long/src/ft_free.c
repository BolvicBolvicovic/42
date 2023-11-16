/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:36:26 by vcornill          #+#    #+#             */
/*   Updated: 2023/11/16 19:44:36 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_allocated_memory(t_game *game)
{
//	ft_destroy_images(game);
	ft_free_map(game);
	free(game->mlx_ptr);
	free(game);
}

void	ft_free_map(t_game *game)
{
	int	string;

	string = -1;
	while (++string < game->map.rows)
		free(game->map.full[string]);
	free(game->map.full);
}
