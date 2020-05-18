
//characteristics about a particular file
bool Is_Symbolic_Link(std::string path_to_file){
	struct stat fileInfo;
	lstat(path_to_file.c_str(), &fileInfo);
	return S_ISLNK(fileInfo.st_mode);
}
bool Is_Directory(std::string path_to_file){
	struct stat fileInfo;
    lstat(path_to_file.c_str(), &fileInfo);
    return S_ISDIR(fileInfo.st_mode);
}
bool Is_Regular_File(std::string path_to_file){
	struct stat fileInfo;
    lstat(path_to_file.c_str(), &fileInfo);
    return S_ISREG(fileInfo.st_mode);
}
bool Is_A_Socket(std::string path_to_file){
	struct stat fileInfo;
    lstat(path_to_file.c_str(), &fileInfo);
    return S_ISSOCK(fileInfo.st_mode);
}
bool Is_A_FIFO_Special_File(std::string path_to_file){
	struct stat fileInfo;
    lstat(path_to_file.c_str(), &fileInfo);
    return S_ISFIFO(fileInfo.st_mode);
}
bool Is_A_Character_Special_File(std::string path_to_file){
	struct stat fileInfo;
    lstat(path_to_file.c_str(), &fileInfo);
    return S_ISCHR(fileInfo.st_mode);
}
bool Is_A_Block_Special_File(std::string path_to_file){
	struct stat fileInfo;
    lstat(path_to_file.c_str(), &fileInfo);
    return S_ISBLK(fileInfo.st_mode);
}

//check existence of a file
bool File_Exists(std::string const& filename) {
    struct stat fileInfo;
    return lstat(filename.c_str(), &fileInfo) == 0;
}
bool File_Exists_And_Is_Symbolic_Link(std::string path_to_file){
    if (File_Exists(path_to_file)){
        if (Is_Symbolic_Link(path_to_file)){
            return true;
        }
    }
    return false;
}
bool File_Exists_And_Is_Directory(std::string path_to_file){
    if (File_Exists(path_to_file)){
        if (Is_Directory(path_to_file)){
            return true;
        }
    }
    return false;
}
bool File_Exists_And_Is_Regular_File(std::string path_to_file){
    if (File_Exists(path_to_file)){
        if (Is_Regular_File(path_to_file)){
            return true;
        }
    }
    return false;
}
bool File_Exists_And_Is_A_Socket(std::string path_to_file){
    if (File_Exists(path_to_file)){
        if (Is_A_Socket(path_to_file)){
            return true;
        }
    }
    return false;
}
bool File_Exists_And_Is_A_FIFO_Special_File(std::string path_to_file){
    if (File_Exists(path_to_file)){
        if (Is_A_FIFO_Special_File(path_to_file)){
            return true;
        }
    }
    return false;
}
bool File_Exists_And_Is_A_Character_Special_File(std::string path_to_file){
    if (File_Exists(path_to_file)){
        if (Is_A_Character_Special_File(path_to_file)){
            return true;
        }
    }
    return false;
}
bool File_Exists_And_Is_A_Block_Special_File(std::string path_to_file){
    if (File_Exists(path_to_file)){
        if (Is_A_Block_Special_File(path_to_file)){
            return true;
        }
    }
    return false;
}
std::vector<std::string> Get_Everything_At_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if we need it, since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    std::string str;
    while ((entry = readdir(dp))){
        str = entry->d_name;
        if (str != "." && str != ".."){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Symbolic_Links_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_Symbolic_Link(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Dirs_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    std::string str;
    while ((entry = readdir(dp))){
        str = entry->d_name;
        if (str != "." && str != ".."){
            if (Is_Directory(path + entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Regular_Files_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_Regular_File(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Sockets_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_A_Socket(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_FIFO_Special_Files_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_A_FIFO_Special_File(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Character_Special_Files_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_A_Character_Special_File(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Block_Special_Files_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_A_Block_Special_File(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Everything_At_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //skip over the "." and ".."
    readdir(dp);
    readdir(dp);
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Symbolic_Links_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_Symbolic_Link(entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Dirs_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_Directory(entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Regular_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_Regular_File(entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Sockets_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_A_Socket(entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_FIFO_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_A_FIFO_Special_File(entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Character_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_A_Character_Special_File(entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Block_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_A_Block_Special_File(entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}

//these need changed
//I'd like to replace them with the file system traverser, and we should start pulling objects into the pre-jstd
//I don't really want the path to change for these function though; you know- thread safety
//I'll keep these shell call ones for now
std::vector<std::string> Recursively_Get_All_Paths_To_Files_Of_Given_File_Extension_From_Path(std::string file_extension, std::string const& path){
    auto str_1 = exec("find " + path + " -type f -name \\*." + file_extension + " 2>/dev/null;");
    auto str_2 = exec("find " + path + " -type l -name \\*." + file_extension + " 2>/dev/null;");
    auto vec = Put_Each_Line_Of_String_Into_A_Vector(str_1);
    vec += Put_Each_Line_Of_String_Into_A_Vector(str_2);
    return vec;
 }
std::vector<std::string> Recursively_Get_All_Paths_To_cpp_Files_Of_Path(std::string const& path){
    auto str_1 = exec("find " + path + " -type f -name \\*.cpp 2>/dev/null;");
    auto str_2 = exec("find " + path + " -type l -name \\*.cpp 2>/dev/null;");
    auto vec = Put_Each_Line_Of_String_Into_A_Vector(str_1);
    vec += Put_Each_Line_Of_String_Into_A_Vector(str_2);
    return vec;
 }
 std::vector<std::string> Recursively_Get_All_Paths_To_hpp_Files_Of_Path(std::string const& path){
    auto str_1 = exec("find " + path + " -type f -name \\*.hpp 2>/dev/null;");
    auto str_2 = exec("find " + path + " -type l -name \\*.hpp 2>/dev/null;");
    auto vec = Put_Each_Line_Of_String_Into_A_Vector(str_1);
    vec += Put_Each_Line_Of_String_Into_A_Vector(str_2);
    return vec;
 }
  std::vector<std::string> Recursively_Get_All_Paths_To_hcp_Files_Of_Path(std::string const& path){
    auto str_1 = exec("find " + path + " -type f -name \\*.hcp 2>/dev/null;");
    auto str_2 = exec("find " + path + " -type l -name \\*.hcp 2>/dev/null;");
    auto vec = Put_Each_Line_Of_String_Into_A_Vector(str_1);
    vec += Put_Each_Line_Of_String_Into_A_Vector(str_2);
    return vec;
 }
std::vector<std::string> Recursively_Get_All_Paths_To_Directories_Of_Given_Name_From_Path(std::string directory_name, std::string const& path){
	std::string str = exec("find " + path + " -type d -name " + directory_name + " 2>/dev/null;");
    auto vec = Put_Each_Line_Of_String_Into_A_Vector(str);

	return vec;
 }
