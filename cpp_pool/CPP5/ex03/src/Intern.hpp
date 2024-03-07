#pragma once

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class	Intern {
public:
	Intern();
	~Intern();

	AForm	*makeForm(std::string form_name, std::string target_name);
};
