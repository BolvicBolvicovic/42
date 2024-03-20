#pragma once

template <typename T>
void	swap(T &i, T &j) {
	T	tmp = i;
	i = j;
	j = tmp;
}

template <typename T>
T		min(T i, T j) {
	if (i < j)
		return i;
	return j;
}

template <typename T>
T		max(T i, T j) {
	if (j < i)
		return i;
	return j;
}
