#include "code/utilities/streams/output/lib.hpp"
#include <iostream>
void Print_To_Stdout(std::string s){
  std::cout << s;
}
void Print_To_Stderr(std::string s){
  std::cerr << s;
}
