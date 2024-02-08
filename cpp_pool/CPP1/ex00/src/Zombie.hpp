#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string.h>
# include <iostream>

class	Zombie
{
private:
	std::string	name;
public:
	Zombie(std::string name);
	void	announce() const;
	~Zombie();
};

void		randomChump(std::string name);
Zombie		*newZombie(std::string name);

#endif
