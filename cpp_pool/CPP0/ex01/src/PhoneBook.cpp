#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : maxContact(false), contactIndex(0)	{}
PhoneBook::~PhoneBook()						{}

std::string	getInput()
{
	std::string	input;
	bool		badInput = true;
	do { std::getline(std::cin, input); if (!input.empty()){badInput = false;} } while (badInput);
	return (input);
}

std::string	getStringTruncated(std::string str)
{
	std::string result;

	if	(str.length() > 10) { return str.substr(0, 9) + '.'; }
	else	{result = str; }
	for	(int i = str.length(); i < 10; i++) { result += ' '; }
	return result;
}

void	PhoneBook::add()
{
	{ std::cout << "First Name: "	 ; this->contacts[this->contactIndex % 8].setFirstName(getInput());	}
	{ std::cout << "Last Name: "	 ; this->contacts[this->contactIndex % 8].setLastName(getInput());	}
	{ std::cout << "Nickname: "	 ; this->contacts[this->contactIndex % 8].setNickname(getInput());	}
	{ std::cout << "Phone Number: "	 ; this->contacts[this->contactIndex % 8].setPhoneNumber(getInput());	}
	{ std::cout << "Darkest Secret: "; this->contacts[this->contactIndex % 8].setDarkestSecret(getInput());	}
	{ this->contactIndex 	+= 	1;									}
}

void	PhoneBook::search()
{
	{ std::cout << std::endl << "<------------------- CONTACTS ------------------->" << std::endl; }
	for (int i = 0; i < (this->contactIndex % 8); i++)
	{
		std::cout << (char)(i + '0') << "         " << " | ";
		std::cout << getStringTruncated(this->contacts[i].getFirstName())	<< " | ";
		std::cout << getStringTruncated(this->contacts[i].getLastName())	<< " | ";
		std::cout << getStringTruncated(this->contacts[i].getNickname())	<< " | ";
		std::cout << std::endl;
	}
	int	inputIndex; std::cout << "Select Index Contact: "; std::cin >> inputIndex; 
	if	(std::cin.fail()) { std::cout << "Wrong data." << std::endl; return ;					}
	if	(inputIndex <= (this->contactIndex % 8) && inputIndex > -1) { contacts[inputIndex].printContact();	}
	else	{ std::cout << "This contact index does not exist." << std::endl;					}
}
