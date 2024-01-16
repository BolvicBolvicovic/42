/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:13:47 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/16 15:54:48 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	if_statment_tokenize(int *i, int *j, char *argv, char *dif)
{
	*j = *i;
	if (argv[*i] && !is_str(argv[*i], dif))
		*i += 1;
	return (argv[*j] && *i != *j);
}

int	while_statment_tokenize(int *i, int *j, char *argv, char *dif)
{
	*j = *i;
	while (argv[*i] && is_str(argv[*i], dif))
		*i = *i + 1;
	return (*i != *j);
}

int	while_statment_tokenize2(int *i, int *j, char *argv, char *dif)
{
	*j = *i;
	while (argv[*i] && !is_str(argv[*i], dif))
		*i = *i + 1;
	return (argv[*j] && *i != *j);
}

t_oken	*tokenize(char *argv, char **envp)
{
	int		i;
	int		j;
	t_oken	*token_list;

	i = 0;
	token_list = NULL;
	while (argv[i])
	{
		if (while_statment_tokenize(&i, &j, argv, "<>|\'\" \t\n\v\f\r"))
			add_token(&token_list, i + 1, j, argv);
		if (if_statment_tokenize(&i, &j, argv, "\""))
			add_token(&token_list, i + 1, j, argv);
		if (if_statment_tokenize(&i, &j, argv, "\'"))
			add_token(&token_list, i + 1, j, argv);
		if (if_statment_tokenize(&i, &j, argv, "|"))
			add_token(&token_list, i + 1, j, argv);
		if (while_statment_tokenize2(&i, &j, argv, "<>"))
			add_token(&token_list, i + 1, j, argv);
		if (while_statment_tokenize2(&i, &j, argv, " \t\n\v\f\r"))
			add_token(&token_list, i + 1, j, argv);
	}
	return (add_path(token_list, envp));
}
