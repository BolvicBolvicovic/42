/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:03:42 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/13 17:04:13 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	i = 0;
	src_len = 0;
	dest_len = 0;
	while (dest[dest_len])
	{
		dest_len++;
		dest++;
	}
	while (src[src_len])
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	while (*src && i + dest_len < size - 1)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	dest[i + dest_len] = '\0';
	return (src_len + dest_len);
}
