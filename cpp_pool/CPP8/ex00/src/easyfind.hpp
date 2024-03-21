#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
void		easyfind(const T &container, int n) {
	if (std::find(container, n) != container.end())
		std::cout << "found " << n << std::endl;
	else
		std::cout << "did not find " << n << std::endl;
}
