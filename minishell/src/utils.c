/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:36:52 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/19 17:03:02 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_str(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (0);
	return (1);
}

void	token_addback(token **list, token *node)
{
	token	*tmp;

	tmp = *list;
	if (!*list)
		*list = node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void	add_token(token **list, int i, int j, char *str)
{
	token	*new_node;
	int		k;

	k = -1;
	new_node = ft_calloc(sizeof(token), 1);
	new_node->next = NULL;
	new_node->value = ft_calloc(1, i - j);
	while (j < i)
		new_node->value[++k] = str[j++];
	new_node->value[k] = '\0';
	token_addback(list, new_node);
	update_token_flags(new_node);
}

void	add_quote_flag(token *list, int t_flag, int quote)
{
	while (list->next)
		list = list->next;
	list->type = t_flag;
	list->s_quote_f = (quote & S_QUOTE);
	list->d_quote_f = (quote & D_QUOTE);
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
