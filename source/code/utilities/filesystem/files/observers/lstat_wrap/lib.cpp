#include "code/utilities/filesystem/files/observers/lstat_wrap/lib.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <filesystem>
#include <algorithm>
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <unordered_map>

struct stat Lstat(std::string path_to_file){
  struct stat fileInfo;
  if (lstat(path_to_file.c_str(), &fileInfo) != 0){
    //failed to open
  }
  return fileInfo;
}

template <typename Fun>
void OnStat(std::string path_to_file, Fun fun){
    struct stat fileInfo;
    if (lstat(path_to_file.c_str(), &fileInfo) == 0){
        fun(fileInfo);
    }
    else{
      //file could not be stat'd.
      //it probably doesn't exist.
    }
}

//characteristics about a particular file
bool Is_Symbolic_Link(std::string path_to_file){
  struct stat fileInfo;
  if (lstat(path_to_file.c_str(), &fileInfo) == 0){
      return S_ISLNK(fileInfo.st_mode);
  }
  return false;
}
bool Is_Directory(std::string path_to_file){
  struct stat fileInfo;
    if (lstat(path_to_file.c_str(), &fileInfo) == 0){
      return S_ISDIR(fileInfo.st_mode);
     }
  return false;
}
bool Is_Regular_File(std::string path_to_file){
  struct stat fileInfo;
    if (lstat(path_to_file.c_str(), &fileInfo) == 0){
    return S_ISREG(fileInfo.st_mode);
           }
  return false;
}
bool Is_A_Socket(std::string path_to_file){
  struct stat fileInfo;
    if (lstat(path_to_file.c_str(), &fileInfo) == 0){
    return S_ISSOCK(fileInfo.st_mode);
    }
  return false;
}
bool Is_A_FIFO_Special_File(std::string path_to_file){
  struct stat fileInfo;
    if (lstat(path_to_file.c_str(), &fileInfo) == 0){
      return S_ISFIFO(fileInfo.st_mode);
    }
  return false;
}
bool Is_A_Character_Special_File(std::string path_to_file){
  struct stat fileInfo;
    if (lstat(path_to_file.c_str(), &fileInfo) == 0){
    return S_ISCHR(fileInfo.st_mode);
           }
  return false;
}
bool Is_A_Block_Special_File(std::string path_to_file){
  struct stat fileInfo;
    if (lstat(path_to_file.c_str(), &fileInfo) == 0){
    return S_ISBLK(fileInfo.st_mode);
           }
  return false;
}

size_t Last_Modified_Time_From_Epoch(std::string const& path_to_file)
{
  struct stat result;
  if (lstat(path_to_file.c_str(), &result) == 0){
      return result.st_mtime;
  }
  return 0;
}

//check existence of a file
bool File_Exists(std::string const& filename) {
    struct stat fileInfo;
    return lstat(filename.c_str(), &fileInfo) == 0;
}
bool File_Exists_And_Is_Symbolic_Link(std::string path_to_file){
    return Is_Symbolic_Link(path_to_file);
}
bool File_Exists_And_Is_Directory(std::string path_to_file){
    return Is_Directory(path_to_file);
}
bool File_Exists_And_Is_Regular_File(std::string path_to_file){
    return Is_Regular_File(path_to_file);
}
bool File_Exists_And_Is_A_Socket(std::string path_to_file){
    return Is_A_Socket(path_to_file);
}
bool File_Exists_And_Is_A_FIFO_Special_File(std::string path_to_file){
    return Is_A_FIFO_Special_File(path_to_file);
}
bool File_Exists_And_Is_A_Character_Special_File(std::string path_to_file){
    return Is_A_Character_Special_File(path_to_file);
}
bool File_Exists_And_Is_A_Block_Special_File(std::string path_to_file){
    return Is_A_Block_Special_File(path_to_file);
}