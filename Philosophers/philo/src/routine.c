/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:38:50 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/18 15:18:51 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	supervisor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(&philo->lock);
	if (get_time() >= philo->time_to_die && !philo->eating)
		messages(DIED, philo);
	if (philo->eat_count == philo->data->number_of_meals)
	{
		philo->data->is_finished++;
		philo->eat_count++;
	}
	pthread_mutex_unlock(&philo->lock);
}

void	*monitor(void *philo_ptr)
{
	t_philo	*philo;
	int		i;
	int		j;

	j = 0;
	philo = (t_philo *)philo_ptr;
	while (!j)
	{
		i = -1;
		while (++i < philo->data->philo_num)
			supervisor(&philo->data->philos[i]);
		pthread_mutex_lock(&philo->lock);
		if (philo->data->is_finished >= philo->data->philo_num)
			philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_lock(&philo->data->write);
		j = philo->data->is_dead;
		pthread_mutex_unlock(&philo->data->write);
	}
	return ((void *)0);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(&philo->lock);
	philo->time_to_die = philo->data->death_time + get_time();
	pthread_mutex_unlock(&philo->lock);
	while (!i)
	{
		eat(philo);
		messages(THINK, philo);
		pthread_mutex_lock(&philo->data->write);
		i = philo->data->is_dead;
		pthread_mutex_unlock(&philo->data->write);
	}
	return ((void *)0);
}

int	init_thread(t_data *data)
{
	int			i;
	pthread_t	t_monitor;

	i = -1;
	data->start_time = get_time();
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (0);
		usleep(100);
	}
	if (pthread_create(&t_monitor, NULL, &monitor, &data->philos[0]))
		return (0);
	pthread_join(t_monitor, NULL);
	i = -1;
	while (++i < data->philo_num)
		pthread_join(data->tid[i], NULL);
	return (1);
}

int	case_one(t_data *data)
{
	pthread_t	t_monitor;
	int			i;

	i = 0;
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
	{
		free_data(data);
		return (ft_error("Error:\nCould not create thread.\n"));
	}
	if (pthread_create(&t_monitor, NULL, &monitor, &data->philos[0]))
	{
		free_data(data);
		return (ft_error("Error:\nCould not create thread.\n"));
	}
	pthread_join(data->tid[0], NULL);
	pthread_join(t_monitor, NULL);
	while (!i)
	{
		pthread_mutex_lock(&data->write);
		i = data->is_dead;
		pthread_mutex_unlock(&data->write);
	}
	return (0);
}
