/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:39:57 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 16:22:17 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*mydup(char *src, int len)
{
	int		i;
	char	*tampon;

	tampon = malloc(len + 1);
	if (tampon == NULL)
		return (NULL);
	i = -1;
	while (src[++i] || len)
	{
		tampon[i] = src[i];
		len--;
	}
	tampon[i] = '\0';
	return (tampon);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		ccount;
	int		j;
	int		i;
	int		k;

	if (!s || !c)
		return (0);
	i = 0;
	while (s[i++])
		if (s[i] == c)
			count++;
	split = malloc(sizeof(char*) * (count + 2));
	i = 0;
	k = i;
	while (s[i])
	{
		j = i;
		while (s[i] && s[i] != c)
			i++;
		split[k] = mydup(s[j], i- j);
		k++;
	}
	split[k] = NULL;
	return (split);	
}
