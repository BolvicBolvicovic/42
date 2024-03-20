#pragma once
#include <cstdlib>
#include <iostream>

template <typename T>
void	iter(T *arr, size_t len, void f(T &)) {
	for (size_t i = 0; i < len; i++) {
		f(arr[i]);
	}
}

template <typename T>
void	printArg(T &arg) {
	std::cout << arg << std::endl;
}
