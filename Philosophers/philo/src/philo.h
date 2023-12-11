// mets un header


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

typedef struct	s_args
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}		t_args;

typedef struct	s_philo
{
	struct s_data	*data;
	pthread_t	t1;
	int		id;
	int		eat_count;
	int		status;
	int		eating;
	int		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}		t_philo;

typedef struct s_data
{
        pthread_t	*tid;
	int		philo_num;
        int		number_of_meals;
        int		is_dead;
        int		is_finished;
        t_philo		*philos;
	int		death_time;
	int		eat_time;
	int		sleep_time;
	int		start_time;
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
int		ft_usleep(useconds_t time);

//Routine
int		init_thread(t_data *data);
void	eat(t_philo *philo);

#endif
