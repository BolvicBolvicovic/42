#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &ref) { (void)ref; }
Intern::~Intern(){}

const Intern	&Intern::operator=(const Intern &ref) { (void)ref; return *this; }

AForm	*Intern::createSC(const std::string &target) {
	return new ShrubberyCreationForm(target);
}
AForm	*Intern::createRR(const std::string &target) {
	return new RobotomyRequestForm(target);
}
AForm	*Intern::createPP(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string form_name, std::string target_name) {
	
	AForm	*form = NULL;
	const	std::string form_names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};
	AForm	*(Intern::*builder[])(const std::string&) = {
		&Intern::createSC,
		&Intern::createRR,
		&Intern::createPP
	};
	for (int i = 0; i < 3; i++) {
		if (form_name == form_names[i]) {
			form = (this->*builder[i])(target_name);
			std::cout << "Intern creates " << *form << std::endl;
			return form;
		}
	}
	std::cout << form_name << "is unknown type of form." << std::endl;
	return NULL;
}
