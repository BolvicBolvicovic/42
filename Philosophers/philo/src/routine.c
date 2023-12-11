//mets un header

#include "philo.h"

void	*monitor(void *philo_ptr)
{
        t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(&philo->data->write);
	printf("data val: %d", philo->data->is_dead);
	pthread_mutex_unlock(&philo->data->write);
	while (!philo->data->is_dead)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->is_finished >= philo->data->philo_num)
			philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*supervisor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (!philo->data->is_dead)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && !philo->eating)
			messages(DIED, philo);
		if (philo->eat_count == philo->data->number_of_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->is_finished++;
			philo->eat_count++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	philo->time_to_die = philo->data->death_time + get_time();
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (!philo->data->is_dead)
	{
		eat(philo);
		messages(THINK, philo);
	}
	return ((void *)0);
}

int	init_thread(t_data *data)
{
	int		i;
	pthread_t	t_monitor;

	i = -1;
	data->start_time = get_time();
	if (data->number_of_meals > 0)
		if (pthread_create(&t_monitor, NULL, &monitor, &data->philos[0]))
			return (0);
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[0]))
			return (0);
		ft_usleep(1);
	}
	i = -1;
	while (++i < data->philo_num)
		if (pthread_join(data->tid[i], NULL))
			return (0);
	return (1);
}
