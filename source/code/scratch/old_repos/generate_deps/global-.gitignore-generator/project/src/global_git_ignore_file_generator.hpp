#pragma once
#include <iostream>
#include <string>

class Global_Git_Ignore_File_Generator{

	public: static void Generate_Ignore_File_At_Project_Root();

	private: static void Go_To_Root_And_Generate_File();
	private: static void Add_Ignore_Git_It_Generated_Files(std::ofstream & ignore_file);
	private: static void Add_Any_Generated_HPP_Or_CPP_Files(std::ofstream & ignore_file);
	private: static void Add_Any_Pulled_Folders_From_Pulls_Directory(std::ofstream & ignore_file);
	private: static void Add_Any_Symbolic_Links_To_Generated_Files(std::ofstream & ignore_file);


};