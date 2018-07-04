#pragma once
#include <iostream>
#include <string>
#include <sstream>

void Disable_Console_Output();
void Enable_Console_Output();

template <typename Func>
std::string Capture_Output_Into_String(Func function){
  std::stringstream s;
  auto* old = std::cout.rdbuf();
  std::cout.rdbuf(s.rdbuf());
  function();
  std::cout.rdbuf(old);
  return s.str();
}
