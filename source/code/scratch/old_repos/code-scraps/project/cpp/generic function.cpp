#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

template <typename T, typename U>
auto
foo(T t, U u)
-> decltype(t(u))
{
	return t(u);
}
