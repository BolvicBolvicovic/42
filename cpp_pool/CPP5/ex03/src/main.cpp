#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main() {
	Intern		Chayanne;
	Bureaucrat	Tom("Tom", 42);

	AForm		*formzdezed = Chayanne.makeForm("zedfzd", "azadaz");
	AForm		*form = Chayanne.makeForm("robotomy request", "Chayanne");

	(void)formzdezed;
	Tom.signForm(*form);
	Tom.executeForm(*form);
	return 0;
}
