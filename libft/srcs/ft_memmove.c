/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:02:11 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/16 18:02:14 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	overlap(void *dest, const void *src, int n)
{
	int		overlapping;
	void	*src_end;

	src_end = src + n;
	overlapping = 0;
	if (dest >= src && dest < src_end)
		overlapping = 1;
	return (overlapping);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	if (!dest && !src)
		return (dest);
	if (overlap(dest, src, n))
		while (--n > 0)
			dest[n] = src[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
