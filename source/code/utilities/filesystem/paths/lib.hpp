#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "boost/filesystem.hpp"
#include "code/utilities/program/call/lib.hpp"

//filesystem stuff


// bazel derived known repo paths
std::string Bazel_Working_Directory();
std::string Bazel_Workspace_Directory();
std::string Bazel_Derived_Root_Of_Repo();
std::string Bazel_Derived_Path_To_Self_Unilang();
std::string Bazel_Derived_Path_To_Essays();
std::string Bazel_Deps_Directory();
std::string Root_Readme_Directory();
std::string Bazel_External_Dep_Targets_Directory();

// moving into those known repo paths
void Move_To_Repo_Root();
void Move_To_Bazel_Derived_Path_To_Self_Unilang();
void Move_To_Bazel_Derived_Path_To_Essays();

//+---------------------------------------+
//| changing path / traversing filesystem |
//+---------------------------------------+
//THESE FUNCTIONS WILL CHANGE THE STATE OF THE CURRENT WORKING DIRECTORY.
//WHICH IS NOT THREAD SAFE.  THREADS SHARE THE SAME GLOBAL CWD.
void Set_Path(std::string const& path);
void Possibly_Set_Path(bool const& set, std::string const& path);
void Set_Path_If_Not_Empty(std::string const& path);
void Step_Into_Folder(std::string const folder_name);
void Step_Out_Of_Folder();
void Move_Back_Directories_Until_Directory_Exists(std::string root_directory_name);

//+-----------+
//| Observers |
//+-----------+

std::string Current_Folder_Name(void);
std::vector<std::string> Recursively_Get_All_Directories_From_Path(std::string const& path);
//std::string Trim_Off_Last_Directory_On_Path(std::string const& path);

	//+---------------+
	//| Getting Paths |
	//+---------------+
	std::vector<std::string> Current_Path_In_Parts(void);
	std::string Current_Path(void);
	std::string Full_Path(void);
	std::string Get_Path_Of_Directory_Starting_From_Root_Directory_Name(std::string root_directory_name);
	std::string Get_Path_Of_Directory_After_Found_Folder(std::string found_folder);
        std::string Get_Path_Of_Directory_After_Desktop();
	std::string Full_Path_To_Home();
	std::string Full_Path_To_Desktop();
	std::string Full_Path_For_Desktop_File(std::string const& file);
	std::string Full_Path_To_Home_Config_File(std::string const& config_for);
	std::string Full_Path_To_Home_File(std::string const& path);
	std::string Full_Path_For_Tmp_File(std::string const& file);

	//+--------------------+
	//| Checking Existence |
	//+--------------------+
	bool Directory_Exists_In_Current_Directory_Or_Any_Parents(std::string const& dir);
	bool Directory_Exists(std::string path_to_dir);

	//+----------------------------------+
	//| Get Numerical Data on Filesystem |
	//+----------------------------------+
	int Recursively_Get_Directory_Count(std::string const& path = ".");
	int Get_Number_Of_Files_In_Directory(std::string path = ".");
	unsigned int Number_Of_Directories_Deep_In_Root_Directory_Name(std::string root_directory_name);

//+--------------+
//| Transformers |
//+--------------+
void Create_Path_If_It_Doesnt_Already_Exist(std::string const& path);

//+--------------------------------------------------------+
//| Transforming AND changing path / traversing filesystem |
//+--------------------------------------------------------+
void Create_Path_If_It_Doesnt_Already_Exist_And_Step_Into_It(std::string const& path);
void Create_The_Path_Empty_And_Step_Into_It(std::string const& path);

//utility
void Shortify_Path(boost::filesystem::path & path);


template<typename Func>
void Temporarily_Move_To_Path_To_Call_Function(std::string const& path, Func f){
	auto current_path = Current_Path();
	Set_Path(path);
	f();
	Set_Path(current_path);
}
template<typename Func>
void Create_Path_And_Temporarily_Move_To_It_To_Call_Function(std::string const& path, Func f){
	exec_quietly("mkdir -p " + path);
	auto current_path = Current_Path();
	Set_Path(path);
	f();
	Set_Path(current_path);
}



template <typename Fun>
void For_Each_Line_Of_File(std::string const& path, Fun fun){
		
	  std::ifstream infile(path);
	  
      std::string str;
      std::getline(infile,str);
      while (infile){
         fun(str);
         std::getline(infile,str);
      }
}
