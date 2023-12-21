/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:13:47 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/20 13:14:03 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

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

token	*tokenize(char *argv)
{
	int		quote;
	int		i;
	int		j;
	token	*token_list;
	
	i = 0;
	quote = 0;
	token_list = NULL;
	while (argv[i])
	{
		j = i;
		while (argv[i] && is_str(argv[i], "<>|\'\" "))
			i++;
		if (i != j)
			add_token(&token_list, i + 1, j, argv);
		j = i;
		while (argv[i] && !is_str(argv[i], "\'\""))
			i++;
		if (argv[j] && i != j)
			add_token(&token_list, i + 1, j, argv);
		j = i;
		while (argv[i] && !is_str(argv[i], "<>| "))
                        i++;
                if (argv[j] && i != j)
			add_token(&token_list, i + 1, j, argv);
	}
	return (token_list);
}
