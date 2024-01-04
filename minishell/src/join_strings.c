#include "mini.h"

void	join_token(token *node, token *next_node)
{
	if (*next_node->value)
		node->value = ft_strjoin(node->value, next_node->value);
	else
		node->value = ft_strjoin(node->value, " ");
	node->type = T_WORD;
	node->next = next_node->next;
	free(next_node->value);
	free(next_node->path);
	free(next_node);
}

void	destroy_token(token *previous_node, token *node_to_destroy)
{
	previous_node->next = node_to_destroy->next;
	free(node_to_destroy->value);
	free(node_to_destroy->path);
	free(node_to_destroy);
}

void	join_string(token **token_list)
{
	token	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (tmp->type == T_S_QUOTE || tmp->type == T_D_QUOTE)
		{
			if (tmp->type == T_S_QUOTE)
				tmp->next->s_quote_flag = 1;
			tmp = tmp->next;
			while (tmp->next && (tmp->next->type != T_S_QUOTE && tmp->next->type != T_D_QUOTE))
				join_token(tmp, tmp->next);
			if (!tmp->next)
			{
				tmp->type = T_ERROR;
				break ;
			}
			tmp = tmp->next;
		}
		if (!tmp)
			break ;
		tmp = tmp->next;
	}
	tmp = *token_list;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->next->type == T_S_QUOTE || tmp->next->type == T_D_QUOTE)
				destroy_token(tmp, tmp->next);
		tmp = tmp->next;
	}
}
