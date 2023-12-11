//Mets un header

#include "philo.h"

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

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

void	end_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	free_data(data);	
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argc, argv))
		return (ft_error("Error:\nWrong arguments.\n"));
	if (!init_data(argc, argv, &data))
	{
		free_data(&data);
		return (ft_error("Error:\nInitialization failed.\n"));
	}
	if (!init_thread(&data))
	{
		end_all(&data);
		return (ft_error("Error:\nProblem with threading.\n"));
	}
	end_all(&data);
	return (0);
}
