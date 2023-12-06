//mets un header


#include "push_swap.h"

t_list	*find_last(t_list *a)
{
	while (a->next)
		a = a->next;
	return (a);
}

void	quicksort(t_list **a, t_list **b)
{
	t_list	*last;

	last = find_last(*a);
	while (*(int *)last->content <= *(int *)(*a)->content)
	{
		rra(a);
		last = find_last(*a);
	}
	while ((*a)->next)
		if(*(int *)(*a)->content > *(int *)(*a)->next->content)
			ra(a);
		else
			pb(b, a);

}
