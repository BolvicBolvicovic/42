/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:49 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/10 17:23:32 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	main(int argc, char **argv, char **envp)
{
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
			join_string(&t_argv);
			add_envp_var(&t_argv, envp);
			while (t_argv)
			{
				printf("Value: %s Token: %d\n", t_argv->value, t_argv->type);
				free(t_argv->value);
				free(t_argv->path);
				t_argv = t_argv->next;
			}
		}
		free(t_argv);
		if (input)
			free(input);
		else
			break ;
	}
	return (0);
}
