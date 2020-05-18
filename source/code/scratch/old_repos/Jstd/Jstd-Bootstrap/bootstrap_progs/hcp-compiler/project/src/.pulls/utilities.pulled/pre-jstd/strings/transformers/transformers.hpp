#include <string>

//transforming string functions
std::string& ltrim(std::string &s);
std::string& rtrim(std::string &s);
std::string&  trim(std::string &s);
std::string& Squeeze_Away_Spaces(std::string &s);
std::string As_Left_Trimmed(std::string s);
std::string As_Right_Trimmed(std::string s);
std::string Trimmed(std::string s);
std::string As_Spaces_Squeezed_Away(std::string s);
std::string& Reverse(std::string & str);
std::string As_Reversed(std::string str);

//changing front and back

    //front
    std::string& Remove_First_Char(std::string &s);
    std::string As_First_Char_Removed(std::string const& s);
    
    std::string& Remove_All_Chars_From_Front_Until_Char_Is_Seen(std::string & str, char const& c);
    /**/ std::string As_All_Chars_Removed_From_Front_Until_Char_Is_Seen(std::string str, char const& c);
    
    std::string& Remove_All_Chars_From_Front_Until_Char_Is_Seen_A_Number_Of_Times(std::string & str, char const& c, unsigned int number_of_times);
    /**/ std::string As_All_Chars_Removed_From_Front_Until_Char_Is_Seen_A_Number_Of_Times(std::string str, char const& c, unsigned int number_of_times);
    
    std::string& Remove_First_N_Chars(std::string & str, unsigned int const& number_of_times);
    std::string As_First_N_Chars_Removed(std::string str, unsigned int const& number_of_times);
    
    
    std::string& Remove_N_Chars_From_Front_And_Back(std::string & str, unsigned int const& number_of_times);
    std::string As_N_Chars_Removed_From_Front_And_Back(std::string str, unsigned int const& number_of_times);
    
    //back
    std::string& Remove_Last_Char(std::string &s);
    std::string As_Last_Char_Removed(std::string const& s);
    
    std::string& Remove_All_Chars_From_Back_Until_Char_Is_Seen(std::string & str, char const& c);
    /**/ std::string As_All_Chars_Removed_From_Back_Until_Char_Is_Seen(std::string str, char const& c);
    
    std::string& Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(std::string & str, char const& c, unsigned int number_of_times);
    /**/ std::string As_All_Chars_Removed_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(std::string str, char const& c, unsigned int number_of_times);
    
    std::string& Remove_Last_N_Chars(std::string & str, unsigned int const& number_of_times);
    std::string As_Last_N_Chars_Removed(std::string str, unsigned int const& number_of_times);


    //changing the end of a string (assuming it's a filename)
    std::string& Remove_Suffix(std::string &s);
    std::string As_Removed_Suffix(std::string s);

    std::string& Add_File_Extension(std::string &s, std::string const& extension);
    std::string As_Added_File_Extension(std::string s, std::string const& extension);

    std::string& Replace_File_Extension(std::string &s, std::string const& new_extension);
    std::string As_Replaced_Extension(std::string s, std::string const& new_extension);

    //changing the end of a string (assuming it's a directory name)
    std::string Get_Path_As_A_Number_Of_Directories_Back(std::string dir_name, unsigned int const& amount_back);
    std::string Get_Path_As_One_Directories_Back(std::string dir_name);
    std::string Get_Path_As_Two_Directories_Back(std::string dir_name);
    std::string Get_Path_As_Three_Directories_Back(std::string dir_name);


//casing
    std::string& Uppercase(std::string &s);
    std::string As_Uppercase(std::string s);
    
    std::string& Lowercase(std::string &s);
    std::string As_Lowercase(std::string s);
    
    std::string Make_Capital_And_Underscored_In_User_Type_Format(std::string s); //Something_Like_This
    std::string As_All_Capital_Letters_With_Spaces_As_Underscores(std::string s); //SOMETHING_LIKE_THIS
    std::string As_All_Lowercase_Letters_With_Spaces_As_Underscores(std::string s);//something_like_this

//search and replace
    std::string string_replace_first_instance( std::string src, std::string const& target, std::string const& repl);
    std::string string_replace_all( std::string src, std::string const& target, std::string const& repl);
    std::string& replace_all( std::string & src, char const& c1, char const& c2);
    std::string& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::string & str);
