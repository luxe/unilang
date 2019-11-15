#pragma once
#include <string>

//file path
std::string Get_File_Extension(std::string const& str);
bool File_Has_Extension(std::string const& path_to_file, std::string const& file_extension);
bool File_Has_Extension(std::string const& path_to_file);
std::string Get_File_Name(std::string const& str);
std::string Get_First_Folder_Name(std::string const& str);
bool File_Name_Starts_With(std::string const& str, std::string const& prefix);