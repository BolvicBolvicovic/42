/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:44:32 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/29 18:59:19 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_oken	*copy_token_list(t_oken *lst)
{
	t_oken	*tmp;
	t_oken	*head;

	head = ft_calloc(1, sizeof(t_oken));
	tmp = head;
	while (lst)
	{
		tmp->value = ft_strdup(lst->value);
		tmp->type = lst->type;
		tmp->path = NULL;
		if (lst->next)
			tmp->next = ft_calloc(1, sizeof(t_oken));
		else
			tmp->next = NULL;
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}

void	token_addback(t_oken **list, t_oken *node)
{
	t_oken	*tmp;

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

void	add_token(t_oken **list, int i, int j, char *str)
{
	t_oken	*new_node;
	int		k;

	k = -1;
	new_node = ft_calloc(sizeof(t_oken), 1);
	new_node->next = NULL;
	new_node->type = T_WORD;
	new_node->s_quote_flag = 0;
	new_node->d_quote_flag = 0;
	new_node->value = ft_calloc(1, i - j);
	while (j < i)
		new_node->value[++k] = str[j++];
	new_node->value[k] = '\0';
	token_addback(list, new_node);
}

char	*get_path(char **envp)
{
	int		i;
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

t_oken	*add_path(t_oken *list, char **envp)
{
	t_oken	*tmp;

	tmp = list;
	while (list)
	{
		list->path = get_path(envp);
		update_token_flags(list);
		list = list->next;
	}
	return (tmp);
}
