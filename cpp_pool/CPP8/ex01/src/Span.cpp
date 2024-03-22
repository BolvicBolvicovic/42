#include "Span.hpp"
#include <climits>
#include <algorithm>

Span::Span() {}
Span::Span(unsigned int N)	:	size(N),
								shortest(INT_MAX),
								longest(0),
								container(new std::vector<int>(N)) 
								{ this->container->clear(); }

Span::Span(const Span &ref)	:	size(ref.size),
								shortest(ref.shortest),
								longest(ref.longest),
								container (new std::vector<int>(*ref.container)) {}

Span::~Span() { delete container; }

Span	&Span::operator=(const Span &ref) {
	delete this->container;
	this->container	= new std::vector<int>(*ref.container);
	this->size		= ref.size;
	this->shortest	= ref.shortest;
	this->longest	= ref.longest;
	return *this;
}

void	Span::addNumber(int nb) {
	if (this->container->size() < this->size) {
		this->container->push_back(nb);
		int	count = 0;
		for (std::vector<int>::iterator ptr = this->container->begin(); ptr < container->end(); ptr++) {
			this->longest = std::max(this->longest, (nb < *ptr ? *ptr - nb : nb - *ptr));
			if (nb == *ptr)
				count++;
			if (nb != *ptr || count > 1)
					this->shortest = std::min(this->shortest, (nb < *ptr ? *ptr - nb : nb - *ptr));
		}
	} else {
		throw Span::SpanFull();
	}
}
void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->size < this->container->size() + end - begin)
		throw Span::SpanFull();
	for (std::vector<int>::iterator ptr = begin; ptr < end; ptr++) {
		this->addNumber(*ptr);
	}
	
}

int		Span::shortestSpan() const {
	if (this->container->size() > 1)
		return this->shortest;
	else
		throw Span::NumberOfElementsTooSmall(); 
	return 0;
}

int		Span::longestSpan() const {
	if (this->container->size() > 1)
		return this->longest;
	else
		throw Span::NumberOfElementsTooSmall();
	return 0;
}
