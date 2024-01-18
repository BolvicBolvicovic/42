#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie	*newZ;
	if (argc == 3)
	{
		randomChamp(argv[1]);
		newZ = newZombie(argv[2]);
		newZ->announce();
		delete newZ;
	}
	else
		std::cout << "Just give two names for Zs.\n";
	return (0);
}
