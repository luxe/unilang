#include <sys/stat.h>
#include <dirent.h>
#include <ctime>
#include <string>
#include <iostream>
#include <experimental/optional>


std::optional<std::time_t> Last_Modification_Time_If_File_Exists(std::string path_to_file){
  
  //starts out with no time, because we don't know if the file exists
  std::optional<std::time_t> potential_time;
  
  //if the file exists, we derive the last modification time
  if (File_Exists(path_to_file)){
    struct stat fileInfo;
    lstat(path_to_file.c_str(), &fileInfo);
    potential_time = fileInfo.st_mtime;
  }
  
  //return an optional modification time
  return potential_time;
}

int main(){

  auto before_time = Last_Modification_Time("here.txt");
  std::cout << before_time << std::endl;
}
