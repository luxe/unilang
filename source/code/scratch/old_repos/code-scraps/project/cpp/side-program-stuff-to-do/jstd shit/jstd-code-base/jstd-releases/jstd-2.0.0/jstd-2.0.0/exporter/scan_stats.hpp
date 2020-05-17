#pragma once
#include "stat_timer.hpp"
#include <vector>
#include <string>

class Scan_Stats: public Stat_Timer{
	
	
public:
	
	//constructor
	Scan_Stats();
	
	//for warning stats
	void Record_Missing_File(std::string const& file);
	void Record_Not_Needed_File(std::string const& file);
	void Record_Duplicate_Header(std::string const& file, std::string const& header);
	void Record_Uneeded_Header(std::string const& file, std::string const& header);
	
	//for other stats
	void Store_If_Max_Depth(uint const& namespace_depth);

private:
	
	//warning stats
	std::vector<std::string> missing_files;
	std::vector<std::string> not_needed_files;
	std::vector<std::pair<std::string,std::string>> duplicated_headers;
	std::vector<std::pair<std::string,std::string>> uneeded_headers;
	
	//other stats
	uint max_namespace_depth; 

};
