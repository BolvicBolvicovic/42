/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deck <deck@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:56 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/29 18:49:29 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define D_QUOTE 0x01
# define S_QUOTE 0x02
# define D_IN_S_QUOTE 0x04
# define S_IN_D_QUOTE 0x08

typedef struct environement
{
	char			**env_cpy;
}					t_env;

typedef struct export
{
	int				i;
	int				j;
	int				k;
	int				empty;
	int				equal;
	int				completed;
}					t_export;

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
}					t_oken_type;

typedef struct soken
{
	t_oken_type		type;
	char			*value;
	char			*path;
	int				s_quote_flag;
	int				d_quote_flag;
	int				f_space;
	struct soken	*next;
}					t_oken;

typedef struct command
{
	char	**args;
	char	**temp;
	int		arg_num;
	int		fd_tab[2];
	int		stdout_backup;
	int		stdin_backup;
	int		fd;
	int		piped;
	int		redirect;
	int		out;
	int		heredoc;
	int		builtin;
	int		rd_fd;
	pid_t	pid;
	int		is_dir;
	int		do_not;
	int		error;
	int		command;
}					t_command;

//Main Function
t_oken				*parsing(char **envp);
t_oken				*do_command(t_oken *lst, int rd_fd, char *path, t_env *env);
void				do_main_loop(t_env *env, t_oken *t_argv, char *cpy);
void				free_tokens(t_oken *list);

//Signal
void				sig_init(void);
int					is_exec(int value);

//Utils
t_oken				*copy_token_list(t_oken *lst)
int					is_str(char c, char *str);
int					is_one_space(char *str);
int					no_quote(char *str);
int					only_space(t_oken *node);
void				*ft_realloc(char *ptr, size_t size);
char				*get_new_str(char *str, char *value, int *i, char *var);
char				*transform_value(char *str, int *i, char **envp, char *var);
int					is_envp(char *str, char **envp, char **variable);
char				*del_backslash(char *str, int i);
void				join_token(t_oken *node, t_oken *next_node);
void				destroy_token(t_oken *previous_node,
						t_oken *node_to_destroy);
void				del_t_type(t_oken **token_list, t_oken_type type1,
						t_oken_type type2);
void				handle_spaces(t_oken **token_list);
int					str_ended_backslash(t_oken *node);
void				token_addback(t_oken **list, t_oken *node);
void				add_token(t_oken **list, int i, int j, char *str);
char				*get_path(char **envp);
void				free_tab(char **tab);
t_oken				*add_path(t_oken *list, char **envp);
char				**ft_realloc_tab(char **tab, int size);
char				*ft_realloc_string(char *str, int size);
char				*ft_strcat_path(char *dest, char *src);
void				ft_put_str_fd(int fd, char *str);
char				**copy_string_array(char **original);

//Flags
void				add_flags(t_oken **t_argv);
void				exec_command_flag(t_oken *t_argv, char *path);
void				join_string(t_oken **token_list);
void				add_envp_var(t_oken **t_argv, char **envp);

//Tokenize
void				add_token(t_oken **list, int i, int j, char *str);
void				add_quote_flag(t_oken *list, int t_flag, int quote);
void				update_token_flags(t_oken *list);
void				add_command_token(t_oken *node);
void				add_operator_token(t_oken *node);
t_oken				*tokenize(char *argv, char **envp);

//command exec
void				exec_command(char **arg_tab, char *cpy, char **envp,
						int rd_fd);
void				execute_heredoc(const char *end_str, int fd_write);
void				do_built_in_command(char **args, t_env *env_cpy);
t_command			var_init(int rd);
t_oken				*fill_arg_tab_utils(t_command *c, t_oken *lst);
t_oken				*fill_arg_tab(t_command *c, t_oken *lst);
t_oken				*if_in_do(t_command *c, t_oken *lst);
t_oken				*if_pipe_do(t_command *c, t_oken *lst);
t_oken				*if_out_do(t_command *c, t_oken *lst);
t_oken				*if_append_do(t_command *c, t_oken *lst);
t_oken				*if_heredoc_do(t_command *c, t_oken *lst);
t_oken				*handle_special_char(t_command *c, t_oken *lst);
void				child_process_do(t_command *c, char *path, t_env *env, t_oken *lst);
void				if_built_in_do(t_command *c, t_env *env);
t_oken				*parent_process_do(t_command *c,
						t_oken *lst, char *path, t_env *env);
t_oken				*do_command(t_oken *lst, int rd_fd, char *path, t_env *env);

//buit-in command
void				ft_echo(char **arg_tab);
void				ft_cd(char **arg_tab);
void				ft_pwd(void);
char				**ft_export(char **arg_tab, t_env *env_cpy);
void				ft_unset(char **arg_tab, t_env *env_cpy);
void				ft_env(t_env *envp, int is_export);
t_export			ft_export_main(t_export e, t_env *env, char **arg_tab);
t_export			ft_export_master(t_export e, char **arg_tab, t_env *env);
int					ft_export_utils2(t_env *env, char **arg_tab, int i, int j);
int					ft_export_utils1(t_env *env, char **arg_tab, int j, int i);
char				**ft_export_print(char **env_cpy);
int					ft_tablen(char **tab);

#endif
