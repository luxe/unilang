#include "code/utilities/types/strings/transformers/trimming/lib.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include "code/utilities/converters/lib.hpp"
#include "code/utilities/std_hackery/lib.hpp"
#include "code/utilities/language_basic/control_structures/looping/lib.hpp"
#include <algorithm>
#include <functional>

//transforming string functions
std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
        return s;
}
std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c);}).base(), s.end());
        return s;
}
std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}
std::string& Trim_Each_Line(std::string &s){
        auto vec = Put_Each_Line_Of_String_Into_A_Vector(s);
        Transform(vec,static_cast<std::string& (*)(std::string&)>(&trim));
        s = Get_Each_Element_Of_Vector_As_A_Line_In_A_String(vec);
        return s;
}
std::string As_Left_Trimmed(std::string s){
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
        return s;
}
std::string As_Right_Trimmed(std::string s){
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c);}).base(), s.end());
        return s;
}
std::string As_Trimmed(std::string s){
        return ltrim(rtrim(s));
}