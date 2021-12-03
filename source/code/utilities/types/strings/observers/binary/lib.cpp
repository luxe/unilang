#include "code/utilities/types/char/lib.hpp"
#include "lib.hpp"

std::vector<std::string> To_Binary(std::string const& str){
	std::vector<std::string> result;
	for (auto it: str){
		result.emplace_back(As_Binary(it));
	}
	return result;
}
std::string To_Binary_String(std::string const& str){
	std::string x;
	for (auto it: str){
		x += As_Binary(it);
	}
	return x;
}
std::string From_Binary(std::vector<std::string> const& str){
	std::string result;
	for (auto it: str){
		result += From_Binary(it);
	}
	return result;
}

unsigned long Binary_To_Decimal(std::string const& str){
	unsigned long value = std::stoull(str, 0, 2);
	return value;
}