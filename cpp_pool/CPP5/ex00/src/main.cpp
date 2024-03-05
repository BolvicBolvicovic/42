#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat a("Sam", 5);
	Bureaucrat b("Sam", -5);
	Bureaucrat c("Sam", 555);
	Bureaucrat d("Sam", 55555555555555555);
	std::cout << a << std:endl;
	std::cout << b << std:endl;
	std::cout << c << std:endl;
	std::cout << d << std:endl;
	return 0;
}
