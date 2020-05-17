#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
/*

*/
class Namespace_Generator{
	
	public: static void Generate_For_Class_Header(std::string const& file, std::string class_path);
	public: static void Generate_For_Class_Source(std::string const& file, std::string class_path);
	public: static void Generate_For_Main_Module(std::string const& file, std::string main_path);
	public: static void Generate_For_Main_Driver(std::string const& file, std::string main_path);
	
	//using statements for a class
	private: static void Use_The_Namespace_Of_Related_Classes_For_Class(std::ofstream & outfile, std::string const& class_path);
		private: static void Use_Namespace_For_Class(std::ofstream & outfile, std::string const& class_path, std::string const& class_name);
		
	//using statements for main module
	private: static void Use_The_Namespace_Of_Related_Classes_For_Main(std::ofstream & outfile, std::string main_path);
		private: static void Use_Namespace_For_Main(std::ofstream & outfile, std::string const& main_path, std::string const& class_name);
		
	//using statements for main driver
	private: static void Use_The_Namespace_Of_Related_Classes_For_Driver(std::ofstream & outfile, std::string main_path);
		private: static void Use_Namespace_For_Driver(std::ofstream & outfile, std::string const& main_path, std::string const& class_name);
	private: static void Use_The_Actual_Class(std::ofstream & outfile, std::string const& main_path);
		
	private: static std::string Generate_Namespace(std::string start_name);
	
	//utility
	private: static std::vector<std::string> Get_Dirs_Of_Path(std::string const& path);
	private: static std::string exec(std::string const& cmd);
	private: static std::string exec(const char* cmd);
	private: static bool File_Exists(std::string const& filename);

};