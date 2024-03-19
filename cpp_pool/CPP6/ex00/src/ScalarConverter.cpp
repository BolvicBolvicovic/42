#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

void	ScalarConverter::convert(std::string str) {
	int			toInt;
	float		toFloat;
	std::string	toChar;
	double		toDouble;

	std::string	[]infinity = ["+inf","-inf","nan","+inff","-inff","nanf"];
	bool		isInfinite = false;
	
	toDouble	= atof(str.c_str());
	toInt		= static_cast<int>(toDouble);
	toFloat		= static_cast<float>(toDouble);

	if (toInt >= 32 && toInt <= 126) {
		toChar = "'" + static_cast<char>(toInt) + "'"; 
	} else {
		toChar = "impossible";
	}

	for (int i = 0; i <= 5; i++) {
		if (infinity[i] == str)
			isInfinite = true;
	}

	if (!isInfinite && toInt == 0 && str[0] != 0 && str[1] != 0 && literal[0] != '+' && literal[0] != '-') {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (isInfinite) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << toInt << std::endl;
	}

	if (toFloat - static_cast<int>(tFloat) == 0) {
		std::cout << "float: "<< toFloat << ".0f" << std::endl;
		std::cout << "double: "<< toDouble << ".0" << std::endl;
	} else {
		std::cout << "float: "<< toFloat << "f" << std::endl;
		std::cout << "double: "<< toDouble << std::endl;
	}
}
