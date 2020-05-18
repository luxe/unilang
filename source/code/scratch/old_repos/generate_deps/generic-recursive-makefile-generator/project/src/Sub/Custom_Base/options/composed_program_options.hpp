#pragma once
#include "utilities.hpp"
#include "systems.hpp"

class Composed_Program_Options{




public:

  //an organized composition of passed in command line options
  std::string program_name;
  bool move;
  std::vector<std::string> additional_libs;
 

};