/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deck <deck@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:32:58 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/03 14:42:28 by deck             ###   ########.fr       */
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
	*node = (*node)->next->next->next;
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
		*tmp = (*tmp)->next;
	}
	else if ((*tmp)->next && (((*tmp)->type == T_S_QUOTE
				&& (*tmp)->next->type == T_S_QUOTE)
			|| ((*tmp)->type == T_D_QUOTE && (*tmp)->next->type == T_D_QUOTE)))
		insert_empty_str(tmp);
}

void	join_string(t_oken **token_list, char **envp)
{
	t_oken	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if_statement_joinstr(&tmp);
		if (tmp)
			tmp = tmp->next;
	}
	add_envp_var(token_list, envp);
	del_t_type(token_list, T_D_QUOTE, T_S_QUOTE);
	handle_spaces(token_list);
	tmp = *token_list;
	while (tmp)
	{
		if (!tmp->value[0])
			tmp->type = T_SPACE;
		tmp = tmp->next;
	}
	del_t_type(token_list, T_SPACE, T_SPACE);
}
