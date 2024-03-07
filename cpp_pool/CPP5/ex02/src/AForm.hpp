#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class	Bureaucrat;

class   AForm {
private:
    const std::string       name;
    bool                    is_signed;
    const unsigned char     grade_required_to_sign;
    const unsigned char     grade_required_to_exec;

public:
    AForm();
    AForm(const AForm &ref);
    AForm(const std::string _name, bool _is_signed, int _grade_to_sign, int _grade_to_exec);
    ~AForm();

    AForm    &operator=(const AForm &ref);

    const std::string       getName()                   const;
    bool                    getIsSigned()               const;
    unsigned char           getGradeRequiredToSign()    const;
    unsigned char           getGradeRequiredToExec()    const;

    void                    beSigned(const Bureaucrat &bureaucrat);
	virtual void			execute(const Bureaucrat &executor) const = 0;
    class                   GradeTooHighException : public std::exception    {
        public:
            const char      *what() const throw() { return "AForm: Grade Too High!"; }
    };
    class                   GradeTooLowException : public std::exception     {
        public:
            const char      *what() const throw() { return "AForm: Grade Too Low!";  }
    };
};

std::ostream    &operator<<(std::ostream &os, const AForm &form);
