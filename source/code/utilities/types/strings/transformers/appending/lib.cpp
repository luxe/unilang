#include "code/utilities/types/strings/transformers/appending/lib.hpp"
#include "code/utilities/types/converters/lib.hpp"
#include <algorithm>

std::string& Append_With_Newline(std::string & str_to_append_to, std::string const& append){
        str_to_append_to += append + "\n";
        return str_to_append_to;
}
std::string& Append_With_Newline_Unless_Empty(std::string & str, std::string const& part){
        if (!part.empty()){
                Append_With_Newline(str,part);
        }
        return str;
}

std::string& Append_With_Newline(std::string & str_to_append_to, char const& append){
        str_to_append_to += append;
        str_to_append_to += "\n";
        return str_to_append_to;
}
std::string& Append_With_Space(std::string & str_to_append_to, std::string const& append){
        str_to_append_to += append + " ";
        return str_to_append_to;
}
std::string& Append_With_Space(std::string & str_to_append_to, char const& append){
        str_to_append_to += append;
        str_to_append_to += " ";
        return str_to_append_to;
}
std::string& Append(std::string & str, std::string const& part){
        str += part;
        return str;
}
std::string& Append(std::string & str, char const& part){
        str += part;
        return str;
}

std::string& Append_In_DQuotes(std::string & str, std::string const& part){
        str += '"';
        str += part;
        str += '"';
        return str;
}
std::string& Append_In_DQuotes(std::string & str, char const& part){
        str += '"';
        str += part;
        str += '"';
        return str;
}
std::string& Append_Key_Value(std::string & str, std::string const& key, std::string const& val){
        Append(str,key);
        Append(str,"=\"");
        Append(str,val);
        Append(str,"\" ");
        return str;
}

std::string& Append_N_Times(std::string & str, std::string const& part, unsigned int number_of_times){
        for (unsigned int i = 0; i < number_of_times; ++i){
                str+=part;
        }
        return str;
}
std::string& Append_A_Newline(std::string & str){
        str += "\n";
        return str;
}
std::string& Append_A_Space(std::string & str){
        str += " ";
        return str;
}
std::string& Append_A_Tab(std::string & str){
        str += "\t";
        return str;
}
std::string& Append_N_Newlines(std::string & str, int number_of_times)
{
        return Append_N_Times(str,"\n",number_of_times);
}
std::string& Append_N_Spaces(std::string & str, int number_of_times)
{
        return Append_N_Times(str," ",number_of_times);
}

std::string& Append_Bash_Comment_With_Newline(std::string & str, std::string const& part)
{
        str += "# ";
        str += part + "\n";
        return str;
}


std::string& Append_With_Newline(std::string & str_to_append_to, std::wstring const& append){
        str_to_append_to += as_string(append) + "\n";
        return str_to_append_to;
}
std::string& Append(std::string & str, std::wstring const& part){
        str += as_string(part);
        return str;
}
std::string& Append_N_Times(std::string & str, std::wstring const& part, unsigned int number_of_times){
        for (unsigned int i = 0; i < number_of_times; ++i){
                str+=as_string(part);
        }
        return str;
}