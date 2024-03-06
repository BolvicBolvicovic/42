#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("random"), grade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat &ref): name(ref.name), grade(ref.grade) {}
Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
    this->grade = _grade;
}
Bureaucrat::~Bureaucrat() {}

const	Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &ref) {
	this->grade = ref.grade;
	return *this;
}

const std::string	Bureaucrat::getName()	const { return this->name;	}
unsigned char	        	Bureaucrat::getGrade()	const { return this->grade;	}

void				Bureaucrat::upgrade()	{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
}
void				Bureaucrat::downgrade()	{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << (unsigned int)bureaucrat.getGrade();
    return os;
}
