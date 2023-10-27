#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		continue ;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*conca;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	conca = malloc(len + 1);
	if (!conca)
		return (NULL);
	if (!s1 && !s2)
		return (0);
	i = -1;
	while (s1[++i])
		conca[i] = s1[i];
	j = -1;
	while (s2[++j])
		conca[j + i] = s2[j];
	conca[i + j] = '\0';
	return (conca);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != (unsigned char)c && *s)
		s++;
	if (*s != (unsigned char)c)
		return (0);
	return (s);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*tampon;

	i = ft_strlen(src);
	tampon = malloc(i + 1);
	if (tampon == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		tampon[i] = src[i];
	tampon[i] = '\0';
	return (tampon);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	substring = malloc(len + 1);
	if (!substring)
		return (0);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
