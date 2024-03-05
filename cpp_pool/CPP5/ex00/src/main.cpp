#include "Bureaucrat.hpp"

int	main() {
	try {
		Bureaucrat a("Sam", 5);
		std::cout << a << std::endl;
	} catch (std:: exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b("Sam", 0);
		std::cout << b << std::endl;
	} catch (std:: exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat c("Sam", 55);
		std::cout << c << std::endl;
	} catch (std:: exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
