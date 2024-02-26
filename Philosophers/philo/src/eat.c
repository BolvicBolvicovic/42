/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:39:06 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/26 12:51:27 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	free(data->tid);
	free(data->forks);
	free(data->philos);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->r_fork);
		messages(TAKE_FORKS, philo);
		if (philo->data->philo_num == 1)
		{
			usleep(philo->data->death_time * 2000);
			return ;
		}
		pthread_mutex_lock(philo->l_fork);
		messages(TAKE_FORKS, philo);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		messages(TAKE_FORKS, philo);
		pthread_mutex_lock(philo->r_fork);
		messages(TAKE_FORKS, philo);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	if (philo->data->philo_num == 1)
	{
		usleep(philo->data->death_time * 2000);
		return ;
	}
	pthread_mutex_unlock(philo->l_fork);
	messages(SLEEP, philo);
	usleep(philo->data->sleep_time * 1000);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->data->death_time;
	messages(EAT, philo);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->lock);
	usleep(philo->data->eat_time * 1000);
	philo->eating = 0;
	drop_forks(philo);
}
