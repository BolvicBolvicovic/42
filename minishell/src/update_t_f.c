/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_t_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:10 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/30 19:20:49 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	add_command_token(t_oken *node)
{
	if (ft_strcmp(node->value, "echo") == 0
		|| ft_strcmp(node->value, "cd") == 0
		|| ft_strcmp(node->value, "pwd") == 0
		|| ft_strcmp(node->value, "export") == 0
		|| ft_strcmp(node->value, "unset") == 0
		|| ft_strcmp(node->value, "env") == 0
		|| ft_strcmp(node->value, "exit") == 0)
		node->type = T_CMD;
	else
		exec_command_flag(node, node->path);
}

void	add_operator_token(t_oken *node)
{
	if (only_space(node))
		return ;
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

void	update_token_flags(t_oken *list)
{
	t_oken	*tmp;

	tmp = list;
	tmp->f_space = is_one_space(tmp->value);
	add_command_token(tmp);
	add_operator_token(tmp);
}
