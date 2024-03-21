#pragma once

template <typename T>
class Span {
private:
	Span();
	unsigned int	size;
	std::array container;
public:
	Span(unsigned int N);
	Span(const Span &ref);
	~Span();



	void	addNumber();
	int		shortestSpan();
	int		longestSpan();
};
