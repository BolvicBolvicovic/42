//Mets un header

#include "philo.h"

int	ft_error(char *str)
{
	printf("%s", str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (!check_args(argc, argv))
		return (ft_error("Error:\nWrong arguments.\n"));
	args = init_args(argc, argv);
	if (!args)
		return (ft_error("Error:\nAllocation failed.\n"));
	free(args);
	return (0);
}
