#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

const std::string	&Weapon::getType() const
{
	return (type);
}

void		Weapon::setType(std::string new_type)
{
	std::string	&tmp = new_type;
	type = tmp;
}

Weapon::~Weapon() {}
