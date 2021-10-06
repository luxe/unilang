#include <iostream>
#include <string>

using namespace jstd;

int main(){

	std::string str = "hello universe";
	std::cout << uppercase(str) << '\n';

	char c = '7';
	std::cout <<  std::boolalpha;
	std::cout << is_alphanumeric(c) << '\n';
	std::cout << is_digit(c) << '\n';
	std::cout << is_prime_number(c) << '\n';
	std::cout << is_even_number(c) << '\n';
	std::cout << is_alpha(c) << '\n';
	std::cout << is_uppercase(c) << '\n';

}
