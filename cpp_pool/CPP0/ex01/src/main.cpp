#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	phoneBook;
	std::cout << "\033]0;Phone Book\a";
	while (true)
	{
		std::cout << "\033c";
		std::cout << "MAIN MENU\n\ncommand: ";
		std::cin >> input;
		if (!input.compare("ADD"))
			phoneBook.add();
		else if (!input.compare("EXIT"))
			break ;
	}
	return (0);
}
