#pragma once
#include <string>

bool Inside_Git_Repository();
bool Git_Repo_Dirty();
bool Repo_Exists_On_Github(std::string const& user_name, std::string const& repo_name);
void Create_Repo_On_Github(std::string const& user_name, std::string const& autorization, std::string const& project_name, std::string const& description);

std::string Get_Path_Of_Directory_Starting_At_Git_Repo_Root(); //Get_Path_Of_Directory_Starting_At_Directory_Name(std::string directory_name);
void Go_To_Git_Repo_Root(); //Move_Back_Directories_Until_Directory_Exists(std::string directory_name);
unsigned int Number_Of_Directories_Deep_In_Git_Repo(); //unsigned int Number_Of_Directories_Deep_In_Folder_Name(std::string directory_name);
