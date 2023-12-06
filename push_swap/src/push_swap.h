//mets un header

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

//Error handle
void	ft_error(char *error);
void	ft_error_free(char *error, char **argv, int flag);
void	ft_free_matrix(char **m);
void    free_node(void *content);

//Check Arguments
void	ft_check_args(int argc, char **argv, int new_av_flag);

//Init
void	init_stack(char **argv, t_list **stack, int new_av_flag);

//Finder
int		find_path(t_list *a, t_list *b);

//Commands
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

#endif
