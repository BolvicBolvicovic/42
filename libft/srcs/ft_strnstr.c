/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:12:55 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 11:36:46 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (!little)
		return (big);
	while (big[i++] && len)
	{
		j = 0;
		while (little[j] && big[j + i])
		{
			if (little[j] != big[j + i])
				break ;
			j++;
		}
		if (little[j] - big[j + i] == 0)
			return (big + j + i);
		len--;
	}
	return (0);
}
