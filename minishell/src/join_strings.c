#include "mini.h"

void	join_token(token *node, token *next_node)
{
	if (*next_node->value)
		node->value = ft_strjoin(node->value, next_node->value);
	node->type = T_WORD;
	node->next = next_node->next;
	free(next_node->value);
	free(next_node->path);
	free(next_node);
}

void	destroy_token(token *previous_node, token *node_to_destroy)
{
	if (previous_node)
		previous_node->next = node_to_destroy->next;
	free(node_to_destroy->value);
	free(node_to_destroy->path);
	free(node_to_destroy);
}

void	del_t_type(token **token_list, token_type type1, token_type type2)
{
	token	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->next->type == type1 || tmp->next->type == type2)
				destroy_token(tmp, tmp->next);
			else
				tmp = tmp->next;
		else
			break ;
	}
}

void	handle_spaces(token **token_list)
{
	token	*tmp;

	tmp = *token_list;
	while (tmp->next)
	{
		if (tmp->type == T_WORD && tmp->next->type == T_WORD)
			join_token(tmp, tmp->next);
		else
			tmp = tmp->next;
	}
}

int	str_ended_backslash(token *node)
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

void	join_string(token **token_list)
{
	token	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (tmp->next && ((tmp->type == T_S_QUOTE && tmp->next->type != T_S_QUOTE)
			|| (tmp->type == T_D_QUOTE && tmp->next->type != T_D_QUOTE)))
		{
			if (tmp->type == T_S_QUOTE)
				tmp->next->s_quote_flag = 1;
			else if (tmp->type == T_D_QUOTE)
				tmp->next->d_quote_flag = 1;
			tmp = tmp->next;
			while (tmp->next && str_ended_backslash(tmp))
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
	del_t_type(token_list, T_D_QUOTE, T_S_QUOTE);
	handle_spaces(token_list);
	del_t_type(token_list, T_D_QUOTE, T_SPACE);
}
