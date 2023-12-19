/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:10 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/19 15:04:16 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	only_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ' || !(str[i] >= '\r' && str[i] <= '\t'))
			return (0);
	return (1);
}

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
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	return (!str[i]);
}

char	*del_spaces(char *str)
{
	int		len;
	int		i;
	char	*tmp;

	len = -1;
	while (str[++len])
		continue ;
	tmp = ft_calloc(1, len + 1);
	i = -1;
	while (++i < len)
		tmp[i] = str[i];
	tmp[i] = '\0';
	free(str);
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
	else
		node->type = T_ERROR;
}
