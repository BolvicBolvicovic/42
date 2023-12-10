//mets un header

#include "philo.h"

int	is_num(char *str)
{
	int	i;
	int	count_non_zero;

	count_non_zero = 0;
	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		if (str[i] != '0')
			count_non_zero++;
	}
	if (!count_non_zero)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (!is_num(argv[i]))
			return (0);
	if (argc != 5 && argc != 6)
		return (0);
	return (1);
}

int	init_data(t_args *args, t_data *data)
{
	data->philo_num = (int) ft_atoi(argv[1]);
	data->death_time = (u_int64_t) ft_atoi(argv[2]);
	data->eat_time = (u_int64_t) ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_nb = (int) ft_atoi(argv[5]);
	else
		data->meals_nb = -1;
	if (data->philo_num > 200)
		return (0);
	data->dead = 0;
	dara->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	data->philos =malloc(sizeof(t_philo) * data->philo_num);
	if (!data->tid || !data->forks || !data->philos)
	{
		free_data(data);
		return (0);
	}
	if (init_forks(data))
		return (1);
	init_philos(data);
	return (1);
}
