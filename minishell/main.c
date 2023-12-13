/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:49 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/13 18:39:42 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	size_of_av(char	**argv)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (argv[++i])
		size += ft_strlen(argv[i]);
	return (size);
}

token	*tokenize(const char **argv)
{
	char	*j_av;
	char	**av;
	int		size;
	int		num_of_words;
	int		i;
	token	*array;
	
	size = size_of_av(argv);
	j_av = ft_join(size, argv, " ");
	num_of_words = ft_count_words(j_av, ' ');
	array = malloc(sizeof(token * num_of_words + 1));
	av = ft_split(j_av);
	free(j_av);
	i = -1;
	while (av[++i])
	{
		array->type = find_type(av[i]);
		array->value = av[i];
	}
	return (array);
}

int	main(int argc, char **argv)
{
	Token	*t_argv;

	t_argv = tokenize(argv);
	free(t_argv);
	return (0);
}
