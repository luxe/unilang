#include <string>

//transforming string functions
std::wstring& ltrim(std::wstring &s);
std::wstring& rtrim(std::wstring &s);
std::wstring&  trim(std::wstring &s);
std::wstring& Squeeze_Away_Spaces(std::wstring &s);

//changing front and back

    //front
    std::wstring& Remove_First_Char(std::wstring &s);
    std::wstring As_First_Char_Removed(std::wstring const& s);
    
    std::wstring& Remove_All_Chars_From_Front_Until_Char_Is_Seen(std::wstring & str, char const& c);
    /**/ std::wstring As_All_Chars_Removed_From_Front_Until_Char_Is_Seen(std::wstring str, char const& c);
    
    std::wstring& Remove_All_Chars_From_Front_Until_Char_Is_Seen_A_Number_Of_Times(std::wstring & str, char const& c, unsigned int number_of_times);
    /**/ std::wstring As_All_Chars_Removed_From_Front_Until_Char_Is_Seen_A_Number_Of_Times(std::wstring str, char const& c, unsigned int number_of_times);
    
    std::wstring& Remove_First_N_Chars(std::wstring & str, unsigned int const& number_of_times);
    std::wstring As_First_N_Chars_Removed(std::wstring str, unsigned int const& number_of_times);
    
    
    std::wstring& Remove_N_Chars_From_Front_And_Back(std::wstring & str, unsigned int const& number_of_times);
    std::wstring As_N_Chars_Removed_From_Front_And_Back(std::wstring str, unsigned int const& number_of_times);
    
    //back
    std::wstring& Remove_Last_Char(std::wstring &s);
    std::wstring As_Last_Char_Removed(std::wstring const& s);
    
    std::wstring& Remove_All_Chars_From_Back_Until_Char_Is_Seen(std::wstring & str, char const& c);
    /**/ std::wstring As_All_Chars_Removed_From_Back_Until_Char_Is_Seen(std::wstring str, char const& c);
    
    std::wstring& Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(std::wstring & str, char const& c, unsigned int number_of_times);
    /**/ std::wstring As_All_Chars_Removed_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(std::wstring str, char const& c, unsigned int number_of_times);
    
    std::wstring& Remove_Last_N_Chars(std::wstring & str, unsigned int const& number_of_times);
    std::wstring As_Last_N_Chars_Removed(std::wstring str, unsigned int const& number_of_times);


    //changing the end of a string (assuming it's a filename)
    std::wstring& Remove_Suffix(std::wstring &s);
    std::wstring As_Removed_Suffix(std::wstring s);

    std::wstring& Add_File_Extension(std::wstring &s, std::wstring const& extension);
    std::wstring As_Added_File_Extension(std::wstring s, std::wstring const& extension);

    std::wstring& Replace_File_Extension(std::wstring &s, std::wstring const& new_extension);
    std::wstring As_Replaced_Extension(std::wstring s, std::wstring const& new_extension);

    //changing the end of a string (assuming it's a directory name)
    std::wstring Get_Path_As_A_Number_Of_Directories_Back(std::wstring dir_name, unsigned int const& amount_back);
    std::wstring Get_Path_As_One_Directories_Back(std::wstring dir_name);
    std::wstring Get_Path_As_Two_Directories_Back(std::wstring dir_name);
    std::wstring Get_Path_As_Three_Directories_Back(std::wstring dir_name);


//casing
    std::wstring& Uppercase(std::wstring &s);
    std::wstring As_Uppercase(std::wstring s);
    
    std::wstring& Lowercase(std::wstring &s);
    std::wstring As_Lowercase(std::wstring s);
    
    std::wstring Make_Capital_And_Underscored_In_User_Type_Format(std::wstring s); //Something_Like_This
    std::wstring As_All_Capital_Letters_With_Spaces_As_Underscores(std::wstring s); //SOMETHING_LIKE_THIS
    std::wstring As_All_Lowercase_Letters_With_Spaces_As_Underscores(std::wstring s);//something_like_this

//search and replace
    std::wstring string_replace_first_instance( std::wstring src, std::wstring const& target, std::wstring const& repl);
    std::wstring string_replace_all( std::wstring src, std::wstring const& target, std::wstring const& repl);
    std::wstring& replace_all( std::wstring & src, char const& c1, char const& c2);
    std::wstring& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::wstring & str);