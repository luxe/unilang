#include "code/utilities/types/strings/observers/columns/lib.hpp"
#include <iterator>
#include <sstream>

//parsing out columns
std::vector<std::string> Get_Each_Column(std::string const& str){
	std::istringstream is{ str };
	const std::vector<std::string> parts{ std::istream_iterator<std::string>(is), std::istream_iterator<std::string>() };
	return parts;
}
std::string Get_Column_By_Index(std::string const& str, int index){
    return Get_Each_Column(str)[index];
}
std::string Get_1st_Column(std::string const& str){
	return Get_Column_By_Index(str,0);
}
std::string Get_2nd_Column(std::string const& str){
	return Get_Column_By_Index(str,1);
}
std::string Get_3rd_Column(std::string const& str){
	return Get_Column_By_Index(str,2);
}
std::string Get_4th_Column(std::string const& str){
	return Get_Column_By_Index(str,3);
}
std::string Get_5th_Column(std::string const& str){
	return Get_Column_By_Index(str,4);
}