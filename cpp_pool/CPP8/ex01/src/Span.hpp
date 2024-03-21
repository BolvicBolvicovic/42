#pragma once

#include <vector>

template <typename T>
class Span {
private:
	Span();
	unsigned int	size;
	std::vector		*container;
public:
	Span(unsigned int N);
	Span(const Span &ref);
	~Span();

	Span	&operator=(const Span &ref);

	void	addNumber(int nb);
	int		&shortestSpan() const;
	int		&longestSpan() const;
};
