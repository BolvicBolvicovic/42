#include "cub.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	free(tab);
}

int	only_w_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '\t' && str[i] <= '\r') && str[i] != ' ')
			return (0);
	return (1);
}
