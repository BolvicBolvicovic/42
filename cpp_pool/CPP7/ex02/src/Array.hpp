#pragma once

#include <exception>

template <typename T>
class Array {
private:
	T arr[];
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &ref);
	~Array();

	Array	&operator=(Array &ref);
	T		&operator[](unsigned int n);

	unsigned int	size() const;

	class IndexOutOfBound: public exception {
		public:
			const char	*what() const throw() { return "Index out of bound."; }
	};
};
