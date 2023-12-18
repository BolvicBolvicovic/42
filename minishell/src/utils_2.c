/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:47:06 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/15 12:10:45 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
void	handle_quotes(char *input, int *i)
{
	(void)input;
	(void)i;
}

int	clear_input(char *input)
{
	int	i;
	
	i = -1;
	while (input[++i])
	{
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			if ((input[i + 1] && !is_white_space(input[i + 1]))
				|| (i > 0 && !is_white_space(input[i - 1])))
				return (0);
	}
	return (1);
}
