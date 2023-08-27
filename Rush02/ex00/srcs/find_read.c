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

void	bignum(char **dict, int counter_rows, int max, int i)
{
	char	num[15];
	int		o;
	int		j;

	o = 0;
	j = 1;
	while (++o <= max - i)
	{
		num[0] = '1';
		num[j++] = '0';
		num[j++] = '0';
		num[j++] = '0';
		num[j] = '\0';
	}
	if (i != max)
	{
		read_words(ft_strstr(dict, counter_rows, num));
		write(1, " ", 1);
	}
}

char	*ft_strstr(char **dict, int arr_len, char *to_find)
{
	int	str_i;
	int	find_i;
	int	i;
	int	bool1;
	int	bool2;

	str_i = -1;
	i = 0;
	find_i = 0;
	while (++str_i < arr_len)
	{
		while (to_find[find_i] && (to_find[find_i] == dict[str_i][i]))
		{
			find_i++;
			i++;
			if (to_find[find_i] == '\0')
				return (dict[str_i]);
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

	i = 0;
	if (!str[0])
		return (0);
	while (str[i] != ':')
		i++;
	while (str[++i] && (str[i] == ' ' || str[i] == '\t'))
		continue ;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
			word_started = 1;
		}
		else if (word_started)
		{
			write(1, " ", 1);
			word_started = 0;
		}
		i++;
	}
	return (0);
}
