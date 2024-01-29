#include "cub.h"

int	check_format(char *str, char *cmp)
{
	int	i;

	i = 0;
	while (str[i] && ft_strcmp(&str[i], cmp) != 0)
		i++;
	if (ft_strcmp(&str[i], cmp) == 0)
		return (1);
	return (0);
	
}

int	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i + 1] && line[i + 1] == '\n')
			line[i + 1] = '\0';
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'O'
			&& line[i] != ' ' && line[i] != '\t')
			return (0);
	}
	return (1);
}

char	**add_line(char **tab, char *line)
{
	char	**newtab;
	int		tab_size;
	int		i;

	tab_size = 1;
	while (tab && tab[tab_size])
		tab_size++;
	newtab = ft_calloc(tab_size + 2, sizeof(char *));
	i = -1;
	while (++i < tab_size && tab)
		newtab[i] = ft_strdup(tab[i]);
	newtab[i] = ft_strdup(line);
	newtab[++i] = NULL;
	ft_free_tab(tab);
	free(line);
	return (newtab);
}

int	valid_path(char *path, t_game **game, int indexText)
{
	int	i;

	i = -1;
	while (path[++i])
		if (path[i] == '\n')
			path[i] = '\0';
	(*game)->tab_texture[indexText] = mlx_load_png(path);
	if (!(*game)->tab_texture[indexText])
		return (0);
	return (1);
}

int	valid_color_setting(char *setting)
{
	int	i;
	int	coma_flag;
	
	coma_flag = 0;
	i = 0;
	while (setting[i] && setting[i] != '\n')
	{
		if (!ft_isdigit(setting[i]))
			return (0);
		if (ft_atoi(&setting[i]) > 255)
			return (0);
		while (ft_isdigit(setting[i]))
			i++;
		if (setting[i] != ',' && coma_flag < 2)
			return (0);
		else
			coma_flag++;
		i++;
	}
	return (1);
}

void	valid_instruction(t_game **game, char *line, char *id, int indexText)
{
	int	i;

	i = 0;
	while (line && line[i] && i < 3)
	{
		if (line[i] != id[i])
			ft_free_exit(*game, "Instruction ID invalid.");
		i++;
	}
	if (!valid_path(&line[3], game, indexText))
		ft_free_exit(*game, "Instruction path invalid.");
}

void	valid_color(t_game **game, char *line, char *id)
{
	int	i;

	i = 0;
	while (line && line[i] && i < 2)
	{
		if (line[i] != id[i])
			ft_free_exit(*game, "Color ID invalid.");
		i++;
	}
	if (!valid_color_setting(&line[2]))
		ft_free_exit(*game, "Color instruction invalid.");
}
