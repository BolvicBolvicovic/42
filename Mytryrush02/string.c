/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:17:15 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/26 13:49:48 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*h;
	char	*current_h;
	char	*n;

	h = str;
	n = to_find;
	if (*to_find == '\0')
		return (str);
	while (*h)
	{
		current_h = h;
		while (*n && *current_h == *n)
		{
			current_h++;
			n++;
		}
		if (*n == '\0')
			return (h);
		h++;
		n = to_find;
	}
	return (0);
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
