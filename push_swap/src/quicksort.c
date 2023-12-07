//mets un header


#include "push_swap.h"

void	index_to_values(t_list **a, int *index)
{
	t_list	*list;
	int		i;

	i = -1;
	list = *a;
	while (list)
	{
		*(int *)list->content = index[++i];
		list = list->next;
	}
	free(index);
}

void	assign_index(t_list **stack_a, int stack_size)
{
	t_list	*ptr;
	int		smallest;
	int		value;
	int		*index;
	int		i;
	int		original_size;

	original_size = stack_size;
	index = ft_calloc(sizeof(int), stack_size);
	i = 0;
	while (stack_size-- > 0)
	{
		ptr = *stack_a;
		value = 2147483647;
		smallest = -1;
		while (ptr)
		{
			if (*(int *)ptr->content < value && index[i] == 0)
			{
				value = *(int *)ptr->content;
				smallest = i;
			}
			i++;
			ptr = ptr->next;
		}
		if (smallest != -1)
			index[smallest] = (stack_size - original_size) * (-1);
		i = 0;
	}
	index_to_values(stack_a, index);
}

void	save_three(t_list **a, t_list **b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_lstsize(*a);
	assign_index(a, stack_size);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if(*(int *)(*a)->content <= stack_size / 2)
		{
			pb(b, a);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(b, a);
		pushed++;
	}
}

int	get_low_pos(t_list **a)
{
	t_list	**list;
	int		i;
	int		lowest;
	int		low_pos;
	i = 0;
	low_pos = 0;
	list = a;
	lowest = *(int *)(*list)->content;
	while (*list)
	{
		if (*(int *)(*list)->content < lowest)
		{
			lowest = *(int *)(*list)->content;
			low_pos = i;
		}
		i++;
		*list = (*list)->next;
	}
	return (low_pos);
}

void	shift_stack(t_list **a)
{
	int	low_pos;
	int	stack_size;

	stack_size = ft_lstsize(*a);
	low_pos = get_low_pos(a);
	if (low_pos > stack_size / 2)
	{
		while (low_pos < stack_size)
		{
			rra(a);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			ra(a);
			low_pos--;
		}
	}
}

void	quicksort(t_list **a, t_list **b)
{
	save_three(a, b);
	sort_three(a);
	while (*b)
		do_best_move(a, b);	
	if (!is_sorted(*a))
		shift_stack(a);
}

