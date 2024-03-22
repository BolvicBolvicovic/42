#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &ref) { *this = ref; }

template <typename T>
MutantStack<T>::~MutantStack() { this->c.clear(); }

template <typename T>
MutantStack	&MutantStack<T>::operator=(const MutantStack &ref) { this->c = ref.c; }

template <typename T>	
iterator	MutantStack<T>::begin() { return this->c.begin(); }

template <typename T>
iterator	MutantStack<T>::end() { return this->c.end(); }
