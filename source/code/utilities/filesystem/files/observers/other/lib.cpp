#include "code/utilities/filesystem/files/observers/other/lib.hpp"
#include "code/utilities/filesystem/files/getting/lib.hpp"
#include "code/utilities/shell/lib.hpp"
#include <sstream>
#include <fstream>
#include <algorithm>

std::string Get_File_That_Symbolic_Link_Points_To(std::string const& path_to_symbolic_link){
  return execute("readlink " + path_to_symbolic_link);
}

bool Folder_Has_C_Or_CPP_File(std::string folder_name){
  auto f1 = Get_Regular_Files_Of_Path_With_The_File_Extension("c",folder_name);
  auto f2 = Get_Regular_Files_Of_Path_With_The_File_Extension("cpp",folder_name);
  return !f1.empty() || !f2.empty();
}

bool Files_Are_The_Same(const std::string& path_to_file1, const std::string& path_to_file2) {
  std::ifstream f1(path_to_file1, std::ifstream::binary|std::ifstream::ate);
  std::ifstream f2(path_to_file2, std::ifstream::binary|std::ifstream::ate);

  if (f1.fail() || f2.fail()) {
    return false; //file problem
  }

  if (f1.tellg() != f2.tellg()) {
    return false; //size mismatch
  }

  //seek back to beginning and use std::equal to compare contents
  f1.seekg(0, std::ifstream::beg);
  f2.seekg(0, std::ifstream::beg);
  return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                    std::istreambuf_iterator<char>(),
                    std::istreambuf_iterator<char>(f2.rdbuf()));
}

std::string Type_Of_File(std::string const& path){
  return execute("file -L -b -z -N " + path);
}