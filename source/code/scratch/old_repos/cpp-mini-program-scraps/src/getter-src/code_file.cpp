#include "code_file.hpp"

//constructor
Code_File::Code_File(std::string const& url_tag_in, std::string const& time_in)
: url_tag(url_tag_in)
, time(time_in)
{}

//OBSERVERS

//unique based on the url_tag and time stamp
bool Code_File::operator < (Code_File const& lhs) const{
	std::string one = url_tag + time;
	std::string two = lhs.url_tag + lhs.time;
	return (one < two);
}
bool Code_File::operator == (Code_File const& lhs) const{
	std::string one = url_tag + time;
	std::string two = lhs.url_tag + lhs.time;
	return (one == two);
}
std::string Code_File::File_Name_Part() const{
	return url_tag + "-" + time;
}
