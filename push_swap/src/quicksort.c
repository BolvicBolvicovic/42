/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:22:09 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/12 15:16:58 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	assign_index(t_list **stack_a, int s_size, int o_size, int value)
{
	t_list	*ptr;
	int		smallest;
	int		*index;
	int		i;

	i = 0;
	index = ft_calloc(sizeof(int), s_size);
	while (s_size-- > 0)
	{
		ptr = *stack_a;
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
			index[smallest] = (s_size - o_size) * (-1);
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
	assign_index(a, stack_size, stack_size, 2147483647);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if (*(int *)(*a)->content <= stack_size / 2)
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

int	get_low_pos(t_list *a)
{
	int	i;
	int	lowest;
	int	low_pos;

	i = 0;
	low_pos = 0;
	lowest = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content < lowest)
		{
			lowest = *(int *)a->content;
			low_pos = i;
		}
		i++;
		a = a->next;
	}
	return (low_pos);
}

void	shift_stack(t_list **a)
{
	int	low_pos;
	int	stack_size;

	stack_size = ft_lstsize(*a);
	low_pos = get_low_pos(*a);
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
