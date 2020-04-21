#pragma once
#include <string>

//file path
std::string Get_File_Extension(std::string const& str);
bool File_Has_Extension(std::string const& path_to_file, std::string const& file_extension);
bool File_Has_Extension(std::string const& path_to_file);
std::string Get_File_Name(std::string const& str);
std::string Get_First_Folder_Name(std::string const& str);
bool File_Name_Starts_With(std::string const& str, std::string const& prefix);

std::string Prepend_Path_To_Program_Execution_Unless_Global_Call(std::string const& program_execution, std::string const& path);
std::string Prepend_Cd_Path(std::string const& program_execution, std::string const& path);


//base name
std::string Prepend_Onto_Basename(std::string const& path, std::string const& add);
std::string Append_onto_Basename(std::string const& path, std::string const& add);