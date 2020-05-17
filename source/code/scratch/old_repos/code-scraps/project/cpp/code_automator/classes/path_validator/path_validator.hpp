#pragma once
#include <iostream>
#include "program_options/program_options.hpp"
#include <string>
/*

*/
class Path_Validator{
	public: static void Make_Sure_Program_Is_Run_In_The_Correct_Directory(Program_Options const& program_options);
		private: static void Ensure_Build_System_Is_Present(void);
		private: static void Ensure_Rules_Top_File_Is_Present(void);
		private: static void Test_Directory_Of_Task(std::vector<std::string> const& files, std::string const& error_message);

//utility
private: static std::string pwd_back(std::string const& path);
private: static std::string pwd(std::string to_get_path="pwd");
private: static std::string top();
private: static bool Is_Top(void);
private: static std::string build_dir();
private: static std::string exec(const char* cmd);
private: static bool File_Exists(std::string const& filename);


//constants
private: static const std::string TOP_RULES_FILE;
private: static const std::string TOP_CODE_FILE;
private: static const std::string BUILD_SYSTEM_FOLDER;
private: static const std::string MAKEFILE_NAME;
	
//both of these paths are relative from right outside the BUILD_SYSTEM_FOLDER

	//path to makefile with MAKEFILE_NAME in path
	private: static const std::string PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER;
	
	//path to makefile WITHOUT MAKEFILE_NAME in path
	private: static const std::string PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER2;

};