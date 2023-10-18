#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
 	t_list *test;

	test = lst;
	while(test->next)
	{
		f(test);
		test = test->next;
	}
	f(test);
}
