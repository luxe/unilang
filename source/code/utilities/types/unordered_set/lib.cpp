#include "code/utilities/types/unordered_set/lib.hpp"
#include <algorithm>
#include <string>

std::unordered_set<char> Create_From_String(std::string const& str){
    
    std::unordered_set<char>  result;
    for (auto const& it: str){
        result.insert(it);
    }
    return result;
    
}

std::unordered_set<char> Get_Intersection(std::unordered_set<char> const& s1, std::unordered_set<char> const& s2){
    

// There is an algorithm called std::set_intersection which allows to find an intersection of two sorted ranges:
// As you deal with std::unordered_set, you cannot apply this algorithm because there is no guaranteed order for the elements in std::unordered_set.
auto set1 = To_Set(s1);
auto set2 = To_Set(s2);
    
    std::unordered_set<char> intersect;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                     std::inserter(intersect, intersect.begin()));

    return intersect;
}