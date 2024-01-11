/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:13:47 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/11 16:20:22 by vcornill         ###   ########.fr       */
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
	path = NULL;
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

token	*add_path(token *list, char **envp)
{
	token *tmp;

	tmp = list;
	while (list)
	{
		list->path = get_path(envp);
		update_token_flags(list);
		list = list->next;
	}
	return (tmp);
}

int	if_statment_tokenize(int *i, int *j, char *argv, char *dif)
{
	*j = *i;
	if (argv[*i] && !is_str(argv[*i], dif))
		*i += 1;
	return (argv[*j] && *i != *j);
}

int	while_statment_tokenize(int *i, int *j, char *argv, char *dif)
{
	*j = *i;
	while (argv[*i] && is_str(argv[*i], dif))
		*i = *i + 1;
	return (*i != *j);
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
		if (while_statment_tokenize(&i, &j, argv, "<>|\'\" \t\n\v\f\r"))
			add_token(&token_list, i + 1, j, argv);
		if (if_statment_tokenize(&i, &j, argv, "\""))
			add_token(&token_list, i + 1, j, argv);
		if (if_statment_tokenize(&i, &j, argv, "\'"))
			add_token(&token_list, i + 1, j, argv);
		if (if_statment_tokenize(&i, &j, argv, "|"))
			add_token(&token_list, i + 1, j, argv);
		j = i;
		while (argv[i] && !is_str(argv[i], "<>\t\n\v\f\r "))
                        i++;
                if (argv[j] && i != j)
			add_token(&token_list, i + 1, j, argv);
	}
	return (add_path(token_list, envp));
}
