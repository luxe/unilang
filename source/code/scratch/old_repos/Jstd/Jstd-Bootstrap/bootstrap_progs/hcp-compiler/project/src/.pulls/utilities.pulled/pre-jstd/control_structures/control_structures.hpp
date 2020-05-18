#pragma once
#include <string>

//when you don't actually care about the index, 
//use this to replace most for loops that iterate an n number of times
template <typename Function>
void repeat(Function f, unsigned int amount) {
    while (amount > 0) {f(); amount -= 1;}
	return;
}
template <typename Function>
void repeat(Function f, std::string amount) {
	mpz_class i (amount);
    while (i > 0) {f(); i -= 1;}
	return;
}
template <typename Function>
void repeat(Function f, const char* amount) {
	mpz_class i (amount);
    while (i > 0) {f(); i -= 1;}
	return;
}
template <typename Function>
void repeat(Function f, mpz_class amount) {
    while (amount > 0) {f(); amount -= 1;}
	return;
}
