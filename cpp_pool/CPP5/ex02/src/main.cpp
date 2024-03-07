#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main() {
	ShruberryCreationForm	a;
	PresidentialPardonForm	b("Tom");
	RobotomyRequestForm		c("Tom");
	Bureaucrat				Tom("Tom", 42);
	
	Tom.signForm(a);
	Tom.executeForm(a);
	Tom.signForm(b);
	Tom.executeForm(b);

	Bureaucrat				Max("Max", 5);
	Max.signForm(a);
	Max.signForm(b);
	Max.executeForm(b);

	Max.signForm(c);
	Max.executeForm(c);
	return 0;
}
