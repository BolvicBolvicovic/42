//mets un header

#include "philo.h"

int	is_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
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

t_args	*init_args(int argc, char **argv)
{
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		args->number_of_times_each_philosopher_must_eat = -1;	
	return (args);
}
