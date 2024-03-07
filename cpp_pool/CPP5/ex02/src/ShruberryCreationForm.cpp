#include "ShruberryCreationForm.hpp"
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm(): 
	AForm(
		"ShruberryCreationForm",
		false,
		145,
		137
	), target_path("random_target") {}

ShruberryCreationForm::ShruberryCreationForm(std::string _target_path): 
	AForm(
		"ShruberryCreationForm",
		false,
		145,
		137
	), target_path(_target_path) {}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm &ref):
	AForm(
		"ShruberryCreationForm",
		ref.getIsSigned(),
		145,
		137
	), target_path(ref.target_path) {}

ShruberryCreationForm::~ShruberryCreationForm() {}



ShruberryCreationForm	&ShruberryCreationForm::operator=(ShruberryCreationForm &ref) {
	this->target_path = ref.target_path;
	return *this;
}

void					ShruberryCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeRequiredToExec())
		throw  AForm::GradeTooLowException();
	
	std::string	filename = this->target_path + "_shrubbery";
	std::ofstream	file(filename.c_str());
	file <<
"	    _-_"			<< std::endl <<
"     /~~   ~~\\"		<< std::endl <<
"  /~~         ~~\\"	<< std::endl <<
" {               }"	<< std::endl <<
"  \\  _-     -_  /"	<< std::endl <<
"    ~  \\\\ //  ~"		<< std::endl <<
" _- -   | | _- _"		<< std::endl <<
 "   _ -  | |   -_"		<< std::endl <<
  "       // \\\\";
	file.close();
}
