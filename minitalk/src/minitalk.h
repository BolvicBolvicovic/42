#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft.h"
# include "ft_printf.h"

//Error Handler
int     ft_error(char *str);
void     sig_error(char *str);

#endif
