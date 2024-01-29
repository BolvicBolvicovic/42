#include "cub.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_exit("Wrong number of argument.");
	if (!check_format(argv[1], ".cub"))
		ft_exit("Wrong format");
}

void	init_game(t_game **game)
{
	int	i;

	*game = ft_calloc(1, sizeof(t_game));
	(*game)->map = NULL;
	(*game)->instructions = NULL;
	(*game)->mlx = mlx_init(512, 512, "PsYcHaDeLeCkS3D", 1);
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
		if (is_map(line))
		{	
			(*game)->map = add_line((*game)->map, line);
			flag = 1;
		}
		else if (!flag)
			(*game)->instructions = add_line((*game)->instructions, line);
	}
	close(fd);
}

void	check_tabs(t_game **game)
{
	int	tab_size;

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

void	parsing(t_game **game, int argc, char **argv)
{
	check_args(argc, argv);
	init_game(game);
	fill_tabs(game, argv[1]);
	check_tabs(game);
}
