/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:06:09 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 15:14:17 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	unsigned int	slen;

	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	substring = malloc(len + 1);
	if (!substring)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
