/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:46:14 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/02 10:20:15 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

extern int	g_status;

void	handle_envp_var(char **str, char **envp, int flag)
{
	int		i;
	char	*var;

	i = -1;
	while ((*str) && (*str)[++i])
	{
		var = NULL;
		if (ft_strnstr(&(*str)[i], "$?", 2))
			*str = transform_value(*str, &i, envp, ft_itoa((int)g_status));
		else if ((*str)[i] == '$' && is_envp((*str) + i, envp, &var))
			*str = transform_value(*str, &i, envp, var);
		else if ((*str)[i] == '$' && !is_envp((*str) + i, envp, &var)
			&& ft_isalpha((*str)[i + 1]))
			*str = transform_value(*str, &i, envp, var);
		else if ((*str)[i] == '\\' && flag)
			if ((*str)[i + 1])
				if ((*str)[i + 1] == '\\'
					|| (*str)[i + 1] == '$'
					|| (*str)[i + 1] == '\"')
					*str = del_backslash(*str, i);
		free(var);
	}
}

void	add_envp_var(t_oken **t_argv, char **envp)
{
	t_oken	*node;

	node = *t_argv;
	while (node)
	{
		if (node->type == T_WORD && !node->s_quote_flag)
			handle_envp_var(&node->value, envp, node->d_quote_flag);
		node = node->next;
	}
	g_status = 0;
}
