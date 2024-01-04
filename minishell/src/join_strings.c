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

void	join_string(token **token_list)
{
	token	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (tmp->type == T_S_QUOTE || tmp->type == T_D_QUOTE)
		{
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
}
