/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:49 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/20 13:05:42 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	main(void)
{
	token	*t_argv;
	int		i;
	char	*input;

	while (1)
	{
		i = -1;
		t_argv = NULL;
		input = readline("minishell$ ");
		if (ft_strlen(input) > 0)
		{
			t_argv = tokenize(input);
			//add_flags(t_argv);
			while (t_argv)
			{
				printf("Value: %s Token: %d", t_argv->value, t_argv->type);
				free(t_argv->value);
				t_argv = t_argv->next;
			}
		}
		free(t_argv);
		free(input);
	}
	return (0);
}
