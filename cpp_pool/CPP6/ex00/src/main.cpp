#include "ScalarConverter.hpp"

int	main() {
	ScalarConverter::convert("c");
	ScalarConverter::convert("-58");
	ScalarConverter::convert("58");
	ScalarConverter::convert("-58.42f");
	ScalarConverter::convert("58.42f");
	return 0;
}
