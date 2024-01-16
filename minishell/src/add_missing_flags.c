/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_missing_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:47:06 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/16 15:53:49 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	if_statement_quote_f(int *quote_1, int *quote_2, t_oken *tmp, char *cmp)
{
	if (!*quote_1 && ft_strcmp(tmp->value, cmp) == 0)
	{
		if (*quote_2 == 0)
			*quote_2 = 1;
		else
			*quote_2 = 0;
		return (1);
	}
	return (0);
}

void	add_quote_flags(t_oken **t_argv)
{
	t_oken	*tmp;
	int		d_quote_flag;
	int		s_quote_flag;

	tmp = *t_argv;
	d_quote_flag = 0;
	s_quote_flag = 0;
	while (tmp)
	{
		if (if_statement_quote_f(&s_quote_flag, &d_quote_flag, tmp, "\""))
			tmp->type = T_D_QUOTE;
		if (if_statement_quote_f(&d_quote_flag, &s_quote_flag, tmp, "\'"))
			tmp->type = T_S_QUOTE;
		tmp = tmp->next;
	}
}

void	add_flags(t_oken **t_argv)
{
	t_oken	*tmp;
	int		cmd_flag;
	int		quote_flag;

	tmp = *t_argv;
	cmd_flag = 0;
	quote_flag = 0;
	add_quote_flags(t_argv);
	while (tmp)
	{
		if (tmp->type == T_D_QUOTE || tmp->type == T_S_QUOTE)
			quote_flag = !quote_flag;
		else if (!cmd_flag && (tmp->type == T_CMD || tmp->type == T_CMD_ENVP))
			cmd_flag = 1;
		else if ((cmd_flag && (tmp->type == T_CMD || tmp->type == T_CMD_ENVP))
			|| (quote_flag
				&& !(tmp->type == T_D_QUOTE || tmp->type == T_S_QUOTE)))
			tmp->type = T_WORD;
		else if (tmp->type >= T_PIPE && tmp->type <= T_HEREDOC)
			cmd_flag = 0;
		tmp = tmp->next;
	}
}
