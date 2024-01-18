#include "Zombie.hpp"

void	randomChamp(std::string name)
{
	Zombie	newZ = Zombie(name);
	newZ.announce();
}
