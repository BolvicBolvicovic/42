#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
		randomChamp(argv[1]);
	else
		std::cout << "Just give one name for the Z.\n";
	return (0);
}
