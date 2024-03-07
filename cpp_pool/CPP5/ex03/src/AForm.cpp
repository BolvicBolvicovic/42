#include "AForm.hpp"

AForm::AForm(): name("random"),
    is_signed(false),
    grade_required_to_sign(150),
    grade_required_to_exec(150) {}

AForm::AForm(const AForm &ref): name(ref.name),
    is_signed(ref.is_signed),
    grade_required_to_sign(ref.grade_required_to_sign),
    grade_required_to_exec(ref.grade_required_to_exec) {}

AForm::AForm(const std::string _name, bool _is_signed, int _grade_to_sign, int _grade_to_exec):
    name(_name), is_signed(_is_signed), grade_required_to_sign(_grade_to_sign), grade_required_to_exec(_grade_to_exec) {
    if (_grade_to_sign < 1 || _grade_to_exec < 1)
        throw AForm::GradeTooHighException();
    if (_grade_to_sign > 150 || _grade_to_exec > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm                &AForm::operator=(const AForm &ref) {
    this->is_signed                 = ref.is_signed;
    return *this;
}

const std::string   AForm::getName()                   const { return this->name; }
bool                AForm::getIsSigned()               const { return this->is_signed; }
unsigned char       AForm::getGradeRequiredToSign()    const { return this->grade_required_to_sign; }
unsigned char       AForm::getGradeRequiredToExec()    const { return this->grade_required_to_exec; }

void                AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->grade_required_to_sign)
        throw AForm::GradeTooLowException();
    this->is_signed = true;
}

std::ostream        &operator<<(std::ostream &os, const AForm &form) {
    os << "AForm: "<< std::endl << "name: " << form.getName() << std::endl
        << "is signed: " << (form.getIsSigned() == true ? "yes" : "no") << std::endl
        << "grade required to sign: " << (unsigned int)form.getGradeRequiredToSign() << std::endl
        << "grade required to exec: " << (unsigned int)form.getGradeRequiredToExec() << std::endl;
    return os;
}
