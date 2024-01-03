/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:49 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/03 15:16:35 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	main(void)
{
	token	*t_argv;
	char	*input;

	printf("\033c");
	printf("\033]0;MiniFeur\a");
//	printf("\x1b[2J");
//	printf("\x1b[H");
	while (1)
	{
		t_argv = NULL;
		input = readline("➜ MiniFeur$ ");
		if (ft_strlen(input) > 0)
		{
			t_argv = tokenize(input);
			add_flags(&t_argv);
			while (t_argv)
			{
				printf("Value: %s Token: %d\n", t_argv->value, t_argv->type);
				free(t_argv->value);
				t_argv = t_argv->next;
			}
		}
		free(t_argv);
		free(input);
	}
	return (0);
}
