#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	target_path;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _target_path);
	PresidentialPardonForm(PresidentialPardonForm &ref);
	~PresidentialPardonForm();

	PresidentialPardonForm	&operator=(PresidentialPardonForm &ref);

	void					execute(const Bureaucrat &executor) const;
};
