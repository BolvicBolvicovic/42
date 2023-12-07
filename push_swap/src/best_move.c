//mets un header

#include "push_swap.h"

t_list	*get_target(t_list *a, t_list *b)
{
	t_list	*tmp;
	t_list	*target;
	int	target_pos;
	int	index;
	
	tmp = a;
	index = *(int *)b->content;
	target_pos = 2147483647;
	while (tmp)
	{
		if (*(int *)tmp->content > index && *(int *)tmp->content < target_pos)
		{
			target_pos = *(int *)tmp->content;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (target_pos != 2147483647)
		return (target);
	tmp = a;
	while (tmp)
	{
		if (*(int *)tmp->content < target_pos)
		{
			target_pos = *(int *)tmp->content;
			target = tmp;
		}
		tmp = tmp->next;
	}
	return (target);
}

int	get_best_cost(t_list *a, t_list *b, t_list *target)
{
	int	cost;

	(void)a;
	(void)b;
	(void)target;
	cost = 0;
	return (cost);
}

t_list	*get_best_node(t_list *a, t_list *b, t_list **node_bullet)
{
	t_list	*target;
	t_list	*current;
	int		current_cost;
	int		*best_cost;
	
	best_cost = NULL;
	while (b)
	{
		current = get_target(a, b);
		current_cost = get_best_cost(a, b, current);
		if (!best_cost || current_cost < *best_cost)
		{
			if (!best_cost)
				best_cost = ft_calloc(sizeof(int), 1);
			target = current;
			*node_bullet = b;
			*best_cost = current_cost;
		}
		b = b->next;
	}
	free(best_cost);
	return (target);
}

void	do_best_move(t_list **a, t_list **b)
{
	t_list	*node_target;
	t_list	*node_bullet;

	node_target = get_best_node(*a, *b, &node_bullet);
	move_node(a, b, node_target, node_bullet);
	if (*b)
		do_best_move(a, b);
}
