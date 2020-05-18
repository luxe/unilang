
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

std::string Get_File_That_Symbolic_Link_Points_To(std::string const& path_to_symbolic_link){
  return execute("readlink " + path_to_symbolic_link);
}

bool Folder_Has_C_Or_CPP_File(std::string folder_name){
  auto f1 = Get_Regular_Files_Of_Path_With_The_File_Extension("c",folder_name);
  auto f2 = Get_Regular_Files_Of_Path_With_The_File_Extension("cpp",folder_name);
  return !f1.empty() || !f2.empty();
}
