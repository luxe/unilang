#pragma once
#include <vector>
#include <string>
#include <utility>
#include <tuple>

class Warn_Log{


public:

	//compacts
	void Record_Duplicate_Compact(std::string const& file, std::string const& compact);
	void Record_Invalid_Compact(std::string const& file, int const& line_number, std::string const& problems);
	std::vector<std::pair<std::string,std::string>> Get_Duplicate_Compacts() const;
	std::vector<std::tuple<std::string,int,std::string>> Get_Invalid_Compacts() const;

private:

	//compacts
	std::vector<std::pair<std::string,std::string>> m_duplicated_compacts;
	std::vector<std::tuple<std::string,int,std::string>> m_invalid_compacts;
};
