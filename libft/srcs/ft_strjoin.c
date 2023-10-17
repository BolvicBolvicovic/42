/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:17:19 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/18 10:17:20 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
