#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
public:
	std::string	name;
	Zombie();
	void	announce() const;
	~Zombie();
};

Zombie	*zombieHorde( int N, std::string name );

#endif
