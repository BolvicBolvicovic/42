/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:21:17 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/27 12:31:47 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ourlib.h"

char	*ft_strstr(char **str_array, int arr_len, char *to_find)
{
	int	str_i;
	int	find_i;
	int	i;

	str_i = -1;
	i = 0;
	find_i = 0;
	while (++str_i < arr_len)
	{
		while (to_find[find_i] && (to_find[find_i] == str_array[str_i][i]))
		{
			find_i++;
			i++;
			if (str_array[str_i][i] == ':' && to_find[find_i] == '\0')
				return (str_array[str_i]);
		}
		find_i = 0;
		i = 0;
	}
	return (0);
}

int	read_words(char *str)
{
	unsigned int	i;
	unsigned int	word_started;
	unsigned int	min;
	unsigned int	maj;

	i = -1;
	word_started = 0;
	if (!str[0])
		return (0);
	while (str[++i])
	{
		min = str[i] >= 'a' && str[i] <= 'z';
		maj = str[i] >= 'A' && str[i] <= 'Z';
		if (min || maj)
		{
			write(1, &str[i], 1);
			word_started = 1;
		}
		else if (word_started)
		{
			write(1, " ", 1);
			word_started = 0;
		}
	}
	return (0);
}
