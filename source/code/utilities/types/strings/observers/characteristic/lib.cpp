#include "code/utilities/types/strings/observers/characteristic/lib.hpp"
#include "code/utilities/types/char/lib.hpp"

bool IsPalindrome(std::string str){
  return std::equal(str.cbegin(),str.cbegin() + str.size()/2,str.crbegin(),[](const char& a, const char& b){return a == b;});
}