#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*test;

	test = lst;
	while (test->next)
		test = test->next;
	return (test);
}
