#include "../libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
  t_list *new;
  t_list *newnode;
  t_list *newtail;
  void *newcontent;
  
  new = 0;
  while (lst)
  {
    newcontent = f(lst->content);
    if (!newcontent && del)
    {
      ft_lstclear(&new, del);
      return (0);
    }
    newnode = malloc(sizeof(t_list));
    if (!newnode && del)
    {
      ft_lstclear(&new, del);
      return (0);
    }
    newnode->next = 0;
    newnode->content = newcontent;
    if (!new)
      new = newnode;
    else
      newtail->next = newnode;
    newtail = newnode;
    lst = lst->next;
  }
  return (new);
}
