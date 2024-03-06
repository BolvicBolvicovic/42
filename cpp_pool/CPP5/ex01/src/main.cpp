#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	try {
		Bureaucrat a("Sam", 42);
		std::cout << a << std::endl;
        Form form("Elon Musk's SpaceX stocks", false, 42, 1);
        a.signForm(form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b("Sab", -52);
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat c("Sat", 151);
		std::cout << c << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat d("Sad", 149);
		std::cout << "Start: "<< d << std::endl;
        for (int i = 0; i < 5; i++) {
            d.downgrade();
            std::cout << d << std::endl;
        }
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat e("Mad", 2);
		std::cout << "Start: "<< e << std::endl;
        for (int i = 0; i < 5; i++) {
            e.upgrade();
            std::cout << e << std::endl;
        }
	} catch (std::exception &f) {
		std::cout << f.what() << std::endl;
	}
	return 0;
}
