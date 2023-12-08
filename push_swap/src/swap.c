//mets un header

#include "push_swap.h"

void	swap(t_list **a)
{
	int	*tmp;

	tmp = ft_calloc(sizeof(int), 1);
	if (ft_lstsize(*a) > 1)
	{
		*tmp = *(int *)(*a)->content;
		*(int *)(*a)->content = *(int *)(*a)->next->content;
		*(int *)(*a)->next->content = *tmp;
	}
	free(tmp);
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
