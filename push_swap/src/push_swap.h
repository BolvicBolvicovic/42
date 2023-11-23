//mets un header

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct	s_node
{
	int		num;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

//Error handle
void	ft_error(char *error);
void	ft_error_free(char *error, char **argv, int flag);
void	ft_free_matrix(char **m);

//Check Arguments
void	ft_check_args(int argc, char **argvi, int new_av_flag);


//Init
void	init_stack(char **argv, t_node **stack, int new_av_flag);

//Finder
int		find_path(t_node *finder);

#endif
