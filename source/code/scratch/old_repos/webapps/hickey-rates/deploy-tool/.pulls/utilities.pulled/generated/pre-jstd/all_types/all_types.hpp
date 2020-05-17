#pragma once
#include <algorithm>

// making default functions for where a full iterator range is presumed from a container being passed in
template <typename T>
void Shuffle(T & container) {
	std::shuffle(container.begin(), container.end());
}

template <typename T>
void Sort(T & container) {
	std::sort(container.begin(), container.end());
}
