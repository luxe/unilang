#pragma once
#include <iostream>
#include <string>

/*

*/
class Driver_Maker{

public: static void Create_Main_Folder(std::string const& main_folder,std::string const& main_module_name);
	private: static void Build_Include_Portion(std::string const& path, std::string const& includes_file);

};