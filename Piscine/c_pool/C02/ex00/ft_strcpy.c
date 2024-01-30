/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:58:21 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/11 10:44:55 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	fou;

	fou = 0;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		fou++;
	}
	*dest = '\0';
	src = src - fou;
	dest = dest - fou;
	return (dest);
}
