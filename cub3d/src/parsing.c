#include "cub.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_exit("Error: Wrong number of argument.");
	if (!check_format(argv[1]), ".cub")
		ft_exit("Error: Wrong format");
}

void	init_game(t_game **game)
{
	*game = ft_calloc(1, sizeof(t_game));
	(*game)->map = NULL;
	(*game)->instructions = NULL;
}

void	fill_tabs(t_game **game, char *file_name)
{
	char	*line;
	int		flag;
	int		fd;

	flag = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_free_exit(*game, "Error: File could not be opened.");
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_map(line))
			add_line((*game)->map, line);
		else
			add_line((*game)->instructions, line);
		free(line);
	}
	close(fd);
}

void	check_tabs(t_game **game)
{

}

void	parsing(t_game **game, int argc, char **argv)
{
	check_args(argc, argv);
	init_game(game);
	fill_tabs(game, argv[1]);
	check_tabs(game);
}
