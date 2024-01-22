#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactIndex(0) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::add()
{
	do {std::cout << "First name: "		; std::cin >> this->contacts[contactIndex].firstName;	 }
	while (!this->contacts[contactIndex].firstName.at(0)	);
	do {std::cout << "Last name: "		; std::cin >> this->contacts[contactIndex].lastName;	 }
	while (!this->contacts[contactIndex].lastName.at(0)	);
	do {std::cout << "Nickname: "		; std::cin >> this->contacts[contactIndex].nickname;	 }
	while (!this->contacts[contactIndex].nickname.at(0)	);
	do {std::cout << "Phone Number: "	; std::cin >> this->contacts[contactIndex].phoneNumber;	 }
	while (!this->contacts[contactIndex].phoneNumber.at(0)	);
	do {std::cout << "Darkest Secret: "	; std::cin >> this->contacts[contactIndex].darkestSecret;}
	while (!this->contacts[contactIndex].darkestSecret.at(0));
}

void	PhoneBook::search() const
{
}

void	PhoneBook::exit()
{
}
