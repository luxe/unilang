#pragma once
#include <iostream>
#include <string>
#include <vector>

class Cleaner{








 public: static void Clean_Dependencies_Of_Current_Dir();
 public: static void Clean_Listed_Dependencies_Of_Dir(std::vector<std::string> symbolic_pull_files);
 public: static void Clean_Dependencies_Recursively();
 public: static void Clean_All_Dependencies();
};