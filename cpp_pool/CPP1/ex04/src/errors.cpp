#include "master.hpp"

void	ft_error(std::string str)
{
	std::cerr << str << std::endl;
	exit(EXIT_FAILURE);
}

void	check_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 4)
		ft_error("Wrong Arguments.");
}
