#include "Form.hpp"

Form::Form(): name("random"),
    is_signed(false),
    grade_required_to_sign(150),
    grade_required_to_exec(150) {}

Form::Form(const Form &ref): name(ref.name),
    is_signed(ref.is_signed),
    grade_required_to_sign(ref.grade_required_to_sign),
    grade_required_to_exec(ref.grade_required_to_exec) {}

Form::Form(const std::string _name, bool _is_signed, int _grade_to_sign, int _grade_to_exec):
    name(_name), is_signed(_is_signed), grade_required_to_sign(_grade_to_sign), grade_required_to_exec(_grade_to_exec) {
    if (_grade_to_sign < 1 || _grade_to_exec < 1)
        throw Form::GradeTooHighException();
    if (_grade_to_sign > 150 || _grade_to_exec > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

Form                &Form::operator=(const Form &ref) {
    this->is_signed                 = ref.is_signed;
    return *this;
}

const std::string   Form::getName()                   const { return this->name; }
bool                Form::getIsSigned()               const { return this->is_signed; }
unsigned char       Form::getGradeRequiredToSign()    const { return this->grade_required_to_sign; }
unsigned char       Form::getGradeRequiredToExec()    const { return this->grade_required_to_exec; }

void                Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->grade_required_to_sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;
}

std::ostream        &operator<<(std::ostream &os, const Form &form) {
    os << "Form: "<< std::endl << "name: " << form.getName() << std::endl
        << "is signed: " << (form.getIsSigned() == true ? "yes" : "no") << std::endl
        << "grade required to sign: " << (unsigned int)form.getGradeRequiredToSign() << std::endl
        << "grade required to exec: " << (unsigned int)form.getGradeRequiredToExec() << std::endl;
    return os;
}
