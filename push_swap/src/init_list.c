//mets un header

#include "push_swap.h"

void	creat_new_lists(int argc, char **argv, finder_t *finder)
{
        int     i;

        i = -1;
	finder->list_a = ft_calloc(sizeof(int), argc);
	finder->list_b = ft_calloc(sizeof(int), argc);
	if (!finder->list_a || !finder->list_b)
		ft_error_free("Lists allocation failed.", finder);
	while (argv[++i])
		finder->list_a[i] = ft_atoi(argv[i]);
}

