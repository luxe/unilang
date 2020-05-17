#include <locale>
#include <codecvt>
#include <string>
#include <iostream>
#include <sstream>

int main(){


    std::string s{"おはよう"};
    //std::wstringstream ws;
    //ws << s.c_str();
    //std::wstring w = ws.str();
    //std::wcout << w << std::endl;
    
    
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::string narrow = converter.to_bytes(s);
    std::wstring wide = converter.from_bytes(s);
    
    std::cout << wide << std::endl;
}
