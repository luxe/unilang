#include "code/utilities/types/strings/observers/search/lib.hpp"
#include <string>

int countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
     offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}

long countSubstringOnRepeatingString(std::string str, long totalCharAmount, std::string const& subString){
    
     //the count we can see
     long count = countSubstring(str,subString);
    
    //predicting future pattern
    long howManyMore = (totalCharAmount / str.size()) - 1;
    long extraLetterCount = totalCharAmount % str.size();
    
    //additional based on full duplicates
    count += count*howManyMore;
    
    //additional based on partial duplicate
    str = str.substr(0, extraLetterCount);
    count += countSubstring(str,subString);
    
    return count;
}