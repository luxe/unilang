#include <iostream>
#include <string>

//returns a colored string for terminal output streams
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-pedantic"
std::string colorize_forground(std::string const& message, int const& background) {
	return std::string("\e[38;5;" + std::to_string(background) + "m" + message + "\x1b[0m");
}
#pragma GCC diagnostic pop

int main() {
	std::cout << colorize_forground("hello world in green", 106) << '\n';
}
