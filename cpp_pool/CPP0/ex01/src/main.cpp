#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	phoneBook;
	std::cout << "\033]0;Phone Book\a\033c";
	while (true)
	{	
		{ std::cout << "MAIN MENU\n\ncommand: "; std::cin >> input;	}
		if (!input.compare("ADD"))		{ phoneBook.add();	}
		else if (!input.compare("EXIT"))	{ break ;		}
		else if (!input.compare("SEARCH")) 	{ phoneBook.search();	}
	}
	return (0);
}
