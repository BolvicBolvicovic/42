//mets un header

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct	finder_s
{
	char	**path;
	int		*list_a;
	int		*list_b;
}	finder_t;

//Error handle
void    ft_error(char *error);
void    ft_error_free(char *error, finder_t *finder);
void    full_free(finder_t *finder);

//Init
void    creat_new_lists(int argc, char **argv, finder_t *finder);

//Finder
void    find_path(finder_t *finder);

#endif
