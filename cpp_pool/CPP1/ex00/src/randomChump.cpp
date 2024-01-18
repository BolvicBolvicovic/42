#include "Zombie.hpp"

void	randomChamp(std::string name)
{
	Zombie	*newZ = newZombie(name);
	newZ->announce();
	delete newZ;
}
