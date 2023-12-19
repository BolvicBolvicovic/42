/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:56 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/19 16:53:57 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "ft_printf.h"


# define D_QUOTE 0x01
# define S_QUOTE 0x02

typedef enum
{
	T_WORD,
	T_CMD,
	T_PIPE,
	T_REDIRECT_IN,
	T_REDIRECT_OUT,
	T_APPEND,
	T_HEREDOC,
	T_ENVP_ARG,
	T_ERROR,
}	token_type;

typedef struct soken
{
	token_type	type;
	char		*value;
	int		s_quote_f;
	int		d_quote_f;
	int		f_space;
	struct soken	*next;
}	token;

int		find_type(char *str);
int		clear_input(char *input);
int		is_str(char c, char *str);
void	add_token(token **list, int i, int j, char *str);
void	add_quote_flag(token *list, int t_flag, int quote);
void	update_token_flags(token *list);
void	add_command_token(token *node);
void	add_operator_token(token *node);

#endif
