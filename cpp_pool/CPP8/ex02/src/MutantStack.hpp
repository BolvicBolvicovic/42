#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack: public Stack {
public:
	MutantStack();
	MutantStack(const MutantStack &ref);
	~MutantStack();
	MutantStack									&operator=(const MutantStack &ref);
	
	typedef typename std::deque<T>::iterator	iterator;
	iterator									begin();
	iterator									end();
};
