/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:41:15 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/18 14:31:40 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				eat_count;
	int				status;
	int				eating;
	int				time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}		t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				number_of_meals;
	int				is_dead;
	int				is_finished;
	t_philo			*philos;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}		t_data;

//Check Arguments
int		check_args(int argc, char **argv);
int		init_data(int argc, char **argv, t_data *data);
//Utils
int		ft_atoi(const char *nptr);
int		init_forks(t_data *data);
void	init_philos(t_data *data);
void	free_data(t_data *data);
void	messages(char *msg, t_philo *philo);
int		get_time(void);
int		ft_error(char *str);
//Routine
int		init_thread(t_data *data);
int		case_one(t_data *data);
void	*routine(void *philo_ptr);
void	eat(t_philo *philo);

#endif
