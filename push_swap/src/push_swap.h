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
void    free_list(t_list *a);
//Check Arguments
void	ft_check_args(int argc, char **argv, int new_av_flag);

//Init
void	init_stack(char **argv, t_list **stack, int new_av_flag);

//Finder
void	find_path(t_list **a, t_list **b);
void	quicksort(t_list **a, t_list **b);
void	sort_three(t_list **a);
int		is_sorted(t_list *a);
void	do_best_move(t_list **a, t_list **b);
void	move_node(t_list **a, t_list **b, t_list *target, t_list *bullet);
int		get_cost(t_list *a, t_list *target);

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
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);

#endif
