//mets un header

#include "push_swap.h"

int	*addnum(int num, char** argv, int new_av_flag)
{
	int	*ptr_num;

	ptr_num = ft_calloc(sizeof(int), 1);
	if (!ptr_num)
		ft_error_free("Error.", argv, new_av_flag);
	*ptr_num = num;
	return (ptr_num);
}

void	init_stack(char **argv, t_list **list, int new_av_flag)
{
	t_list	*new_node;
	int		i;

	i = 0;
	if (new_av_flag)
		i--;
	while (argv[++i])
	{
		new_node = ft_lstnew(addnum(ft_atoi(argv[i]), argv, new_av_flag));
		if (*list)
			ft_lstadd_back(list, new_node);
		else
			*list = new_node;
	}
	if (new_av_flag)
		ft_free_matrix(argv);
}

