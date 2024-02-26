/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:39:20 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/18 15:15:10 by vcornill         ###   ########.fr       */
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
	{
		if (case_one(&data))
			return (ft_error("Error:\nProblem with threading.\n"));
		free_data(&data);
		return (0);
	}
	if (!init_thread(&data))
	{
		free_data(&data);
		return (ft_error("Error:\nProblem with threading.\n"));
	}
	free_data(&data);
	return (0);
}
