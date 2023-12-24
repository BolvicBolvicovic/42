/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:10 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/19 17:51:04 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	add_command_token(token *node)
{
	if (ft_strcmp(node->value, "echo") == 0
		|| ft_strcmp(node->value, "cd") == 0
		|| ft_strcmp(node->value, "pwd") == 0
		|| ft_strcmp(node->value, "export") == 0
		|| ft_strcmp(node->value, "unset") == 0
		|| ft_strcmp(node->value, "env") == 0
		|| ft_strcmp(node->value, "exit") == 0)
		node->type = T_CMD;
}

int	str_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	return (str[i]);
}

char	*del_spaces(char *str)
{
	int		start;
	int		end;
	char	*tmp;
	
	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] == ' ')
		start++;
	while (end > start && str[end] == ' ')
		end--;
	tmp = ft_calloc(1, end - start + 2);
	ft_strlcpy(tmp, str + start, end - start + 2);
	tmp[end - start + 1] = '\0';
	return (tmp);
}

void	add_operator_token(token *node)
{
	if (only_space(node->value))
		return ;
	if (str_error(node->value))
	{
		node->type = T_ERROR;
		return ;
	}
	node->value = del_spaces(node->value);
	if (ft_strcmp(node->value, "<<") == 0)
		node->type = T_HEREDOC;
	else if (ft_strcmp(node->value, "<") == 0)
		node->type = T_REDIRECT_IN;
	else if (ft_strcmp(node->value, ">>") == 0)
		node->type = T_APPEND;
	else if (ft_strcmp(node->value, ">") == 0)
		node->type = T_REDIRECT_OUT;
	else if (ft_strcmp(node->value, "|") == 0)
		node->type = T_PIPE;
}

void	update_token_flags(token *list)
{
	token	*tmp;

	tmp = list;
	tmp->f_space = is_one_space(tmp->value);
	if (!tmp->f_space)
		add_command_token(tmp);
	else
		add_operator_token(tmp);
}
