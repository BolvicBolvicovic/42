#include "master.hpp"

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	handle_file(argv[1], argv[2], argv[3]);
	return (0);
}
