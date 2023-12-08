//METS TON HEADER
#include "minitalk.h"

void	sig_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_error(char *str)
{
	ft_printf("%s\n", str);
	return (1);
}
