#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <string>
#include <iostream>
class	Contact
{
	public:
		Contact()	;
		~Contact()	;

		void		printContact(void)			;
		void		setFirstName(std::string str)		;
		void		setLastName(std::string str)		;
		void		setNickname(std::string str)		;
		void		setPhoneNumber(std::string str)		;
		void		setDarkestSecret(std::string str)	;
		std::string	getFirstName()		;
		std::string	getLastName()		;
		std::string	getNickname()		;
		std::string	getPhoneNumber()	;
		std::string	getDarkestSecret()	;
	private:
		std::string	firstName	;
		std::string	lastName	;
		std::string	nickname	;
		std::string	phoneNumber	;
		std::string	darkestSecret	;
};

#endif
