#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <stack>
#include <cstdlib>

//-----FILE MANAGEMENT-----\\

void	output_result(std::ifstream file, std::ifstream database);

//-----ERROR HANDLING-----\\

class IncorrectFormat: public exception {
	public:
		const char	*what() const throw() {
			return "Panic: Incorrect Format";
		}
};

class InvalidDate: public exception {
	public:
		const char	*what() const throw() {
			return "Panic: Invalid Date";
		}
};

class InvalidValue: public exception {
	public:
		const char	*what() const throw() {
			return "Panic: Invalid Value";
		}
};
