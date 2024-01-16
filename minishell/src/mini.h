/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:56 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/16 17:02:22 by vcornill         ###   ########.fr       */
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

typedef enum soken_type
{
	T_SPACE,
	T_S_QUOTE,
	T_D_QUOTE,
	T_WORD,
	T_DIR_OR_FILE,
	T_CMD_ENVP,
	T_CMD,
	T_PIPE,
	T_REDIRECT_IN,
	T_REDIRECT_OUT,
	T_APPEND,
	T_HEREDOC,
	T_ERROR,
}	t_oken_type;

typedef struct soken
{
	t_oken_type		type;
	char			*value;
	char			*path;
	int				s_quote_flag;
	int				d_quote_flag;
	int				f_space;
	struct soken	*next;
}	t_oken;
//Main Function
t_oken	*parsing(char **envp);

//Utils
int		is_str(char c, char *str);
int		is_one_space(char *str);
int		no_quote(char *str);
int		only_space(t_oken *node);
void	*ft_realloc(char *ptr, size_t size);
char	*get_new_str(char *str, char *value, int *i, char *var);
char	*transform_value(char *str, int *i, char **envp, char *var);
int		is_envp(char *str, char **envp, char **variable);
char	*del_backslash(char *str, int i);
void	join_token(t_oken *node, t_oken *next_node);
void	destroy_token(t_oken *previous_node, t_oken *node_to_destroy);
void	del_t_type(t_oken **token_list, t_oken_type type1, t_oken_type type2);
void	handle_spaces(t_oken **token_list);
int		str_ended_backslash(t_oken *node);
void	token_addback(t_oken **list, t_oken *node);
void	add_token(t_oken **list, int i, int j, char *str);
char	*get_path(char **envp);
t_oken	*add_path(t_oken *list, char **envp);

//Flags
void	add_flags(t_oken **t_argv);
void	exec_command_flag(t_oken *t_argv, char *path);
void	join_string(t_oken **token_list);
void	add_envp_var(t_oken **t_argv, char **envp);

//Tokenize
void	add_token(t_oken **list, int i, int j, char *str);
void	add_quote_flag(t_oken *list, int t_flag, int quote);
void	update_token_flags(t_oken *list);
void	add_command_token(t_oken *node);
void	add_operator_token(t_oken *node);
t_oken	*tokenize(char *argv, char **envp);

#endif
