#include "lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include "code/utilities/types/strings/observers/binary/lib.hpp"

std::wstring To_Watermark_From_Binary(std::string str){
	auto zero_char = Zero_Width_Non_Joiner();
	auto one_char = Zero_Width_Space();
	std::wstring result;
	for (auto it: str){
		if (it == '0'){
			result += zero_char;
		}
		else if (it == '1'){
			result += one_char;
		}
	}
	return result;
}
std::string From_Watermark_To_Binary(std::wstring str){
	auto zero_char = Zero_Width_Non_Joiner();
	auto one_char = Zero_Width_Space();
	std::string result;
	for (auto it: str){
		if (it == zero_char){
			result += "0";
		}
		else if (it == one_char){
			result += "1";
		}
	}
	return result;
}

std::vector<std::wstring> To_Watermark_From_Binary(std::vector<std::string> const& str){
	std::vector<std::wstring> result;
	for (auto it: str){
		result.emplace_back(To_Watermark_From_Binary(it));
	}
	return result;
}
std::vector<std::string> From_Watermark_To_Binary(std::vector<std::wstring> w){
	std::vector<std::string> result;
	for (auto it: w){
		result.emplace_back(From_Watermark_To_Binary(it));
	}
	return result;
}

//actual watermark converters
std::vector<std::wstring> Str_To_Watermark(std::string str){
	auto as_binary = To_Binary(str);
	auto watermark = To_Watermark_From_Binary(as_binary);
	return watermark;
}
std::string Watermark_To_Str(std::vector<std::wstring> str){
	auto as_binary = From_Watermark_To_Binary(str);
	auto s = From_Binary(as_binary);
	return s;
}

