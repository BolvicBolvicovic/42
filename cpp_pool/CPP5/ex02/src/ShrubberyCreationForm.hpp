#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string	target_path;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target_path);
	ShrubberyCreationForm(ShrubberyCreationForm &ref);
	~ShrubberyCreationForm();

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm &ref);

	void					execute(const Bureaucrat &executor) const;
};
