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

void	convert_int(long i) {
	if (i < INT_MIN || i > INT_MAX) {
		std::cerr	<< "error : overflow"					<< std::endl;
		return;
	}
	if (i >= 0 && i <= 255)
		std::cout	<< "char  : " << static_cast<char>(i)	<< std::endl;
	else
		std::cout	<< "char  : not allowed"				<< std::endl; 
	std::cout 		<< "int   : " << static_cast<int>(i)	<< std::endl
			  		<< "float : " << static_cast<float>(i)	<< ".0f" << std::endl
			  		<< "double: " << static_cast<double>(i)	<< ".0f" << std::endl;
}

void	convert_float(float f) {
	if (f >= 0 && f <= 255)
		std::cout	<< "char  : " << static_cast<char>(f)	<< std::endl;
	else
		std::cout	<< "char  : not allowed"				<< std::endl; 
	std::cout 		<< "int   : " << static_cast<int>(f)	<< std::endl
			  		<< "float : " << static_cast<float>(f)	<< "f" << std::endl
			  		<< "double: " << static_cast<double>(f)	<< "f" << std::endl;
}

bool	is_int(const char *str) {
	int	i = -1;
	if (str[0] == '-') { i++; }
	while (str[++i])
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

bool	is_float(const char *str) {
	int	i = -1;
	int	dots = 0;
	if (str[0] == '-') { i++; }
	while (str[++i]) {
		if (str[i] == '.')
			dots++;
		if (!std::isdigit(str[i]) && (dots > 1 || !dots) && str[i] != 'f')
			return false;
		if (!str[i + 1] && str[i] == 'f' && dots == 1)
			return true;
		else if (str[i] == 'f')
			return false;
	}
	return true;
}

void	ScalarConverter::convert(std::string str) {
	if (str.length() == 1) 			{ convert_char(str.c_str()[0]);		}
	else if (is_int(str.c_str()))	{ convert_int(atol(str.c_str()));	}
	else if (is_float(str.c_str()))	{ convert_float(atof(str.c_str()));	}
}
