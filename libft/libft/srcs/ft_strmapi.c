#include "../libft.h"
#include <stdlib.h>

char  *ft_strmapi(char *s, char (*f)(unsigned int, char))
{
  int i;
  char  *tmp;

  tmp = malloc(ft_strlen(s));
  if (!tmp)
    return (0);
  i = 0;
  while (s[i++])
    tmp[i] = f(i, s[i]);
  return (tmp);
}
