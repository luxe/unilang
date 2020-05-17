#include <iostream>
#include <string>
#include "is_stl_container.hpp"

auto main() -> int{

	std::vector<int> i{1,2,3};
  auto& f = i;
	int j = 5;

  std::cout << std::boolalpha;
  std::cout << is_stl_container<std::vector<int>>::value << std::endl;
  std::cout << is_stl_container<std::vector<int>const&>::value << std::endl;
	std::cout << is_stl_container<int>::value << std::endl;
  
  //std::cout << Is_Int<int&>::value << std::endl;
  return 0;

}
