#pragma once
#include <string>
#include <vector>

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

//observing string functions
bool Space_At_The_Beginning(std::wstring const& s);
bool Space_At_The_End(std::wstring const& s);
bool Consecutive_Space_In_The_Middle(std::wstring s);
bool Contains_Capital_Letters(std::wstring const& s);
bool Contains_Character(std::wstring const& s, char const& c);
bool Begins_With(std::wstring const& str, std::wstring const& start_part);
bool Ends_With(std::wstring const& str, std::wstring const& end_part);
bool Begins_And_Ends_With(std::wstring const& str, std::wstring const& part);
bool Begins_With(std::wstring const& str, char const& start_part);
bool Ends_With(std::wstring const& str, char const& end_part);
bool Begins_And_Ends_With(std::wstring const& str, char const& part);
bool Contains_Substring(std::wstring const& str, std::wstring const& part);
char First_Char(std::wstring const& str);
char Last_Char(std::wstring const& str);

std::wstring Get_File_Extension(std::wstring const& str);

bool First_Char_Comes_Before_Second_Char(std::wstring const& s, char const& c1, char const& c2);

std::vector<size_t> Get_Indexes_Of_Character(std::wstring const& s, char const& c);
unsigned int Count_Instances_Of_Character(std::wstring const& s, char const& c);


//converting to other types
unsigned int as_unsigned(std::wstring str);
signed int as_signed(std::wstring str);
std::vector<std::wstring> Put_Each_Line_Of_String_Into_A_Vector(std::wstring const& str);
