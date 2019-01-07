#include "code/utilities/types/wstrings/transformers/trimming/lib.hpp"
#include <algorithm>

std::wstring &ltrim(std::wstring &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
        return s;
}
std::wstring &rtrim(std::wstring &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c);}).base(), s.end());
        return s;
}
std::wstring &trim(std::wstring &s) {
        return ltrim(rtrim(s));
}