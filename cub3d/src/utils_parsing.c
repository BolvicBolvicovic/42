#include "cub.h"

int	check_format(char *str, char *cmp)
{
	int	i;

	i = -1;
	while (str[i] && ft_strcmp(&str[i], cmp) != 0)
		i++;
	if (ft_strcmp(&str[i], cmp) == 0)
		return (1);
	return (0);
	
}

is_map
add_line_
