//mets un header

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_list **b, t_list **a)
{
	push(a, b);
	ft_printf("pb\n");
}
