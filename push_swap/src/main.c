//mets un header

#include "push_swap.h"

int	stack_sorted(t_node *a)
{
	if (a->next && a->next->num > a->num)
		return (0);
	else if (a->next)
		return (stack_sorted(a->next));
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
//	t_node	*b;

	a = NULL;
//	b = NULL;
	ft_check_args(argc, argv, argc == 2);
	init_stack(argv, &a, argc == 2);
	if (!stack_sorted(a))
		ft_printf("Stack not sorted.\n");
	else
		ft_printf("Stack sorted.\n");
	return (0);
}
