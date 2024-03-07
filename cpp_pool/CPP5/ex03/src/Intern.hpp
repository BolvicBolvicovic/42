#pragma once

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class	Intern {
public:
	Intern();
	Intern(const Intern &ref);
	~Intern();
	
	const Intern	&operator=(const Intern &ref);

	AForm	*makeForm(std::string form_name, std::string target_name);
	AForm*	createSC(const std::string &target);
	AForm*	createRR(const std::string &target);
	AForm*	createPP(const std::string &target);
};
