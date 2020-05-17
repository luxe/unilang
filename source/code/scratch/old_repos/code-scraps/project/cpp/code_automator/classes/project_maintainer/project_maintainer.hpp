#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

/*

*/
class Project_Maintainer{
	
	//-------------------//
	// MAIN MODULE STUFF //
	//-------------------//
	public: static void Update_All_Main_Module_Headers(std::string const& project_name);
		private: static void Update_Main_Module_Header(std::string const& main_module);
	public: static void Update_All_Main_Driver_Headers(std::string const& project_name);
		private: static void Update_Main_Driver_Header(std::string const& main_module, std::string const& got_ya);
		
	public: static void Update_All_Main_Module_Namespaces(std::string const& project_name);
	public: static void Update_All_Main_Driver_Namespaces(std::string const& project_name);
	
	public: static void Update_All_Main_Module_Direct_Relationships(std::string const& project_name);
		private: static void Update_Main_Module_Direct_Relationships(std::string const& main_module, std::vector<std::string> root_classes);
	public: static void Update_All_Main_Driver_Direct_Relationships(std::string const& project_name);
		private: static void Update_Main_Driver_Direct_Relationships(std::string const& main_module, std::vector<std::string> root_classes);
		
	public: static void Update_Main_Modules_Root_Rules_File(std::string const& project_name);
	
	public: static void Update_Class_Sub_Directory(std::string const& folder_path);
	public: static void Update_All_Main_Module_Direct_Relationships_Rules_File(std::string const& folder_path);
	
	public: static void Update_All_Main_Module_Dependencies(std::string folder_path);
		private: static void Update_Main_Module_Dependencies(std::string const& folder_path);
			private: static void Recursive_Object_Pickup(std::map<long,std::string> & objects,std::string const& object_path, int const& erase_amount);

	//utility
	private: static std::vector<std::string> Get_Dirs_Of_Path(std::string const& path);
	private: static std::string exec(std::string const& cmd);
	private: static std::string exec(const char* cmd);
	private: static long Get_I_Node_Number(std::string const& filename);
	
private: static std::string Skim_String(std::string str);
private: static std::string Skim_String2(std::string str);
private: static std::string Skim_String3(std::string str);
private: static bool File_Exists(std::string const& filename);

};