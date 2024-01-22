#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define MAX_CONTACTS 8


#include <iostream>
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[MAX_CONTACTS];
		int	contactIndex;
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search() const;
		void	exit();
};

#endif
