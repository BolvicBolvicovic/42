//Mets un header

#include "philo.h"

void	free_data(t_data *data)
{
	free(data->tid);
	free(data->forks);
	free(data->philos);
}

int	ft_error(char *str)
{
	printf("%s", str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argc, argv))
		return (ft_error("Error:\nWrong arguments.\n"));
	if (!init_data(argc, argv, &data))
		return (ft_error("Error:\nInitialization failed.\n"));
	return (0);
}
