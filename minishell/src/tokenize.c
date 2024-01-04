/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:13:47 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/02 14:09:31 by vcornill         ###   ########.fr       */
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
	new_node->s_quote_flag = 0;
	new_node->value = ft_calloc(1, i - j);
	while (j < i)
		new_node->value[++k] = str[j++];
	new_node->value[k] = '\0';
	token_addback(list, new_node);
}

char	*get_path(char **envp)
{
	int	i;
	char	*path;

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i]);
			break ;
		}
	}
	return (path);
}

void	add_path(token *list, char **envp)
{
	while (list)
	{
		list->path = get_path(envp);
		update_token_flags(list);
		list = list->next;
	}
}

token	*tokenize(char *argv, char **envp)
{
	int		i;
	int		j;
	token	*token_list;
	
	i = 0;
	token_list = NULL;
	while (argv[i])
	{
		j = i;
		while (argv[i] && is_str(argv[i], "<>|\'\" "))
			i++;
		if (i != j)
			add_token(&token_list, i + 1, j, argv);
		j = i;
		if (argv[i] && !is_str(argv[i], "\""))
			i++;
		if (argv[j] && i != j)
			add_token(&token_list, i + 1, j, argv);
		j = i;
		if (argv[i] && !is_str(argv[i], "\'"))
			i++;
		if (argv[j] && i != j)
			add_token(&token_list, i + 1, j, argv);
		j = i;
		while (argv[i] && !is_str(argv[i], "<>| "))
                        i++;
                if (argv[j] && i != j)
			add_token(&token_list, i + 1, j, argv);
	}
	add_path(token_list, envp);
	return (token_list);
}
