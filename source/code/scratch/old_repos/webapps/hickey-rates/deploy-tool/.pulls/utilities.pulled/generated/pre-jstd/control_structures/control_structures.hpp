#pragma once
#include <string>

//replaces most for loops that iterate an n number of times
template <typename F>
void repeat(unsigned n, F f) {
    while (n > 0) {f(); n -= 1;}
	return;
}
template <typename F>
void repeat(std::string n, F f) {
	mpz_class i (n);
    while (i > 0) {f(); i -= 1;}
	return;
}
template <typename F>
void repeat(const char* n, F f) {
	mpz_class i (n);
    while (i > 0) {f(); i -= 1;}
	return;
}
