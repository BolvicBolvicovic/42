#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(): 
	AForm(
		"PresidentialPardonForm",
		false,
		25,
		5
	), target_path("random_target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string _target_path): 
	AForm(
		"PresidentialPardonForm",
		false,
		25,
		5
	), target_path(_target_path) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &ref):
	AForm(
		"PresidentialPardonForm",
		ref.getIsSigned(),
		25,
		5
	), target_path(ref.target_path) {}

PresidentialPardonForm::~PresidentialPardonForm() {}



PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &ref) {
	this->target_path = ref.target_path;
	return *this;
}

void					PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeRequiredToExec())
		throw  AForm::GradeTooLowException();
	std::cout << this->target_path << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
