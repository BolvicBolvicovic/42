#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weepon) : name(name), weapon(weepon) {}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}

HumanA::~HumanA() {}
