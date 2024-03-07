#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): 
	AForm(
		"RobotomyRequestForm",
		false,
		72,
		45
	), target_path("random_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string _target_path): 
	AForm(
		"RobotomyRequestForm",
		false,
		72,
		45
	), target_path(_target_path) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &ref):
	AForm(
		"RobotomyRequestForm",
		ref.getIsSigned(),
		72,
		45
	), target_path(ref.target_path) {}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &ref) {
	this->target_path = ref.target_path;
	return *this;
}

void					RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeRequiredToExec())
		throw  AForm::GradeTooLowException();
	srand((unsigned) time(NULL));
	std::cout << (char)7 << (char)7 << (char)7 << "*drill*" << std::endl;
	if (rand() % 2)
		std::cout << this->target_path << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomozation has failed." << std::endl;
}
