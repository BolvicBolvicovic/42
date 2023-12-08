//mets un header

#include "push_swap.h"

void q(t_list *l)
{
	while (l)
	{
		ft_printf("%d ", *(int *)l->content);
		l = l->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_check_args(argc, argv, argc == 2);
	init_stack(argv, &a, argc == 2);
	find_path(&a, &b);
	q(a);
	q(b);
	free_list(a);
	return (0);
}
