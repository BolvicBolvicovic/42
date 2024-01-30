/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:55:59 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/12 12:56:03 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	copy_len;
	unsigned int	i;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	if (src_len > size - 1)
		copy_len = size - 1;
	else
		copy_len = src_len;
	while (i < copy_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[copy_len] = '\0';
	return (src_len);
}
