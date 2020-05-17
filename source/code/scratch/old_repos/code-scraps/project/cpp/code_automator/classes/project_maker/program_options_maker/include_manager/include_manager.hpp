#pragma once
#include <iostream>
#include <vector>
#include <string>
/*

*/
class Include_Manager{

	//Turning On A Header
	public: static bool Turn_On_Header(std::string const& include_parts_folder, std::string const& header_file);
		private: static bool Attempt_Turn_On(std::string const& full_path_file, std::string const& header_name);
	
	//Turning Off A Header
	public: static bool Turn_Off_Header(std::string const& include_parts_folder, std::string const& header_file);
		private: static bool Attempt_Turn_Off(std::string const& full_path_file, std::string const& header_name);
	
	private: static std::vector<std::string> Get_Files_Containing_Headers(std::string const& include_parts_folder);
	
	//utility
	private: static std::string exec(const char* cmd);

};