// mets un header


#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct	s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}		t_args;

//Check Arguments
int	check_args(int argc, char **argv);
t_args	*init_args(int argc, char **argv);

//Utils
int	ft_atoi(const char *nptr);














#endif
