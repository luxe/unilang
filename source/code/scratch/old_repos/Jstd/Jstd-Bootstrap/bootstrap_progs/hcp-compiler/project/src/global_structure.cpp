#include "global_structure.hpp"








//setters
void Global_Structure::Add_Header_Include(std::wstring const& include_name){
    header_includes.emplace_back(include_name,true);
}
void Global_Structure::Add_Source_Include(std::wstring const& include_name){
    source_includes.emplace_back(include_name,true);
}
void Global_Structure::Add_Character_To_Inheritance(wchar_t const& c){
    inheritance+=c;
}
void Global_Structure::Add_String_To_Inheritance(std::wstring const& str){
    inheritance+=str;
}
void Global_Structure::Add_Character_To_HPP_Code(wchar_t const& c){
    hpp_code+=c;
}
void Global_Structure::Add_Character_To_CPP_Code(wchar_t const& c){
    cpp_code+=c;
}
void Global_Structure::Add_Character_To_Both_HPP_and_CPP(wchar_t const& c){
    hpp_code+=c;
    cpp_code+=c;
}
void Global_Structure::Add_String_To_HPP_Code(std::wstring const& str){
    hpp_code+=str;
}
void Global_Structure::Add_String_To_CPP_Code(std::wstring const& str){
    cpp_code+=str;
}
void Global_Structure::Add_String_To_Both_HPP_and_CPP(std::wstring const& str){
    hpp_code+=str;
    cpp_code+=str;
}
void Global_Structure::Add_To_After_Headers_Portion(wchar_t const& c){
    everything_after_headers += c;
}
void Global_Structure::Add_File_Type(std::wstring const& str){
    file_type = str;
}
void Global_Structure::Add_Data_Member(std::wstring const& str){
    data_members.push_back(str);
}

//getters
std::vector<std::pair<std::wstring,bool>> Global_Structure::Header_Includes() const{
    return header_includes;
}
std::vector<std::pair<std::wstring,bool>> Global_Structure::Source_Includes() const{
    return source_includes;
}
std::wstring Global_Structure::Inheritance() const{
    return inheritance;
}
std::wstring Global_Structure::HPP_Code() const{
    return hpp_code;
}
std::wstring Global_Structure::CPP_Code() const{
    return cpp_code;
}
std::wstring Global_Structure::File_Type() const{
    return file_type;
}
std::vector<std::wstring> Global_Structure::Data_Members() const{
    return data_members;
}




