/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:36:52 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/18 17:33:58 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	space(char **input, int i)
{
	int		j;
	char	*tmp;

	tmp = ft_calloc(1, ft_strlen(*input) + 1);
	j = -1;
	while (++j != i)
		tmp[j] = (*input)[j];
	tmp[j] = ' ';
	while ((*input)[i])
		tmp[++j] = (*input)[i++];
	tmp[++j] = '\0';
	*input = tmp;
}

void	add_space(char **input, int *i)
{
	int	j;
	
	j = *i;
	if (ft_memcmp((*input) + *i, "<<", 2) == 0 || ft_memcmp((*input) + *i, ">>", 2) == 0)
		j += 2;
	if (j > 0 && !is_white_space((*input)[j - 1]))
	{
		space(input, j);
		*i += 1;
	}
	if ((*input)[j + 1] && !is_white_space((*input)[j + 1]))
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
			if (ft_memcmp(&input[i], "<<", 2) == 0 || ft_memcmp(&input[i], ">>", 2) == 0)
			{
				add_space(&input, &i);
				i++;
			}
			else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
				add_space(&input, &i);
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
	else if (ft_memcmp(str, "<<", 2) == 0)
		return (T_HEREDOC);
	else if (ft_memcmp(str, ">>", 2) == 0)
		return (T_APPEND);
	return (T_WORD);
}
