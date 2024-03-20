#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base	*generate(void) {
	srand(static_cast<unsigned>(time(NULL)));
	int random = rand() % 3;
	if (random == 0)
		return new A;
	if (random == 1)
		return new B;
	if (random == 2)
		return new C;
	return new C;
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "Base A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Base B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Base C" << std::endl;
}

void	identify(Base &p) {
	Base	*test = &p;
	identify(test);
}

int	main() {

	Base	*test = generate();
	identify(test);
	identify(*test);

	return 0;
}
