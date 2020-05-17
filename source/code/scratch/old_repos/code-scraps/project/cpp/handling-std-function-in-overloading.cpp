#include <iostream>
#include <functional>
#include <cstdlib>

void Print_Wrapper(std::function<void(int)> function);
void Print(int param);
void Print(std::string param);

int main(){

  Print_Wrapper(static_cast<void(*)(int)>(Print));

  return EXIT_SUCCESS;
}

void Print_Wrapper(std::function<void(int)> function){
  int i = 5;
  function(i);
}
void Print(int param){
  std::cout << param << std::endl;
}
void Print(std::string param){
  std::cout << param << std::endl;
}