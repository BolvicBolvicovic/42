/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:49 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/19 17:50:33 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	update_quote_flags(char c, int *quote)
{
	if (c == '\'' && *quote & S_QUOTE)
		*quote &= ~S_QUOTE;
	else if (c == '\'')
		*quote |= S_QUOTE;
	if (c == '\"' && *quote & D_QUOTE)
		*quote &= ~D_QUOTE;
	else if (c == '\"')
		*quote |= D_QUOTE;
}

token	*tokenize(char *argv)
{
	int		quote;
	int		i;
	int		j;
	token	*token_list;
	
	i = 0;
	quote = 0;
	token_list = NULL;
	while (argv[i])
	{
		j = i;
		while (argv[i] && is_str(argv[i], "<>|\'\" "))
			i++;
		if (i != j)
		{
			add_token(&token_list, i + 1, j, argv);
			if (quote)
				add_quote_flag(token_list, T_WORD, quote);
		}
		j = i;
		while (argv[i] && !is_str(argv[i], "<>|\'\" "))
                        i++;
                if (argv[j])
			add_token(&token_list, i + 1, j, argv);
		update_quote_flags(argv[i], &quote);
		if (quote)
			add_quote_flag(token_list, T_WORD, quote);
	}
	return (token_list);
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
			t_argv = tokenize(input);
			while (t_argv)
			{
				printf("Value: %s Token: %d S_flag: %d D_flag: %d\n", t_argv->value, t_argv->type, t_argv->s_quote_f, t_argv->d_quote_f);
				free(t_argv->value);
				t_argv = t_argv->next;
			}
		}
		free(t_argv);
		free(input);
	}
	return (0);
}
