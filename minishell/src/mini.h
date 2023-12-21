/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:56 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/20 13:12:40 by vcornill         ###   ########.fr       */
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
# define D_IN_S_QUOTE 0x04
# define S_IN_D_QUOTE 0x08

typedef enum
{
	T_WORD,
	T_CMD,
	T_PIPE,
	T_REDIRECT_IN,
	T_REDIRECT_OUT,
	T_APPEND,
	T_HEREDOC,
	T_ERROR,
}	token_type;

typedef struct s_envp
{
	char		*v_name;
	struct s_envp	*next;
}	t_envp;

typedef struct soken
{
	token_type	type;
	t_envp		*envp;
	char		*value;
	int		quote_flag;
	int		f_space;
	struct soken	*next;
}	token;

//Utils
int		is_str(char c, char *str);
int		is_one_space(char *str);
int		no_quote(char *str);
int		only_space(char *str);

//Tokenize
void	add_token(token **list, int i, int j, char *str);
void	add_quote_flag(token *list, int t_flag, int quote);
void	update_token_flags(token *list);
void	add_command_token(token *node);
void	add_operator_token(token *node);
token	*tokenize(char *argv);

#endif
