#include "ScalarConverter.hpp"
#include <iostream>

void	convert_char(char c) {
	std::cout << "char  : " << c 						<< std::endl
			  << "int   : " << static_cast<int>(c)		<< std::endl
			  << "float : " << static_cast<float>(c)	<< ".0f" << std::endl
			  << "double: " << static_cast<double>(c)	<< ".0f" << std::endl;
}

void	convert_int(int i) {
	
}

void	ScalarConverter::convert(std::string str) {
	if (str.length() == 1) { convert_char(str.c_str()[0]);		}
	else if (is_int(str))  { convert_int(atol(str.c_str()));	}
}
