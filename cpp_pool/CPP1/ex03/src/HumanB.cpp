#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(Weapon(NULL)) {}

void	HumanB::attack() const
{
	if (weapon.getType().compare(NULL))
		std::cout << name << " attacks with their " << weapon.getType() << "\n";
}

HumanB::~HumanB() {}
