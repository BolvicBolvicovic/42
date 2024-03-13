#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
void	convert_char(char c) {
	std::cout << "char  : " << c 						<< std::endl
			  << "int   : " << static_cast<int>(c)		<< std::endl
			  << "float : " << static_cast<float>(c)	<< ".0f" << std::endl
			  << "double: " << static_cast<double>(c)	<< ".0f" << std::endl;
}

void	convert_else(char *str) {
	double	num = atof(str);
	if (!num) {
		int	i = -1;
		while (iswhitespace(str[i])) {
			
		}
	}
}

void	ScalarConverter::convert(std::string str) {
	if		(str.length() == 1)	{ convert_char(str.c_str()[0]);		}
	else						{ convert_else(str.c_str());		}
}
