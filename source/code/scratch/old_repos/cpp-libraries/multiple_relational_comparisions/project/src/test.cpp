#include <iostream>
#include "multiple_relational_comparing.hpp"

//test functions
bool yes(){
  std::cout << "True\n";
  return true;
}
bool no(){
  std::cout << "False\n";
  return false;
}
bool test(bool const& b){
  return b ? yes() : no();
}

int main(){

	std::vector<std::vector<int>> v{
		{1,2,3,4,2},
		{6,7,8},
    {1,5,1}
	};

  std::vector<std::vector<int>> s{{1,4,5,6,7,8,9,1},{1,2,3,4}};

  std::vector<std::vector<std::vector<int>>> d3{
    {{1,1,1},{1,1,1},{1,1,1}},
    {{1,1,1},{1,1,1},{1,1,1}},
    {{},{},{}} //make sure it handles empty containers also
  };


	test(5 == Any_Of(9,4,v));
  test(Any_Of(1,2,3) == Any_Of(4,5,6,s));


  test(1 >= Any_Of(2,3,4,5));

  test(d3 == All_Of(d3));
  
  std::vector<int> xx{1,2,3};
  int hi = 11;
  test(hi == Any_Of(xx));
  

}
