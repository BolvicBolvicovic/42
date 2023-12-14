/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:36:52 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/14 18:26:20 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	space(char *input, int i)
{

}

void	add_space(char *input, int *i)
{
	int	j;
	
	j = *i;
	if (j > 0 && !is_white_space(input[j - 1]))
		space(input, j - 1);
	if (input[j + 1] && !is_white_space(input[j + 1]))
		space(input, j + 1);
}

char	*add_spaces(char *input)
{
	int	i;

	while (1)
	{
		i = -1;
		while (input[++i])
		{
			if (input[i] == '|' || input[i] == '<' || input[i] == '>')
				add_space(input, i);
			else if (input[i] == ''' || input[i] == '"')
				handle_quotes(input, &i);
		}
		if (clear_input(input))
			break ;
	}
	return (input);
}

int	find_type(char *str)
{
	if (ft_memcmp(str, "<", 1) == 0)
		return (T_REDIRECT_IN);
	else if (ft_memcmp(str, ">", 1) == 0)
		return (T_REDIRECT_OUT);
	else if (ft_memcmp(str, "|", 1) == 0)
		return (T_PIPE);
	else
		return (T_WORD);
}
