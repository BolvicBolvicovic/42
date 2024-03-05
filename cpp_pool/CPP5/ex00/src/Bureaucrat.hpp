#pragma once

#include <string>
#include <iostream>
#include <exception>

class	Bureaucrat {

private:
	const std::string	name;
	unsigned char		grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat(std::string _name, unsigned char _grade);
	~Bureaucrat();

	const	Bureaucrat	&operator=(const Bureaucrat &ref);


	const std::string	getName()	const;
	unsigned char		getGrade()	const;

	void				upgrade();
	void				downgrade();
	
	class				GradeTooHighException : public std::exception {
		public:
			const char	*what() const throw() { return "Grade Too High!"; }
	};
	class				GradeTooLowException : public std::exception {
		public:
			const char	*what const throw() { return "Grade Too Low!"; }
	};

};

std::ostream	&operator<<(std::ostream os, const Bureaucrat &bureaucrat);
