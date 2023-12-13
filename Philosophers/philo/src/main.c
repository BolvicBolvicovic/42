/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:39:20 by vcornill          #+#    #+#             */
/*   Updated: 2023/12/13 12:22:49 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
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

int	case_one(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
	{
		end_all(data);
		return (ft_error("Error:\nCould not create thread.\n"));
	}
	pthread_detach(data->tid[0]);
	while (!data->is_dead)
		usleep(0);
	end_all(data);
	return (0);
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
	if (data.philo_num == 1)
		return (case_one(&data));
	if (!init_thread(&data))
	{
		end_all(&data);
		return (ft_error("Error:\nProblem with threading.\n"));
	}
	end_all(&data);
	return (0);
}
