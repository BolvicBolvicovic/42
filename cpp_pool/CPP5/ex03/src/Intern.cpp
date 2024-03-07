#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::~Intern(){}

AForm	*Intern::makeForm(std::string form_name, std::string target_name) {
	
	AForm	*form = NULL;
	switch (0) {
		case form_name == "robotomy request":
			form = new RobotomyRequestForm(target_name);
			break ;
		case form_name == "shrubbery creation":
			form = new ShrubberyCreationForm(target_name);
			break ;
		case form_name == "presidential pardon":
			form = new PresidentialPardonForm(target_name);
			break ;
		default:
			std::cout << "Unknown type of form." << std::endl;
			return NULL;
	}

	std::cout << "Intern creates " << form << std::endl;
	return form;
}
