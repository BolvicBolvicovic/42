
#include "ourlib.h"

void	ft_puterror(char *err)
{
	while (*err)
		write(2, err++, 1);
}

int		ft_error(char *str)
{
	if (!(ft_is_number(str)))
	{
		ft_puterror("Error\n");
		return (1);
	}
	if (ft_strlen(str) > 12)
	{
		ft_puterror("Dict Error\n");
		return (1);
	}
	return (0);
}
