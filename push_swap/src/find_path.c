//mets ton header
#include "push_swap.h"

int	*find_highest(t_list *a)
{
	int		*highest;
	int		*content;
	t_list	*list;
	
	list = a;
	highest = (int *)a->content;
	while (list)
	{
		content = (int *)list->content;
		if (*content > *highest)
			highest = list->content;
		list = list->next;
	}
	return (highest);
}

int	is_sorted(t_list *a)
{
	int	*content;
	int	*next_content;
	
	while (a->next)
	{
		content = a->content;
		next_content = a->next->content;
		if (*content > *next_content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(t_list **a)
{
	int	*highest;
	int	*content;
	int	*next_content;

	if (is_sorted(*a))
		return ;
	highest = find_highest(*a);
	if ((*a)->content == highest)
		ra(a);
	else if ((*a)->next->content == highest)
		rra(a);
	content = (*a)->content;
	next_content = (*a)->next->content;
	if (*content > *next_content)
		sa(a);
}

void	find_path(t_list *a, t_list *b)
{
	if (ft_lstsize(a) == 3)
		sort_three(&a);
	else
		quicksort(&a, &b);
}
