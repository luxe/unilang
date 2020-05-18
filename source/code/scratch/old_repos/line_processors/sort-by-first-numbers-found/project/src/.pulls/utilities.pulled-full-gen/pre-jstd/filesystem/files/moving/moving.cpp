void Copy_Folder_To_Path(std::string folder_name, std::string directory_to_copy_to){
    execute("cp -rf " + folder_name + " " + directory_to_copy_to);
}

void Copy_Folder_Contents_To_Path(std::string folder_name, std::string directory_to_copy_to){
    execute("cp -rf " + folder_name + "/* " + directory_to_copy_to);
}
