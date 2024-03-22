#pragma once

#include <vector>
#include <exception>

class Span {
private:
	Span();
	unsigned int		size;
	int					shortest;
	int					longest;
	std::vector<int>	*container;
public:
	Span(unsigned int N);
	Span(const Span &ref);
	~Span();

	Span	&operator=(const Span &ref);

	void	addNumber(int nb);
	void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int		shortestSpan() const;
	int		longestSpan() const;

	class NumberOfElementsTooSmall: public std::exception {
		const char	*what() const throw() { return "Number of elements too small"; }
	};
	
	class SpanFull: public std::exception {
		const char	*what() const throw() { return "Span is full"; }
	};
};
