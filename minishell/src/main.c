/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:49 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/11 17:36:06 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	check_redirect(token **token_list)
{
	token	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (tmp->value[0] == '<' 
			&& !(!tmp->value[1] || (tmp->value[1] == '<' && !tmp->value[2])))
			tmp->type = T_ERROR;
		if (tmp->value[0] == '>' 
			&& !(!tmp->value[1] || (tmp->value[1] == '>' && !tmp->value[2])))
			tmp->type = T_ERROR;
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	token	*tmp;
	token	*t_argv;
	char	*input;

	(void)argc;
	(void)argv;
	printf("\033c");
	printf("\033]0;MiniFeur\a");
	while (1)
	{
		t_argv = NULL;
		input = readline("➜ MiniFeur$ ");
		if (input && ft_strlen(input) > 0)
		{
			if (ft_strcmp(input, "e") == 0)
			{
				free(input);
				break ;
			}
			t_argv = tokenize(input, envp);
			add_flags(&t_argv);
			check_redirect(&t_argv);
			join_string(&t_argv);
			add_envp_var(&t_argv, envp);
			if (t_argv->type == T_S_QUOTE
				|| t_argv->type == T_D_QUOTE || t_argv->type == T_SPACE)
			{
				tmp = t_argv->next;
				free(t_argv->value);
				free(t_argv->path);
				free(t_argv);
				t_argv = tmp;
			}
			while (t_argv)
			{
				tmp = t_argv->next;
				printf("Value: %s Token Type: %d\n", t_argv->value, t_argv->type);
				free(t_argv->value);
				free(t_argv->path);
				free(t_argv);
				t_argv = tmp;
			}
		}
		if (input)
			free(input);
		else
			break ;
	}
	return (0);
}
