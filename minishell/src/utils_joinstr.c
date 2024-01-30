/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_joinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:41:26 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/30 20:13:28 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	join_token(t_oken *node, t_oken *next_node)
{
	if (*next_node->value)
		node->value = ft_strjoin(node->value, next_node->value);
	if (node->type != T_DIR_OR_FILE && node->next->type != T_DIR_OR_FILE)
		node->type = T_WORD;
	else
		node->type = T_DIR_OR_FILE;
	node->next = next_node->next;
	free(next_node->value);
	free(next_node->path);
	free(next_node);
}

void	destroy_token(t_oken *previous_node, t_oken *node_to_destroy)
{
	if (previous_node)
		previous_node->next = node_to_destroy->next;
	free(node_to_destroy->value);
	free(node_to_destroy->path);
	free(node_to_destroy);
}

void	del_t_type(t_oken **token_list, t_oken_type type1, t_oken_type type2)
{
	t_oken	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->next->type == type1 || tmp->next->type == type2)
				destroy_token(tmp, tmp->next);
			else
				tmp = tmp->next;
		}
		else
			break ;
	}
}

void	handle_spaces(t_oken **token_list)
{
	t_oken	*tmp;

	tmp = *token_list;
	while (tmp->next)
	{
		if (tmp->type >= T_WORD && tmp->type <= T_CMD
			&& tmp->next->type >= T_WORD && tmp->next->type <= T_CMD)
			join_token(tmp, tmp->next);
		else
			tmp = tmp->next;
	}
}

int	str_ended_backslash(t_oken *node)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen(node->value);
	if (node->value[len - i] == '\\')
		while (len - i >= 0 && node->value[len - i] == '\\')
			i++;
	return ((node->next->type != T_S_QUOTE && node->next->type != T_D_QUOTE)
		|| ((i - 1) % 2));
}
