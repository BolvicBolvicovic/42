#pragma once

#include <string>
#include <iostream>
#include <exception>

class	Bureaucrat {

private:
	const std::string	name;
	unsigned char		grade;
public:
	Bureaucrat(std::string _name, unsigned char _grade);
	~Bureaucrat();

	const std::string	getName();
	unsigned char		getGrade();

	void				upgrade();
	void				downgrade();

};

std::ostream	&operator<<(std::ostream os, const Bureaucrat &bureaucrat);
