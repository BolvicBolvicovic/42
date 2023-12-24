/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:47:06 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/19 16:56:37 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	add_flags(token **t_argv)
{
	token	*tmp;
	int	cmd_flag;

	tmp = *t_argv;
	cmd_flag = 0;
	while (tmp)
	{
		if (only_space(tmp->value))
			tmp->type = T_SPACE;
		else if (!cmd_flag && tmp->type == T_CMD)
			cmd_flag = 1;
		else if (cmd_flag && tmp->type == T_CMD)
			tmp->type = T_WORD;
		else if (tmp->type >= T_PIPE && tmp->type <= T_HEREDOC)
			cmd_flag = 0;
		tmp = tmp->next;
	}
}
