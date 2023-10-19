#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*test;

	test = ft_lstlast(*lst);
	test->next = new;
}
