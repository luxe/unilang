#pragma once
#include <iostream>
#include <string>
/*

*/
class Make_Putter{

	public: static void Hard_Link_The_Makefile(std::string const& path);
	private: static void Make_Hard_Link(std::string const& build_dir, std::string const& run_dir);
	
//utility
private: static std::string pwd_back(std::string const& path);
private: static std::string pwd(std::string to_get_path="pwd");
private: static std::string top();
private: static std::string build_dir();
private: static std::string exec(const char* cmd);
private: static bool File_Exists(std::string const& filename);

//constants
private: static const std::string TOP_RULES_FILE;
private: static const std::string BUILD_SYSTEM_FOLDER;
private: static const std::string MAKEFILE_NAME;
	
//both of these paths are relative from right outside the BUILD_SYSTEM_FOLDER

	//path to makefile with MAKEFILE_NAME in path
	private: static const std::string PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER;
	
	//path to makefile WITHOUT MAKEFILE_NAME in path
	private: static const std::string PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER2;
};