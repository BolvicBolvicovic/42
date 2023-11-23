//mets un header

#include "push_swap.h"

void	ft_error(char *error)
{
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}

void	ft_error_free(char *error, char **argv, int flag)
{
	if (flag)
		ft_free_matrix(argv);
	ft_error(error);
}

void	ft_free_matrix(char **m)
{
	int	i;

	i = -1;
	while (m[++i])
		free(m[i]);
	free(m);
}
