#pragma once
#include <string>
    
std::string Get_File_That_Symbolic_Link_Points_To(std::string const& path_to_symbolic_link);

//basically a diff
bool Files_Are_The_Same(const std::string& path_to_file1, const std::string& path_to_file2);

bool Folder_Has_C_Or_CPP_File(std::string folder_name);
