//mets un header

#include "push_swap.h"

void	free_list(t_list *a)
{
	t_list *tmp;

	tmp = a;
	while (tmp)
	{
		free(tmp->content);
		tmp = tmp->next;
	}
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

void	free_node(void *content)
{
	free(content);
}

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
