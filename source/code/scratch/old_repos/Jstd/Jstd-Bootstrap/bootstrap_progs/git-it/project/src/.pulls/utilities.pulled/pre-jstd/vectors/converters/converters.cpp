std::string Get_As_String_With_Element_On_Each_Line(std::vector<std::string> const& vec){
    std::string str;
    for (auto const& it: vec){
        str+=it +'\n';
    }
    return str;
}
std::string Get_As_String_With_Space_In_Between_Each_Element(std::vector<std::string> v){
    std::string str;
    for (auto it = v.cbegin(); it != v.cend(); ++it){
        str += *it;
        if (it != v.cend()-1){
            str+= " ";
        }
    }
    return str;
}