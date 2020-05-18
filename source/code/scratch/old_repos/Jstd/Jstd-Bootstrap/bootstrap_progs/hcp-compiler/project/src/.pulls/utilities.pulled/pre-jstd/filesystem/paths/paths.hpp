#pragma once
#include <string>
#include <vector>
#include <boost/filesystem.hpp>


//filesystem stuff

//+---------------------------------------+
//| changing path / traversing filesystem |
//+---------------------------------------+
//THESE FUNCTIONS WILL CHANGE THE STATE OF THE CURRENT WORKING DIRECTORY
void Set_Path(std::string const& path);
void Step_Into_Folder(std::string const folder_name);
void Step_Out_Of_Folder(void);
void Move_Back_Directories_Until_Directory_Exists(std::string root_directory_name);

//+-----------+
//| Observers |
//+-----------+

std::string Current_Folder_Name(void);

	//+---------------+
	//| Getting Paths |
	//+---------------+
	std::vector<std::string> Current_Path_In_Parts(void);
	std::string Current_Path(void);
	std::string Full_Path(void);
	std::string Get_Path_Of_Directory_Starting_From_Root_Directory_Name(std::string root_directory_name);

	//+--------------------+
	//| Checking Existence |
	//+--------------------+
	bool Directory_Exists_In_Current_Directory_Or_Any_Parents(std::string const& dir);

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
