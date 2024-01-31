#include <iostream>
#include <string>

class IMateriaSource
{
public:
	IMateriaSource();
	~IMateriaSource();

	void learnMateria( AMateria* );
	AMateria* createMateria( std::string const &type );
};
