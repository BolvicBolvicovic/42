#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	target_path;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _target_path);
	RobotomyRequestForm(RobotomyRequestForm &ref);
	~RobotomyRequestForm();

	RobotomyRequestForm	&operator=(RobotomyRequestForm &ref);

	void					execute(const Bureaucrat &executor) const;
};
