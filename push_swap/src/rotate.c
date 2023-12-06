// mets un header

#include "push_swap.h"

void	rotate(t_list **a)
{
	t_list	*new_node;
	t_list	*tail;
	
	if (*a && (*a)->next)
	{
		new_node = (*a)->next;
		tail = *a;
		while (tail->next)
			tail = tail->next;
		tail->next = *a;
		(*a)->next = NULL;
		*a = new_node;
	}
}

void	ra(t_list **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void    rb(t_list **b)
{
        rotate(b);
        ft_printf("rb\n");
}

void    rr(t_list **a, t_list **b)
{
        rotate(a);
	rotate(b);
        ft_printf("rr\n");
}
