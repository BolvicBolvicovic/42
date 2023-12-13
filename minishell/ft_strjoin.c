/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:17:19 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/13 18:32:16 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*tmp;

	tmp = s;
	tab_p = tab;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*tab_p = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab_p;
		}
	}
	*tab_p = NULL;
}

int	ft_count_words(char const *s, char sep)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == sep)
			++i;
		if (s[i])
			++word_count;
		while (s[i] && s[i] != sep)
			++i;
	}
	return (word_count);
}

int	test(char **split, int size)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i])
		continue ;
	if (i != size)
	{
		j = -1;
		while (++j < size)
			free(split[j]);
		free(split);
	}
	return (i - size);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	if (test(new, size))
		return (NULL);
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		continue ;
	return (i);
}

int	ft_totalsizeofstr2stars(char **strs, int size, char *sep)
{
	int	i;
	int	count;
	int	sizeofsep;

	sizeofsep = ft_strlen(sep);
	count = 0;
	i = -1;
	while (++i < size)
		count += ft_strlen(strs[i]);
	return (count + sizeofsep * (size - 1));
}

char	*addcharacters(char *conca, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		conca[i] = str[i];
	return (&conca[i]);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*conca;
	int		i;

	if (size <= 0)
		return (conca = malloc(0));
	i = -1;
	conca = malloc(ft_totalsizeofstr2stars(strs, size, sep) + 1);
	if (conca == NULL)
		return (conca);
	while (++i < size)
	{
		conca = addcharacters(conca, strs[i]);
		if (i < size - 1)
			conca = addcharacters(conca, sep);
	}
	*conca = '\0';
	return (conca - ft_totalsizeofstr2stars(strs, size, sep));
}
