// mets un header

#include "push_swap.h"

void    check_double(int argc, char **argv, int new_av_flag)
{
        int     i;
        int     j;
        int     count;
        int	*list;

	i = -1;
	list = ft_calloc(sizeof(int), argc);
	if (!list)
		ft_error_free("Error.", argv, new_av_flag);
	while (++i < argc - 1)
		list[i] = ft_atoi(argv[i + 1]);
        i = -1;
	while (++i < argc)
        {
                count = 0;
                j = -1;
                while (++j < argc)
                        if (list[i] == list[j])
                		count++;
		if (count != 1 && list[i])
                {
			free(list);
                        ft_error_free("Error, there is at least one double.", argv, new_av_flag);
                }
		else if (count > 3 && !list[i])
		{
			free(list);
			ft_error_free("Error, there is at least one double.", argv, new_av_flag);		
		}
        }
	free(list);
}

void	ft_check_args(int argc, char **argv, int new_av_flag)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		ft_error("No argument.");
	if (new_av_flag)
		i--;
	while (argv[++i])
	{
		j = -1;
		if (argv[i][0] == '-' && argv[i][1])
			j = 0;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				ft_error_free("At least one argument is not a number.", argv, new_av_flag);
	}
	check_double(argc, argv, new_av_flag);
}
