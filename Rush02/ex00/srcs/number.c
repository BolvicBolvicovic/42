

#include "ourlib.h"

int		ft_is_number(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int		ft_modthree(char *str)
{
	int		mod;

	if (ft_strlen(str) % 3 > 0)
		mod = 1;
	else
		mod = 0;
	return (mod);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}
		index++;
	}
	return (0);
}
