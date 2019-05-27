#pragma once
#include <string>
#include <vector>

void Copy_Folder_To_Path(std::string folder_name, std::string directory_to_copy_to);
void Copy_Folder_Contents_To_Path(std::string folder_name, std::string directory_to_copy_to);
void Copy_Folder_Contents_To_Path_Only_If_Contents_Are_Different(std::string folder_name, std::string directory_to_copy_to);
void Copy_Files_To_Current_Directory(std::vector<std::string> const& files);
