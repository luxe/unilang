#include <string>
#include <iostream>

template<typename ... Strings>void Output(const std::string& arg, const Strings&... rest);
void Output(const std::string& value);

int main() {
	Output("hello", "world", "we", "cool");
	Output();
	return 0;
}

template<typename ... Strings>void Output(const std::string& arg, const Strings&... rest) {
	std::cout<<arg<<" ";
	Output(rest...);
}
void Output(const std::string& value) {
	std::cout<< value << std::endl;
}