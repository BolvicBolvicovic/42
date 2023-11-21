//METS LE HEADER

#include "so_long.h"

int	total_collec(t_game *game)
{
	int	total;
	int	i;
	int	o;

	total = 0;
	i = 0;
	while (game->map.full[i])
	{
		o = 0;
		while (game->map.full[i][o])
		{
			if (game->map.full[i][o] == 'C')
				total++;
			o++;
		}
		i++;
	}
	return (total);
}

void	delete_key(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = game->n_collec;
	while (i < count)
	{
		if (((game->images->coins->instances[i].y
					== game->images->player_front->instances->y)
				&& (game->images->coins->instances[i].x
					== game->images->player_front->instances->x))
			&& game->images->coins->instances[i].enabled == true)
		{
			count--;
			game->images->coins->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	collec_keys(t_game *game)
{
	if (game->map.full[game->images->player_front->instances->y / 16]
		[game->images->player_front->instances->x / 16] == COINS)
	{
		delete_key(game);
		game->map.full[game->images->player_front->instances->y / 16]
		[game->images->player_front->instances->x / 16] = FLOOR;
		game->count_collec++;
		if (game->count_collec == game->n_collec)
			game->images->open_exit->instances->enabled = false;
	}
	if (game->map.full[game->images->player_front->instances->y / 16]
		[game->images->player_front->instances->x / 16] == MAP_EXIT)
	{
		if (game->count_collec == game->n_collec)
			mlx_close_window(game->mlx_ptr);
	}
}
