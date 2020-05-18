#include <sstream>
#include <cctype>
#include <map>
#include <utility>
#include <string>
#include <boost/algorithm/string/predicate.hpp>

std::vector<int> Collect_Whitespace_Separated_Numbers(std::string const& s){
        auto parts = Get_Each_Column(s);
        std::vector<int> numbers;
        for (auto it: parts){
                numbers.push_back(as_signed(it));
        }
        return numbers;
}

//both
std::string& Remove_First_And_Last_Char(std::string & str){
        Remove_First_Char(str);
        Remove_Last_Char(str);
        return str;
}

std::vector<char> Convert_To_Vec_Of_Chars(std::string const& str){
        std::vector<char> all;
        for (auto it: str){
                all.push_back(it);
        }
        return all;
}


std::string& Add_Prefix_To_Each_Line(std::string & str, std::string const& prefix){
        std::string new_str = prefix;
        
        for (auto const& it: str){
                new_str += it;
                if (it == '\n'){
                        new_str += prefix;
                }
        }
        
        str = new_str;
        return str;
}

std::string& Add_Prefix_To_All_Lines_Except_First(std::string & str, std::string const& prefix){
        std::string new_str;
        
        for (auto const& it: str){
                new_str += it;
                if (it == '\n'){
                        new_str += prefix;
                }
        }
        
        str = new_str;
        return str;
}

std::string As_NonAlphas_Removed(std::string const& str){
        std::string new_str;
        
        for (auto const& it: str){
                if (Is_An_Alpha_Character(it)){
                        new_str += it;
                }
        }
        
        return new_str;
}
std::string& Append_With_Newline(std::string & str_to_append_to, std::string const& append){
        str_to_append_to += append + "\n";
        return str_to_append_to;
}
std::string& Append(std::string & str, std::string const& part){
        str += part;
        return str;
}
std::string& Remove_All_Instances_Of_Char(std::string & str, char const& c){
        std::string new_str;
        for (auto it: str){
                if (it != c){
                        new_str += it;
                }
        }
        str = new_str;
        return str;
}
std::string& Append_N_Times(std::string & str, std::string const& part, unsigned int number_of_times){
        for (unsigned int i = 0; i < number_of_times; ++i){
                str+=part;
        }
        return str;
}
//---
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

std::string& CapitalizeFirstChar(std::string & s){
        if (!s.empty()){
                s[0] = toupper(s[0]);
        }
}
std::string& LowercaseFirstChar(std::string & s){
        if (!s.empty()){
                s[0] = tolower(s[0]);
        }        
}
//--



std::string& Turn_Any_Whitespace_Chars_Into_A_Space(std::string & str){
        for (auto & it: str){
                if (Is_A_Whitespace_Character(it)){
                        it = ' ';
                }
        }
        return str;
}

//transforming string functions
std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}
std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
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

std::string& Squeeze_Away_Spaces(std::string &s){
    std::string::iterator new_end = std::unique(s.begin(), s.end(), [](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); });
    s.erase(new_end, s.end());
    return s;
}
std::string As_Left_Trimmed(std::string s){
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}
std::string As_Right_Trimmed(std::string s){
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}
std::string As_Trimmed(std::string s){
        return ltrim(rtrim(s));
}
std::string As_Spaces_Squeezed_Away(std::string s){
    std::string::iterator new_end = std::unique(s.begin(), s.end(), [](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); });
    s.erase(new_end, s.end());
    return s;
}
std::string& Reverse(std::string & str){
        std::reverse(std::begin(str), std::end(str));
        return str;
}
std::string As_Reversed(std::string str){
        return Reverse(str);
}
std::string& Empty_String_If_It_Only_Contains_Whitespace(std::string & str){
         if (Contains_Only_Whitespace_Characters(str)){
                str.clear();
        }
        return str;
}
std::string As_Empty_String_If_It_Only_Contains_Whitespace(std::string str){
         if (Contains_Only_Whitespace_Characters(str)){
                str.clear();
        }
        return str;
}

std::string& Squeeze_Away_Spaces_On_String(std::string &s){
    return Squeeze_Away_Spaces(s);
}

std::string& Remove_Match_If_It_Is_Found_At_Beginning_Or_End(std::string & str, std::string const& match){
        if (Begins_Or_Ends_With(str,match)){
                Remove_Match_Found_At_Beginning_Or_End(str,match);
        }
        return str;
}

std::string& Remove_Match_If_It_Is_Found_At_Beginning(std::string & str, std::string const& match){
        if (Begins_With(str,match)){
                Remove_Match_Found_At_Beginning(str,match);
        }
        return str;
}
std::string& Remove_Match_If_It_Is_Found_At_End(std::string & str, std::string const& match){
        if (Ends_With(str,match)){
                Remove_Match_Found_At_End(str,match);
        }
        return str;
}

std::string& Remove_Match_Found_At_Beginning_Or_End(std::string & str, std::string const& match){
        Remove_Match_Found_At_Beginning(str,match);
        Remove_Match_Found_At_End(str,match);
        return str;
}
std::string& Remove_Match_Found_At_Beginning(std::string & str, std::string const& match){
        if (Begins_With(str,match)){
                Remove_First_N_Chars(str,match.size());
        }
        return str;
}
std::string& Remove_Match_Found_At_End(std::string & str, std::string const& match){
        if (Ends_With(str,match)){
                Remove_Last_N_Chars(str,match.size());
        }
        return str;
}

std::string& Remove_All_Beginning_Characters_That_Match_Any_Of_The_Following_Characters(std::string & str, std::string const& chars){
        while(Contains(chars,First_Char(str))){
                str.erase(0,1);
        }
        return str;
}

std::string& Remove_Matching_Beginning_Part_Of_String(std::string & str, std::string const& match){
        
        auto min = std::min(str.size(),match.size());
        
        int count = 0;
        for (int i = 0; i < min; ++i){
                if (str[i] == match[i]){
                        ++count;
                }else{
                        break;
                }
        }
        Remove_First_N_Chars(str, count);
        
        return str;
}
std::string As_Beginning_Matching_Part_Of_String_Removed(std::string const& str, std::string const& match){
        
        auto min = std::min(str.size(),match.size());
        std::string new_string;
        
        int count = 0;
        for (int i = 0; i < min; ++i){
                if (str[i] == match[i]){
                        ++count;
                }else{
                        break;
                }
        }
        new_string = str;
        Remove_First_N_Chars(new_string, count);
        
        return new_string;
}
std::string& Keep_Matching_Beginning_Part_Of_String(std::string & str, std::string const& match){
        
        auto min = std::min(str.size(),match.size());
        
        int count = 0;
        for (int i = 0; i < min; ++i){
                if (str[i] == match[i]){
                        ++count;
                }else{
                        break;
                }
        }
        Keep_Only_First_N_Characters(str, count);
        
        return str;
}
std::string As_Beginning_Matching_Part_Of_String_Kept(std::string const& str, std::string const& match){
        
        auto min = std::min(str.size(),match.size());
        std::string new_string;
        
        int count = 0;
        for (int i = 0; i < min; ++i){
                if (str[i] == match[i]){
                        ++count;
                }else{
                        std::cout << "break" << std::endl;
                        break;
                }
        }
        new_string = str;
        Keep_Only_First_N_Characters(new_string, count);
        
        return new_string;
}

std::string& Keep_Only_First_N_Characters(std::string & str, unsigned int const& count){
        std::string new_string;
        for (int i = 0; i < count; ++i){
                if (i == count){
                        break;
                }
             if (i > str.size()-1){
                     break;
             }else{
                   new_string += str[i];   
             }
        }
        str = new_string;
        return str;
}

std::string& Escape_Double_Quote_String_Content_For_Shell(std::string & str){
        std::string new_string;
        for (auto const& it: str){
                if (it == None_Of('!','$','"','\\')){
                        new_string += it;
                }else{
                        new_string += '\\';
                        new_string += it;
                }
        }
        str = new_string;
        return str;
}
std::string As_Escaped_Double_Quote_String_Content_For_Shell(std::string str){
        std::string new_string;
        for (auto const& it: str){
                if (it == None_Of('!','$','"','\\')){
                        new_string += it;
                }else{
                        new_string += '\\';
                        new_string += it;
                }
        }
        return new_string;
}
std::string& Escape_Single_Quote_String_Content_For_Shell(std::string & str){
        std::string new_string;
        for (auto const& it: str){
                if (it == None_Of('\'')){
                        new_string += it;
                }else{
                        new_string += "'\"'\"'";
                }
        }
        str = new_string;
        return str;
}
std::string As_Escaped_Single_Quote_String_Content_For_Shell(std::string str){
        std::string new_string;
        for (auto const& it: str){
                if (it == None_Of('\'')){
                        new_string += it;
                }else{
                        new_string += "'\"'\"'";
                }
        }
        return new_string;
}

std::string& Append_To_Front(std::string & str, std::string const& part){
        str = part + str;
        return str;
}
std::string& Append_To_Back(std::string & str, std::string const& part){
        str += part;
        return str;
}
std::string& Append_To_Front_Of_Each_Line(std::string & str, std::string const& part){
        std::string new_str = part;
        for (auto const& it: str){
                new_str+=it;
                if (it == '\n'){new_str+= part;}
        }
        
        str = new_str;
        return str;
}
std::string& Append_To_Back_Of_Each_Line(std::string & str, std::string const& part){
        std::string new_str;
        for (auto const& it: str){
                if (it == '\n'){new_str+= part;}
                new_str+=it;
        }
        new_str += part;
        str = new_str;
        return str;
}

std::string& Indent_Each_Line(std::string & str, int indent_amount){
        auto indents = Create_String_Of_N_Spaces(indent_amount);
        Append_To_Front_Of_Each_Line(str,indents);
        return str;
}

std::string& Wrap_In_Single_Quotes(std::string & str){
        str = "'" + str + "'";
        return str;
}
std::string As_Wrapped_In_Single_Quotes(std::string str){
        str = "'" + str + "'";
        return str;
}
std::string& Wrap_In_Double_Quotes(std::string & str){
        str = "\"" + str + "\"";
        return str;
}
std::string As_Wrapped_In_Double_Quotes(std::string str){
        str = "\"" + str + "\"";
        return str;
}

//changing front and back
std::string& Remove_First_Char(std::string &s){
    if (!s.empty()){
        s.erase(0,1);
    }
    return s;
}
std::string& Remove_Last_Char(std::string &s){
    if (!s.empty()){
        s.pop_back();
    }
    return s;
}
std::string As_First_Char_Removed(std::string const& s){
    std::string new_string = s;
    return Remove_First_Char(new_string);
}
std::string As_Last_Char_Removed(std::string const& s){
    std::string new_string = s;
    return Remove_Last_Char(new_string);
}

std::string& Remove_All_Chars_From_Front_Until_Char_Is_Seen(std::string & str, char const& c){
    bool seen = false;
    while(1){
        if (str.empty()){
            break;
        }else{
            if(str[0] == c){
                break;
            }else{
                str.erase(0,1);
            }
        }
    }
    return str;
}
std::string& Remove_All_Chars_From_Back_Until_Char_Is_Seen(std::string & str, char const& c){
    bool seen = false;
    while(1){
        if (str.empty()){
            break;
        }else{
            if(Last_Char(str) == c){
                break;
            }else{
                Remove_Last_Char(str);
            }
        }
    }
    return str;
}

std::string As_All_Chars_Removed_From_Back_Until_Char_Is_Seen(std::string str, char const& c){
    bool seen = false;
    while(1){
        if (str.empty()){
            break;
        }else{
            if(Last_Char(str) == c){
                break;
            }else{
                Remove_Last_Char(str);
            }
        }
    }
    return str;
}

std::string& Remove_All_Chars_From_Front_Until_Char_Is_Seen_A_Number_Of_Times(std::string & str, char const& c, unsigned int number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        Remove_All_Chars_From_Front_Until_Char_Is_Seen(str,c);
        if (i < number_of_times-1){
            Remove_First_Char(str);
        }
    }
    return str;
}
std::string& Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(std::string & str, char const& c, unsigned int number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        Remove_All_Chars_From_Back_Until_Char_Is_Seen(str,c);
        if (i < number_of_times-1){
            Remove_Last_Char(str);
        }
    }
    return str;
}

std::string& Remove_First_N_Chars(std::string & str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.erase(0,1);
        }else{
            return str;
        }
    }
    return str;
}
std::string& Remove_Last_N_Chars(std::string & str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.pop_back();
        }else{
            return str;
        }
    }
    return str;
}

std::string As_First_N_Chars_Removed(std::string str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.erase(0,1);
        }else{
            return str;
        }
    }
    return str;
}
std::string As_Last_N_Chars_Removed(std::string str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.pop_back();
        }else{
            return str;
        }
    }
    return str;
}

std::string& Remove_N_Chars_From_Front_And_Back(std::string & str, unsigned int const& number_of_times){
    return Remove_First_N_Chars(Remove_Last_N_Chars(str,number_of_times),number_of_times);
}
std::string As_N_Chars_Removed_From_Front_And_Back(std::string str, unsigned int const& number_of_times){
    return As_First_N_Chars_Removed(As_Last_N_Chars_Removed(str,number_of_times),number_of_times);
}

std::string& Remove_Suffix(std::string &s) {
    auto it = s.rfind(".");
    if (it !=  std::string::npos) {
        s.erase(it, s.size());
    }
    return s;
}
std::string As_Removed_Suffix(std::string s) {
    auto it = s.rfind(".");
    if (it !=  std::string::npos) {
        s.erase(it, s.size());
    }
    return s;
}

std::string& Add_File_Extension(std::string &s, std::string const& extension){
    s+="." + extension;
    return s;
}
std::string As_Added_File_Extension(std::string s, std::string const& extension){
    return s+"." + extension;
}

std::string& Replace_File_Extension(std::string &s, std::string const& new_extension){
    Add_File_Extension(Remove_Suffix(s),new_extension);
    return s;
}
std::string As_Replaced_Extension(std::string s, std::string const& new_extension){
    return As_Added_File_Extension(As_Removed_Suffix(s),new_extension);
}

std::string& Move_First_Word_Of_String_To_The_End(std::string & str){
        auto start_and_length = Get_Start_Position_And_Length_Of_First_Word(str);
        auto word = str.substr (start_and_length.first,start_and_length.second);
        str.erase(start_and_length.first,start_and_length.second);
        str+=word;
        return str;
}
std::string As_First_Word_Of_String_Moved_To_The_End(std::string str){
        return Move_First_Word_Of_String_To_The_End(str);
}

//changing the end of a string (assuming it's a directory name)
std::string Get_Path_As_A_Number_Of_Directories_Back(std::string dir_name, unsigned int const& amount_back){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',amount_back);
    return dir_name;
}
std::string Get_Path_As_One_Directories_Back(std::string dir_name){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',1);
    return dir_name;
}
std::string Get_Path_As_Two_Directories_Back(std::string dir_name){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',2);
    return dir_name;
}
std::string Get_Path_As_Three_Directories_Back(std::string dir_name){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',3);
    return dir_name;
}

//casing
std::string& Uppercase(std::string &str){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
std::string& Lowercase(std::string &str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
std::string As_Uppercase(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
std::string As_Lowercase(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
std::string As_Camel_Case(std::string s){
        return As_Capital_And_Pushed_Together(s);
}
std::string As_Lower_Camel_Case(std::string s){
        auto new_s = As_Capital_And_Pushed_Together(s);
        LowercaseFirstChar(new_s);
        return new_s;
}
std::string As_Capital_And_Pushed_Together(std::string s){
        auto it = Make_Capital_And_Underscored_In_User_Type_Format(s);
        auto next = string_replace_all(it,"_","");
        return string_replace_all(next," ","");
}
std::string As_Capital_And_Pushed_Together_Preserve_Underscores_With_Lowercase_After(std::string s){
        auto str = As_Capitalized(s);
        return string_replace_all(str," ","");
}

std::string Capitalize_Each_With_Space_In_Between(std::string s){
        auto it = Make_Capital_And_Underscored_In_User_Type_Format(s);
        return string_replace_all(it,"_"," ");
}
std::string Make_Capital_And_Underscored_In_User_Type_Format(std::string s) {

    trim(s);
    Squeeze_Away_Spaces(s);

    //turn spaces into underscores and capitalize each letter
    bool was_space = true; // <- capitalize the first character every time
    for (auto & it: s){
        if (it == ' ' || it == '_'){
            it ='_';
            was_space = true;
        }else{
            if (was_space){
                it = static_cast<char>(toupper(it));
                was_space = false;
            }
        }
    }

    return s;
}
std::string As_Capitalized(std::string s){
       trim(s);
       Squeeze_Away_Spaces(s); 
       
    //capitalize each letter after a space
    bool was_space = true; // <- capitalize the first character every time
    for (auto & it: s){
        if (it == ' '){
            was_space = true;
        }else{
            if (was_space){
                it = static_cast<char>(toupper(it));
                was_space = false;
            }
        }
    }

    return s;
}
std::string As_All_Capital_Letters_With_Spaces_As_Underscores(std::string s) {

    trim(s);
    Squeeze_Away_Spaces(s);
    for (auto & it: s){
        if (it == ' '){ it ='_'; }
        else { it = static_cast<char>(toupper(it)); }
    }

    return s;
}
std::string As_All_Lowercase_Letters_With_Spaces_As_Underscores(std::string s){
    trim(s);
    Squeeze_Away_Spaces(s);
    for (auto & it: s){
        if (it == ' '){ it ='_'; }
        else { it = static_cast<char>(tolower(it)); }
    }

    return s;
}
std::string As_All_Lowercase_Letters_With_Underscores_As_Spaces(std::string s){
    trim(s);
    Squeeze_Away_Spaces(s);
    for (auto & it: s){
        if (it == '_'){ it =' '; }
        else { it = static_cast<char>(tolower(it)); }
    }

    return s;
}

std::string string_replace_first_instance( std::string src, std::string const& target, std::string const& repl){
    // handle error situations/trivial cases

    if (target.length() == 0 || src.length() == 0) {
        return src;
    }

    size_t idx = 0;

        idx = src.find( target, idx);

        src.replace( idx, target.length(), repl);
        idx += repl.length();

    return src;
}
std::string string_replace_all( std::string src, std::string const& target, std::string const& repl){

    if (target.length() == 0) {
        // searching for a match to the empty string will result in
        //  an infinite loop
        //  it might make sense to throw an exception for this case
        return src;
    }

    if (src.length() == 0) {
        return src;  // nothing to match against
    }

    size_t idx = 0;

    for (;;) {
        idx = src.find( target, idx);
        if (idx == std::string::npos)  break;

        src.replace( idx, target.length(), repl);
        idx += repl.length();
    }

    return src;
}

std::string& replace_all( std::string & src, char const& c1, char const& c2) {
    for (auto & it: src) {
        if (it ==  c1) {
            it = c2;
        }
    }

    return src;
}

std::string& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::string & str) {



     std::map<char,int> m;
    for (int i =0; i < str.size(); ++i) {
        if (!m.insert( std::pair<char,int>(str[i],0)).second) {
            str.erase(i, 1); --i;
        }
    }

    return str;
}

//stripping
   std::string Strip_Out_Data_Between_First_Set_Of_Double_Quotes(std::string const& str){
           std::string return_str;
           int count = 0;
           for (auto const& it: str){
                   if (count == 1){
                           if (it != '"'){
                                return_str +=it;
                           }
                   }else if(count == 2){
                           break;
                   }
                   
                   if (it == '"'){++count;}
           }
           
           return return_str;
   }
   std::string Strip_Out_Data_Between_First_Set_Of_Single_Quotes(std::string const& str){
           std::string return_str;
           int count = 0;
           for (auto const& it: str){
                   if (count == 1){
                           if (it != '\''){
                                return_str +=it;
                           }
                   }else if(count == 2){
                           break;
                   }
                   
                   if (it == '\''){++count;}
           }
           
           return return_str;
   }
std::string Strip_Out_Data_Between_First_Set_Of_Square_Brackets(std::string & str){
        std::string new_str;
        std::string brackets;
        
        bool in_brackets = false;
        for (auto it: str){
                if (it == '['){
                        in_brackets = true;
                        brackets += it;
                }
                else if(it == ']'){
                        if (in_brackets){
                                in_brackets = false;
                                brackets += it;
                        }
                        else{
                                new_str += it;
                        }
                }
                else{
                        if (in_brackets){
                          brackets += it;
                        }
                        else{
                          new_str += it;
                        }
                }
        }
        
        str = new_str;
        return brackets;
}



std::string Strip_Out_From_End_Until_Char_Is_Found(std::string const& str, char const& c){
        std::string return_str;
        for (auto it=str.rbegin(); it!=str.rend(); ++it){
                if (*it == c){
                        break;
                }else{
                        return_str = *it + return_str;
                }
        }
        return return_str;
}
std::string Strip_Out_From_Front_Until_Char_Is_Found(std::string const& str, char const& c){
        std::string return_str;
        for (auto it=str.begin(); it!=str.end(); ++it){
                if (*it == c){
                        break;
                }else{
                        return_str += *it;
                }
        }
        return return_str;
}

std::string Strip_Out_From_Front_Until_Number_Is_Found(std::string const& str){
        std::string return_str;
        for (auto it=str.begin(); it!=str.end(); ++it){
                if (Is_A_Numeric_Character(*it)){
                        break;
                }else{
                        return_str += *it;
                }
        }
        return return_str;
}
std::string Strip_Out_All_Numbers(std::string const& str){
        std::string return_str;
        for (auto it=str.begin(); it!=str.end(); ++it){
                if (Is_A_Numeric_Character(*it)){
                        return_str += *it;
                }
        }
        return return_str;
}

std::string Get_File_Name_From_File_Path(std::string const& file_path){
        return Strip_Out_From_End_Until_Char_Is_Found(file_path,'/');
}


std::string& Convert_Non_Digits_To_Spaces(std::string& s){
        for (auto & it: s){
                if (!Is_A_Numeric_Character(it)){
                        it = ' ';
                }
        }
        return s;
}

//strings and bools
void Falsify_Bool_If_Line_Is_Empty(std::string const& line, bool & b){
    if (Contains_Only_Whitespace_Characters(line)){Make_False(b);}
}
void Falsify_Bool_If_Line_Is_Empty(bool & b, std::string const& line){
    if (Contains_Only_Whitespace_Characters(line)){Make_False(b);}
}
