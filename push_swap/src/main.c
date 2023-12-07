//mets un header

#include "push_swap.h"

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
	if (!find_path(a, b))
		ft_error_free("Error.", argv, argc == 2);
	return (0);
}
