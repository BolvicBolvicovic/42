#include <unistd.h>

void    ft_putstr(char *str)
{
    int i;
    
    i = -1;
    while (++str[i])
        write(1, &str[i], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0)
			return (0);
		i++;
	}
	if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
}

int	main([[maybe_unused]]int argc, char **argv)
{
	int	i;
	char	*temp;
	int	sorted;
	
	sorted = 1;
	i = 0;
	while (sorted) // Continuer tant que le tri n'est pas effectué
	{
		sorted = 0; // Supposer que le tableau est trié
		i = 0;
		while (argv[i + 1]) // Parcourir jusqu'à l'avant-dernier élément
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
				sorted = 1;
			}
			i++;
		}
	}
	i = 0;
	while(argv[++i])
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
	}
	return (0);
}
