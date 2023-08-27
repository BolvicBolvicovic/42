/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:27:15 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/27 13:19:43 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ourlib.h"

void	algosheart(char *digits, char **dictionary, int counter_rows)
{
	int		j;

	j = -1;
	while (++j < 3)
	{
		if (digits[j] != '0')
		{
			if (j == 0)
				first_digit(dictionary, digits[j], counter_rows);
			if (j == 1)
				second_digit(dictionary, digits, counter_rows);
			if (j == 2 && digits[1] != '1')
				third_digit(dictionary, digits[j], counter_rows);
		}
	}
}

int	algo(char *dictionary, char *num)
{
	char	**arr_nums;
	char	**dict;
	int		counter_rows;
	int		i;

	i = 0;
	arr_nums = allocnum(num);
	dict = copy_dict(dictionary);
	counter_rows = count_rows(read_dict(dictionary));
	if (arr_nums[0][0] == '0' && arr_nums[0][1] == '0' && arr_nums[0][2] == '0')
	{
		read_words(ft_strstr(dict, counter_rows, "0"));
		return (0);
	}
	while (i < (ft_strlen(num) / 3 + modthree(num)))
	{
		algosheart(arr_nums[i], dict, counter_rows);
		if (ft_strcmp(arr_nums[i++], "000") != 0)
			bignum(dict, counter_rows, ft_strlen(num) / 3 + modthree(num), i);
	}
	free(arr_nums);
	free(dict);
	return (0);
}
