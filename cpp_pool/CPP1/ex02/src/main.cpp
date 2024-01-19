#include <string>
#include <iostream>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << &brain << "\n";
	std::cout << stringPTR << "\n";
	std::cout << &stringREF << "\n";
	
	std::cout << brain << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << "\n";
	
	return (0);
}
