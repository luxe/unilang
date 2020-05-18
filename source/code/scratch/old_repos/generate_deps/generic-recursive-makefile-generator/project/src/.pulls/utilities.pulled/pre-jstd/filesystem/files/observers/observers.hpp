//checking characteristics of a single file
bool Is_Symbolic_Link(std::string path_to_file);
bool Is_Directory(std::string path_to_file);
bool Is_Regular_File(std::string path_to_file);
bool Is_A_Socket(std::string path_to_file);
bool Is_A_FIFO_Special_File(std::string path_to_file);
bool Is_A_Character_Special_File(std::string path_to_file);
bool Is_A_Block_Special_File(std::string path_to_file);

//checking the existence of a particular file
bool File_Exists(std::string const& filename);
    bool File_Exists_And_Is_Symbolic_Link(std::string path_to_file);
    bool File_Exists_And_Is_Directory(std::string path_to_file);
    bool File_Exists_And_Is_Regular_File(std::string path_to_file);
    bool File_Exists_And_Is_A_Socket(std::string path_to_file);
    bool File_Exists_And_Is_A_FIFO_Special_File(std::string path_to_file);
    bool File_Exists_And_Is_A_Character_Special_File(std::string path_to_file);
    bool File_Exists_And_Is_A_Block_Special_File(std::string path_to_file);
    
std::string Get_File_That_Symbolic_Link_Points_To(std::string const& path_to_symbolic_link);

//basically a diff
bool Files_Are_The_Same(const std::string& path_to_file1, const std::string& path_to_file2);



bool Folder_Has_C_Or_CPP_File(std::string folder_name);
