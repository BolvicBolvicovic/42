#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

void	Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed...\n";
}
