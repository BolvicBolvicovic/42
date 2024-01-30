/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:10:22 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/10 16:10:24 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0') 
	{
		length++;
		str++;
	}
	str = str - length;
	return (length);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
