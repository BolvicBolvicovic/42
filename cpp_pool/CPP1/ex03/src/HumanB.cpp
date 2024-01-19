#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void	HumanB::attack() const
{
	if (this->weapon)
	std::cout << name << " attacks with their " << weapon->getType() << "\n";
}

void	HumanB::setWeapon(Weapon &ref)
{
	weapon = &ref;
}

HumanB::~HumanB() {}
