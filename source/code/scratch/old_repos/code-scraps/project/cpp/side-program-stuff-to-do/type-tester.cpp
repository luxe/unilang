#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <fstream>
#include <memory>
#include <utility>

static const std::vector<std::string> TYPES 

//Miscellaneous
{"std::nullptr_t"

//boolean
,"bool"

//char
,"char"
,"signed char"
,"unsigned char"
,"wchar_t"
,"signed wchar_t"
,"unsigned wchar_t"
,"char16_t"
,"char32_t"

//shorts
,"short"
,"short int"
,"signed short"
,"signed short int"
,"unsigned short"
,"unsigned short int"

//ints
,"int"
,"signed"
,"signed int"
,"unsigned"
,"unsigned int"
,"size_t"
,"ptrdiff_t"

//longs
,"long"
,"long int"
,"signed long"
,"signed long int"
,"unsigned long"
,"unsigned long int"

//long longs
,"long long"
,"long long int"
,"signed long long"
,"signed long long int"
,"unsigned long long"
,"unsigned long long int"

//rational
,"float"
,"double"
,"long double"

//fixed width types <cstdint>
,"int8_t"
,"int16_t"
,"int32_t"
,"int64_t"
,"int_fast8_t"
,"int_fast16_t"
,"int_fast32_t"
,"int_fast64_t"
,"int_least8_t"
,"int_least16_t"
,"int_least32_t"
,"int_least64_t"
,"intmax_t"
,"intptr_t"
,"uint8_t"
,"uint16_t"
,"uint32_t"
,"uint64_t"
,"uint_fast8_t"
,"uint_fast16_t"
,"uint_fast32_t"
,"uint_fast64_t"
,"uint_least8_t"
,"uint_least16_t"
,"uint_least32_t"
,"uint_least64_t"
,"uintmax_t"
,"uintptr_t"};


void Test_Type(std::string type);

int main(){
    
    
//for (auto it: TYPES){
    Test_Type("int");
//}

  

}


void Test_Type(std::string type){

//beginning stuff:
std::ofstream outfile("type_test.cpp");
outfile << "#include <iostream>\n";
outfile << "#include <string>\n";
outfile << "#include <vector>\n";
outfile << "#include <cstdint>\n";
outfile << "#include <memory>\n";
outfile << "#include <utility>\n";

//all the functions:
for (auto it: TYPES){
    outfile << "void func(" << it << " a){}\n";
}

outfile << "int main(){\n";
outfile << type << " a;\n";
outfile << "func(a);\n";
outfile << "}\n";



}
