#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <cwchar>
#include <fstream>



int main(){
std::locale::global(std::locale("en_US.UTF-8"));
std::wstring wstr = L"ļ⚞";
std::wofstream out("test.dat");
std::wcout << wstr << std::endl;
out << wstr << std::endl;
std::cout << "random" << std::endl;
std::wifstream in("some_unicode.dat");
std::wstring wstr2;
std::getline(in,wstr2);

std::wcout << wstr2 << std::endl;
out << wstr2 << std::endl;



}
