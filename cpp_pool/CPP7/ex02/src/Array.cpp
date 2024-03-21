#include "Array.hpp"
	
template <typename T>
Array<T>::Array(): arr(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): arr(new T[n]) _size(n) {}

template <typename T>
Array<T>::Array(const Array &ref): arr(new T[ref.size()]), _size(ref.size()) {
	for (unsigned int i = 0; i < this->_size; i++) {
		this->arr[i] = ref.arr[i];
	}
}

template <typename T>
Array<T>::~Array() { delete [] this->arr; }

template <typename T>
Array	&Array<T>::operator=(Array &ref) {
	delete [] this->arr;
	this->_size = ref.size();
	this->arr = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++) {
		this->arr[i] = ref.arr[i];
	}
	return *this;
}

template <typename T>
T		&Array<T>::operator[](unsigned int n) {
	if (n < this->_size && n > -1)
		return this->arr[n];
	else
		throw Array<T>::IndexOutOfBound();
}

template <typename T>
unsigned int	Array<T>::size() const { return this->_size; }
