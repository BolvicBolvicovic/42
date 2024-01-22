#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : maxContact(false), contactIndex(0) {}
PhoneBook::~PhoneBook() {}

std::string	getInput()
{
	std::string	input;
	bool		badInput = true;
	do { std::getline(std::cin, input); if (!input.empty()){badInput = false;} } while (badInput);
	return (input);
}

void	PhoneBook::add()
{
	{ std::cout << "First Name: "	 ; this->contacts[this->contactIndex].setFirstName(getInput());	    }
	{ std::cout << "Last Name: "	 ; this->contacts[this->contactIndex].setLastName(getInput());	    }
	{ std::cout << "Nickname: "	 ; this->contacts[this->contactIndex].setNickname(getInput());	    }
	{ std::cout << "Phone Number: "	 ; this->contacts[this->contactIndex].setPhoneNumber(getInput());   }
	{ std::cout << "Darkest Secret: "; this->contacts[this->contactIndex].setDarkestSecret(getInput()); }
	if (this->contactIndex < 8)
		this->contactIndex	+= 1;
	else
	{
		maxContact		= true;
		this->contactIndex	= 0;
	}
}

void	PhoneBook::search() const
{

}
