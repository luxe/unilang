#include "code/utilities/types/strings/observers/characteristic/lib.hpp"
#include "code/utilities/types/char/lib.hpp"

bool IsPalindrome(std::string str){
  return std::equal(str.cbegin(),str.cbegin() + str.size()/2,str.crbegin(),[](const char& a, const char& b){return a == b;});
}

bool IsMixedCase(std::string const& str)
{
    int hasUpper=0, hasLower=0;
    for (auto c: str)
    {
        hasUpper = hasUpper || (isalpha(c) && c == toupper(c));
        hasLower = hasLower || (isalpha(c) && c == tolower(c));
        
        if (hasLower && hasUpper){
          return true;
        }
    }
    return false;
}