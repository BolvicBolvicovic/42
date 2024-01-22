#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <string>

class	Contact
{
	public:
		Contact()	;
		~Contact()	;

		std::string	firstName	;
		std::string	lastName	;
		std::string	nickname	;
		std::string	phoneNumber	;
		std::string	darkestSecret	;
};

#endif
