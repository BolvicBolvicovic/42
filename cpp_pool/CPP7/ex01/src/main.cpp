#include "iter.hpp"
#include <string>

void	cl(std::string &str) { str.insert(0, "haha "); }
void	addOne(int	&nb) { nb += 1; }

int main() {
	{
		std::string	test[]= {"test", "it", "works", "!"};
		iter(test, 4, printArg);
		iter(test, 4, cl);
		iter(test, 4, printArg);
	}
	std::cout << std::endl;
	{
		int		test[] = {1,2,3,4};
		iter(test, 4, printArg);
		iter(test, 4, addOne);
		std::cout << std::endl;
		iter(test, 4, printArg);
	}

	return 0;
}
