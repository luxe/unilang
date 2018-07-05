#include "code/utilities/types/strings/transformers/appending/lib.hpp"
#include "code/utilities/converters/lib.hpp"
#include <algorithm>

std::string& Append_With_Newline(std::string & str_to_append_to, std::string const& append){
        str_to_append_to += append + "\n";
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

std::string& Append_N_Times(std::string & str, std::string const& part, unsigned int number_of_times){
        for (unsigned int i = 0; i < number_of_times; ++i){
                str+=part;
        }
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