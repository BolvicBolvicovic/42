//mets un header

#include "push_swap.h"

void	ft_error(char *error)
{
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}

void	ft_error_free(char *error, finder_t *finder)
{
	full_free(finder);
	ft_error(error);
}

void	full_free(finder_t *finder)
{
	int	i;

	i = -1;
	while (finder->path[++i])
		free(finder->path[i]);
	free(finder->path);
	free(finder->list_a);
	free(finder->list_b);
	free(finder);
}

void	ft_check_args(int argc, char **argv, finder_t *finder)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
	{
		free(finder);
		ft_error("No argument.");
	}
	while (argv[++i])
	{
		j = -1;
		if (argv[i][0] == '-' && argv[i][1])
			j = 0;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				free(finder);
				ft_error("At least one argument is not a number.");
			}
		}
	}
}

int	main(int argc, char **argv)
{
	finder_t	*finder;

	finder = ft_calloc(sizeof(finder_t), 1);
	ft_check_args(argc, argv, finder);
	creat_new_lists(argc, argv, finder);
	find_path(finder);
	full_free(finder);
	return (0);
}
