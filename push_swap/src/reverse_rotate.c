//mets ton header

#include "push_swap.h"

void	get_tails(t_list *a, t_list **tail, t_list **pre_tail)
{
	while (a->next->next)
		a = a->next;
	*tail = a->next;
	*pre_tail = a;
}

void	reverse_rotate(t_list **a)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*pre_tail;
	
	if (*a && (*a)->next)
	{
		tmp = *a;
		get_tails(*a, &tail, &pre_tail);
		*a = tail;
		(*a)->next = tmp;
		pre_tail->next = NULL;
	}
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void    rrb(t_list **b)
{
        reverse_rotate(b);
        ft_printf("rrb\n");
}

void    rrr(t_list **a, t_list **b)
{
        reverse_rotate(a);
	reverse_rotate(b);
        ft_printf("rrr\n");
}
