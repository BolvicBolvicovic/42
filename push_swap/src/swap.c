//mets un header

#include "push_swap.h"

void	swap(t_list **a)
{
	void	*tmp;

	if (ft_lstsize(*a) > 1)
	{
		tmp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = tmp;
	}
}

void	sa(t_list **a)
{
	swap(a);
	ft_printf("sa\n");
}

void    sb(t_list **b)
{
        swap(b);
        ft_printf("sb\n");
}

void    ss(t_list **a, t_list **b)
{
	swap(b);
        swap(a);
        ft_printf("ss\n");
}
