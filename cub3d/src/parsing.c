#include "cub.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_exit("Wrong number of argument.");
	if (!check_format(argv[1], ".cub"))
		ft_exit("Wrong format");
}

void	init_game_ptr(t_game **game)
{
	int	i;

	*game = ft_calloc(1, sizeof(t_game));
	(*game)->map = NULL;
	(*game)->instructions = NULL;
	(*game)->mlx = mlx_init(WIDTH, HEIGHT, "PsYcHaDeLeCkS3D", 1);
	i = -1;
	while (++i < 4)
		(*game)->tab_texture[i] = NULL;
}

void	fill_tabs(t_game **game, char *file_name)
{
	char	*line;
	int		fd;
	int		flag;

	flag = 0;	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_free_exit(*game, "File could not be opened.");
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_map(line) && !only_w_spaces(line))
		{	
			(*game)->map = add_line((*game)->map, line);
			flag = 1;
		}
		else if (!flag && !only_w_spaces(line))
			(*game)->instructions = add_line((*game)->instructions, line);
		else
			free(line);
	}
	close(fd);
}

void	check_tabs(t_game **game)
{
	int	tab_size;

	is_valid_map(game);
	tab_size = -1;
	while ((*game)->instructions && (*game)->instructions[++tab_size])
	{
		if (tab_size == 0)
			valid_instruction(game, (*game)->instructions[tab_size], "NO ", 0);
		else if (tab_size == 1)
			valid_instruction(game, (*game)->instructions[tab_size], "SO ", 1);
		else if (tab_size == 2)
			valid_instruction(game, (*game)->instructions[tab_size], "WE ", 2);
		else if (tab_size == 3)
			valid_instruction(game, (*game)->instructions[tab_size], "EA ", 3);
		else if (tab_size == 4)
			valid_color(game, (*game)->instructions[tab_size], "F ");
		else if (tab_size == 5)
			valid_color(game, (*game)->instructions[tab_size], "C ");
	}
	if (tab_size != 6)
		ft_free_exit(*game, "Wrong number of instructions.");
}

void	init_player_pos(t_game **game)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = -1;
	while ((*game)->instructions[++i])
	{
		j = -1;
		while ((*game)->instructions[++j])
			if (((*game)->instructions[i][j] == 'N')
				|| ((*game)->instructions[i][j] == 'W')
				|| ((*game)->instructions[i][j] == 'E')
				|| ((*game)->instructions[i][j] == 'S'))
				{
					found = 1;
					(*game)->player_pos.x = j;
					(*game)->player_pos.y = i;
					(*game)->starting_dir = (*game)->instructions[i][j];
					break ;
				}
		if (found)
			break ;
	}
}

void	parsing(t_game **game, int argc, char **argv)
{
	check_args(argc, argv);
	init_game_ptr(game);
	fill_tabs(game, argv[1]);
	check_tabs(game);
	init_player_pos(game);
}
