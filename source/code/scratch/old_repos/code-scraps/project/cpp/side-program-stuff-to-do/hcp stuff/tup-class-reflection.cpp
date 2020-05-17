#include <iostream>
#include <string>
#include <tuple>
#include <vector>

class A{



  public: auto Get_Member_Variables() -> auto{
  return std::make_tuple(a,b,c);
  }

  private:
  int a = 5;
  float b = 3.14;
  std::string c = "hello";
  
  
};


int main(){

  A a;
  
  auto tup = a.Get_Member_Variables();
  std::get<0>(tup) = 9;
  std::cout << std::get<0>(tup) << std::endl;
  
    auto tup2 = a.Get_Member_Variables();
  std::cout << std::get<0>(tup2) << std::endl;
  
}
