#include "../libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tmp;

	if (!s || !f)
		return (0);
	tmp = malloc(ft_strlen(s) + 1);
	if (!tmp)
		return (0);
	i = -1;
	while (s[++i])
		tmp[i] = f(i, s[i]);
	return (tmp);
}
