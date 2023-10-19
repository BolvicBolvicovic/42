/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:57:55 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 11:36:20 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(void *s, int c, int n)
{
	unsigned char	*ss;
	unsigned char	cc;

	cc = c;
	ss = s;
	while (*ss && n && *ss != cc)
	{
		n--;
		ss++;
	}
	if (!n || !*ss)
		return (0);
	return ((void *)ss);
}
