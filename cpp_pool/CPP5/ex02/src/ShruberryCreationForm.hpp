#pragma once

#include "AForm.hpp"

class ShruberryCreationForm : public AForm {
private:
	std::string	target_path;
public:
	ShruberryCreationForm();
	ShruberryCreationForm(std::string _target_path);
	ShruberryCreationForm(ShruberryCreationForm &ref);
	~ShruberryCreationForm();

	ShruberryCreationForm	&operator=(ShruberryCreationForm &ref);

	void					execute(const Bureaucrat &executor) const;
};
