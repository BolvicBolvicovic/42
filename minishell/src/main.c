/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:49 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/14 17:44:39 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

token	*tokenize(char *argv)
{
	char	**av;
	int		num_of_words;
	int		i;
	token	*array;
	
	num_of_words = ft_count_words(argv, ' ');
	array = malloc(sizeof(token) * (num_of_words + 1));
	av = ft_split(argv, ' ');
	i = -1;
	while (av[++i])
	{
		array[i].type = find_type(av[i]);
		array[i].value = av[i];
	}
	array[i].value = NULL;
	return (array);
}

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
			input = add_spaces(input);
			t_argv = tokenize(input);
			while (t_argv[++i].value)
			{
				printf("Value: %s Token: %d\n", t_argv[i].value, t_argv[i].type);
				free(t_argv[i].value);
			}
		}
		free(t_argv);
		free(input);
	}
	return (0);
}
