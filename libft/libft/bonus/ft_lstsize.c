#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*test;

	count = 0;
	test = lst;
	while (test->next)
	{
		count++;
		test = test->next;
	}
	return (count);
}
