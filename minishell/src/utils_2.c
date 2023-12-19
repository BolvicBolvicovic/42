/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:47:06 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/19 16:56:37 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_one_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			return (1);
	return (0);
}

int	no_quote(char *str)
{
	while (str++)
		if (*str == '\'' || *str == '\"')
			return (0);
	return (1);
}

void	update_token_flags(token *list)
{
	int	space;
	int	no_q;
	int	i;
	token	*tmp;

	space = 0;
	i = -1;
	tmp = list;
	tmp->f_space = is_one_space(tmp->value);
	no_q = !(tmp->s_quote_f && tmp->d_quote_f);
	if (!tmp->f_space && no_q)
		add_command_token(tmp);
	if (no_q)
		add_operator_token(tmp);
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
