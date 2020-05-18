#pragma once
#include <iostream>
#include <string>
#include <vector>

class Updater{











 public: static void Update_Symbolic_Pull_Ins_For_Current_Directory();

 public: static void Update_Specific_Symbolic_Pull_Ins(std::vector<std::string> const& symbolic_pull_files);

 public: static void Update_Symbolic_Pull_Ins_Recursively();

 public: static void Update_Symbolic_Pull_Ins_For_The_Whole_Repo();};