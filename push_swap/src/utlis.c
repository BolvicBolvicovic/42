//mets un header

#include "push_swap.h"

int	get_cost(t_list *a, t_list *target)
{
	int	cost;
	int	size_a;

	size_a = ft_lstsize(a);
	cost = 0;
	while (a)
	{
		if (a == target)
			break ;
		a = a->next;
		cost++;
	}
	if (cost > size_a / 2)
		cost -= size_a;
	return (cost);
}
