#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

void	HumanA::attack() const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}

HumanA::~HumanA() {}
