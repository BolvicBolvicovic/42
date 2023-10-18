#include "../libft.h"

t_list *ft_lstnew(void *content)
{
  t_list *newlst;
  
  newlst = malloc(sizeof(t_list));
  newlst->content = content;
  newlst->next = 0;
  return (newlst);
}
