#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): 
	AForm(
		"ShrubberyCreationForm",
		false,
		145,
		137
	), target_path("random_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target_path): 
	AForm(
		"ShrubberyCreationForm",
		false,
		145,
		137
	), target_path(_target_path) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &ref):
	AForm(
		"ShrubberyCreationForm",
		ref.getIsSigned(),
		145,
		137
	), target_path(ref.target_path) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}



ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &ref) {
	this->target_path = ref.target_path;
	return *this;
}

void					ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
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
