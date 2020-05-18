size_t Get_Longest_String_Length_In_Vector(std::vector<std::string> const& v){
    return (*max_element ( v.begin(), v.end())).length();
}
bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str){
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}