#include "code/utilities/types/vectors/converters/lib.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"

std::string Get_As_String_With_Element_On_Each_Line(std::vector<std::string> const& vec){
    std::string str;
    for (auto const& it: vec){
        str+=it +'\n';
    }
    return str;
}
std::string Get_As_String_With_Space_In_Between_Each_Element(std::vector<std::string> v){
    return Get_As_String_With_Delim_In_Between_Each_Element(v," ");
}
std::string Get_As_String_With_CommaSpace_In_Between_Each_Element(std::vector<std::string> v){
    return Get_As_String_With_Delim_In_Between_Each_Element(v,", ");
}
std::string Get_As_String_With_Comma_In_Between_Each_Element(std::vector<std::string> v){
    return Get_As_String_With_Delim_In_Between_Each_Element(v,",");
}
std::string Get_As_String_With_Forward_Slash_In_Between_Each_Element(std::vector<std::string> v){
   return Get_As_String_With_Delim_In_Between_Each_Element(v,"/");
}
std::string Get_As_String_With_Delim_In_Between_Each_Element(std::vector<std::string> v, std::string const& delim){
    std::string str;
    for (auto it = v.cbegin(); it != v.cend(); ++it){
        str += *it;
        if (it != v.cend()-1){
            str+= delim;
        }
    }
    return str;
}
std::vector<std::vector<int>> VecVecStringToVecVecInt(std::vector<std::vector<std::string>> const& lists){
    std::vector<std::vector<int>> results;
    
    for (auto const& it: lists){
        results.push_back(VecStringToVecInt(it));
    }
    
    return results;
}

std::vector<int> VecStringToVecInt(std::vector<std::string> const& list){
    std::vector<int> result;
    
    for (auto const& it: list){
        result.push_back(as_signed(it));
    }
    
    return result;
}
std::vector<long> VecStringToVecLong(std::vector<std::string> const& list){
    std::vector<long> result;
    
    for (auto const& it: list){
        result.push_back(as_signed(it));
    }
    
    return result;
}

std::vector<std::pair<char,int>> Get_As_Each_Element_A_Char_And_Int(std::vector<std::string> const& v){
    std::vector<std::pair<char,int>> result;
    
    for (auto it: v){
        char c = it[0];
        Remove_First_Char(it);
        int i = as_signed(it);
        result.emplace_back(c,i);
    }
    
    return result;
}
std::string Squeeze_Into_String(std::vector<std::string> vec){
    std::string str;
    for (auto const& it: vec){
        str+=it;
    }
    return str;
}
