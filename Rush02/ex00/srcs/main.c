
#include "ourlib.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if ((ft_error(argv[1])))
			return (1);
		if (ft_algo("numbers.dict", argv[1]))
			return (1);
	}
	else if (argc == 3)
	{
		if ((ft_error(argv[2])))
			return (1);
		if (ft_algo(argv[1], argv[2]))
			return (1);
	}
	else
	{
		ft_puterror("Error\n");
		return (1);
	}
	return (0);
}
