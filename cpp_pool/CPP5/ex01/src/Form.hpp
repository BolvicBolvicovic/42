#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class	Bureaucrat;

class   Form {
private:
    const std::string       name;
    bool                    is_signed;
    const unsigned char     grade_required_to_sign;
    const unsigned char     grade_required_to_exec;

public:
    Form();
    Form(const Form &ref);
    Form(const std::string _name, bool _is_signed, int _grade_to_sign, int _grade_to_exec);
    ~Form();

    Form    &operator=(const Form &ref);

    const std::string       getName()                   const;
    bool                    getIsSigned()               const;
    unsigned char           getGradeRequiredToSign()    const;
    unsigned char           getGradeRequiredToExec()    const;

    void                    beSigned(const Bureaucrat &bureaucrat);

    class                   GradeTooHighException : public std::exception    {
        public:
            const char      *what() const throw() { return "Form: Grade Too High!"; }
    };
    class                   GradeTooLowException : public std::exception     {
        public:
            const char      *what() const throw() { return "Form: Grade Too Low!";  }
    };
};

std::ostream    &operator<<(std::ostream &os, const Form &form);
