#pragma once
#include <iostream>
#include <vector>
#include <string>
/*

*/
class Project_Maker{

	public: static void Create_Project(std::string const& project_name, std::vector<std::string> const& main_module_names);
		private: static void Build_Main_Modules_Directory(std::string const& project_name, std::vector<std::string> const& main_module_names);
		private: static void Build_Classes_Directory(std::string const& project_name);
			private: static void Create_Program_Options_Class(std::string const& path);

};