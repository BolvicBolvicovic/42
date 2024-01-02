/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_missing_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:47:06 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/02 14:32:00 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"


void	add_quote_flags(token **t_argv)
{
	token	*tmp;
	int	d_quote_flag;
	int	s_quote_flag;

	tmp = *t_argv;
	d_quote_flag = 0;
	s_quote_flag = 0;
	while (tmp)
	{
		if (!s_quote_flag && ft_strcmp(tmp->value, "\"") == 0)
		{
			tmp->type = T_D_QUOTE;
			if (d_quote_flag == 0)
				d_quote_flag = 1;
			else
				d_quote_flag = 0;
		}
		if (!d_quote_flag && ft_strcmp(tmp->value, "\'") == 0)
		{
			tmp->type = T_S_QUOTE;
			if (s_quote_flag == 0)
				s_quote_flag = 1;
			else
				s_quote_flag = 0;
		}
		tmp = tmp->next;
	}
}

void	add_flags(token **t_argv)
{
	token	*tmp;
	int	cmd_flag;
	int	quote_flag;

	tmp = *t_argv;
	cmd_flag = 0;
	quote_flag = 0;
	add_quote_flags(t_argv);
	while (tmp)
	{
		if (tmp->type == T_D_QUOTE || tmp->type == T_S_QUOTE)
			quote_flag = !quote_flag;
		if (only_space(tmp->value))
			tmp->type = T_SPACE;
		else if (!cmd_flag && tmp->type == T_CMD)
			cmd_flag = 1;
		else if ((cmd_flag && tmp->type == T_CMD) 
			|| (quote_flag && !(tmp->type == T_D_QUOTE || tmp->type == T_S_QUOTE)))
			tmp->type = T_WORD;
		else if (tmp->type >= T_PIPE && tmp->type <= T_HEREDOC)
			cmd_flag = 0;
		tmp = tmp->next;
	}
}
