#include <sys/stat.h>
#include <dirent.h>
#include <vector>
#include <string>

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

//getting files from a path
std::vector<std::string> Get_Everything_At_Path(std::string path = ".");
std::vector<std::string> Get_Symbolic_Links_Of_Path(std::string path = ".");
std::vector<std::string> Get_Dirs_Of_Path(std::string path = ".");
std::vector<std::string> Get_Regular_Files_Of_Path(std::string path = ".");
std::vector<std::string> Get_Sockets_Of_Path(std::string path = ".");
std::vector<std::string> Get_FIFO_Special_Files_Of_Path(std::string path = ".");
std::vector<std::string> Get_Character_Special_Files_Of_Path(std::string path = ".");
std::vector<std::string> Get_Block_Special_Files_Of_Path(std::string path = ".");
    std::vector<std::string> Get_Everything_At_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
    std::vector<std::string> Get_Symbolic_Links_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
    std::vector<std::string> Get_Dirs_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
    std::vector<std::string> Get_Regular_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
    std::vector<std::string> Get_Sockets_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
    std::vector<std::string> Get_FIFO_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
    std::vector<std::string> Get_Character_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
    std::vector<std::string> Get_Block_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");

    //recursively getting files from a path
    std::vector<std::string> Recursively_Get_All_Paths_To_Files_Of_Given_File_Extension_From_Path(std::string file_extension, std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_cpp_Files_Of_Path(std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_hpp_Files_Of_Path(std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_hcp_Files_Of_Path(std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_Directories_Of_Given_Name_From_Path(std::string directory_name, std::string const& path = ".");

