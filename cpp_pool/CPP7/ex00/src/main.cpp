#include "whatever.hpp"
#include <iostream>

int main() {
	{
		char	a = 'a';
		char	b = 'b';
		std::cout	<< "a:    " << a			<< std::endl
					<< "b:    " << b			<< std::endl
					<< "min:  " << min(a , b)	<< std::endl
					<< "max:  " << max(a , b)	<< std::endl;
		swap(a, b);
		std::cout	<< "post swap: "			<< std::endl
					<< "a:    " << a			<< std::endl
					<< "b:    " << b			<< std::endl << std::endl;
	}
	{
		int	a = 42;
		int	b = 24;
		std::cout	<< "a:    " << a			<< std::endl
					<< "b:    " << b			<< std::endl
					<< "min:  " << min(a , b)	<< std::endl
					<< "max:  " << max(a , b)	<< std::endl;
		swap(a, b);
		std::cout	<< "post swap: "			<< std::endl
					<< "a:    " << a			<< std::endl
					<< "b:    " << b			<< std::endl << std::endl;
	}
	{
		double	a = 42.5;
		double	b = 47.9;
		std::cout	<< "a:    " << a			<< std::endl
					<< "b:    " << b			<< std::endl
					<< "min:  " << min(a , b)	<< std::endl
					<< "max:  " << max(a , b)	<< std::endl;
		swap(a, b);
		std::cout	<< "post swap: "			<< std::endl
					<< "a:    " << a			<< std::endl
					<< "b:    " << b			<< std::endl << std::endl;
	}
	return 0;
}
