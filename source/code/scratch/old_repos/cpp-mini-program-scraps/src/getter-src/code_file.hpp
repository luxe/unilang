#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include "pre_check.hpp"

struct Code_File {

	//constructor
	Code_File(std::string const& url_tag_in, std::string const& time_in);

	//OBSERVERS
	//unique based on the url_tag and time stamp
	bool operator < (Code_File const& lhs) const;
	bool operator == (Code_File const& lhs) const;

	//gives all the data members as a single combined string for file naming
	std::string File_Name_Part() const;

	//data members
	std::string url_tag;
	std::string time;
};
