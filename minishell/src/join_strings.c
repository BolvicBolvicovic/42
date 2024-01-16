/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:32:58 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/16 17:44:02 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	insert_empty_str(t_oken **node)
{
	t_oken	*empty_str;

	empty_str = ft_calloc(sizeof(t_oken), 1);
	empty_str->type = T_WORD;
	empty_str->value = ft_calloc(1, 1);
	empty_str->value[0] = '\0';
	empty_str->next = (*node)->next;
	(*node)->next = empty_str;
	*node = (*node)->next;
}

void	if_statement_joinstr(t_oken **tmp)
{
	if ((*tmp)->next && (((*tmp)->type == T_S_QUOTE
				&& (*tmp)->next->type != T_S_QUOTE)
			|| ((*tmp)->type == T_D_QUOTE && (*tmp)->next->type != T_D_QUOTE)))
	{
		if ((*tmp)->type == T_S_QUOTE)
			(*tmp)->next->s_quote_flag = 1;
		else if ((*tmp)->type == T_D_QUOTE)
			(*tmp)->next->d_quote_flag = 1;
		*tmp = (*tmp)->next;
		while ((*tmp)->next && str_ended_backslash(*tmp))
			join_token(*tmp, (*tmp)->next);
	}
	else if ((*tmp)->next && (((*tmp)->type == T_S_QUOTE
				&& (*tmp)->next->type == T_S_QUOTE)
			|| ((*tmp)->type == T_D_QUOTE && (*tmp)->next->type == T_D_QUOTE)))
		insert_empty_str(tmp);
}

void	join_string(t_oken **token_list)
{
	t_oken	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if_statement_joinstr(&tmp);
		tmp = tmp->next;
		if (!tmp)
			break ;
		tmp = tmp->next;
	}
	del_t_type(token_list, T_D_QUOTE, T_S_QUOTE);
	handle_spaces(token_list);
	del_t_type(token_list, T_D_QUOTE, T_SPACE);
}
