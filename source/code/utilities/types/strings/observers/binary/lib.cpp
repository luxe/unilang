#include "code/utilities/types/char/lib.hpp"
#include "lib.hpp"

std::vector<std::string> To_Binary(std::string const& str){
	std::vector<std::string> result;
	for (auto it: str){
		result.emplace_back(As_Binary(it));
	}
	return result;
}
std::string From_Binary(std::vector<std::string> const& str){
	std::string result;
	for (auto it: str){
		result += From_Binary(it);
	}
	return result;
}