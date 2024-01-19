#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(Weapon("")) {}

void	HumanB::attack() const
{
	if (weapon.getType().compare(""))
		std::cout << name << " attacks with their " << weapon.getType() << "\n";
}

void	HumanB::setWeapon(Weapon &ref)
{
	weapon = ref;
}

HumanB::~HumanB() {}
