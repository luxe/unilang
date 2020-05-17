#pragma once
#include<string>
#include<vector>
#include <boost/filesystem.hpp>


//filesystem stuff

//changing path
void Set_Path(std::string const& path);
void Step_Into_Folder(std::string const folder_name);
void Step_Out_Of_Folder(void);

// observing file system
std::string Full_Path(void);
std::string Current_Path(void);
std::string Current_Folder_Name(void);
bool File_Exists(std::string const& filename);
bool Directory_Exists_In_Current_Directory_Or_Any_Parents(std::string const& dir);
bool Inside_Git_Repository();
std::vector<std::string> Get_Dirs_Of_Path(std::string const& path);
std::vector<std::string> Get_Files_Of_Path(std::string const& path);
std::vector<std::string> Recursively_Get_All_Source_File_Paths_Of_Path(std::string const& path);
int Recursively_Get_Directory_Count(std::string const& path = ".");
int Get_Number_Of_Files_In_Directory(std::string const& path = ".");

//transforming file system
void Create_Path_If_It_Doesnt_Already_Exist(boost::filesystem::path const& path);

//utility
void Shortify_Path(boost::filesystem::path & path);
