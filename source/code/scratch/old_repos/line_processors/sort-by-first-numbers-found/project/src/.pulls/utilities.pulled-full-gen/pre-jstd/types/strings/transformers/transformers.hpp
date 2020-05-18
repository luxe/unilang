#include <string>

std::vector<char> Convert_To_Vec_Of_Chars(std::string const& str);

std::vector<int> Collect_Whitespace_Separated_Numbers(std::string const& s);

//appending to string
std::string& Append_With_Newline(std::string & str, std::string const& part);
std::string& Append(std::string & str, std::string const& part);
std::string& Append_N_Times(std::string & str, std::string const& part, unsigned int number_of_times);

//appending to wstring
std::string& Append_With_Newline(std::string & str, std::wstring const& part);
std::string& Append(std::string & str, std::wstring const& part);
std::string& Append_N_Times(std::string & str, std::wstring const& part, unsigned int number_of_times);

std::string& Add_Prefix_To_Each_Line(std::string & str, std::string const& prefix);
std::string& Add_Prefix_To_All_Lines_Except_First(std::string & str, std::string const& prefix);

std::string& CapitalizeFirstChar(std::string & s);
std::string& LowercaseFirstChar(std::string & s);

std::string& Turn_Any_Whitespace_Chars_Into_A_Space(std::string & str);

std::string& Remove_All_Instances_Of_Char(std::string & str, char const& c);

//transforming string functions
std::string& ltrim(std::string &s);
std::string& rtrim(std::string &s);
std::string&  trim(std::string &s);
std::string& Trim_Each_Line(std::string &s);

std::string As_NonAlphas_Removed(std::string const& str);

std::string& Squeeze_Away_Spaces(std::string &s);
std::string As_Left_Trimmed(std::string s);
std::string As_Right_Trimmed(std::string s);
std::string As_Trimmed(std::string s);
std::string As_Spaces_Squeezed_Away(std::string s);
std::string& Reverse(std::string & str);
std::string As_Reversed(std::string str);

std::string& Remove_All_Beginning_Characters_That_Match_Any_Of_The_Following_Characters(std::string & str, std::string const& chars);

std::string& Remove_Match_Found_At_Beginning_Or_End(std::string & str, std::string const& match);
std::string& Remove_Match_If_It_Is_Found_At_Beginning(std::string & str, std::string const& match);
std::string& Remove_Match_If_It_Is_Found_At_End(std::string & str, std::string const& match);

std::string& Remove_Match_Found_At_Beginning(std::string & str, std::string const& match);
std::string& Remove_Match_Found_At_End(std::string & str, std::string const& match);

std::string& Squeeze_Away_Spaces_On_String(std::string &s);

std::string& Remove_Match_If_It_Is_Found_At_Beginning_Or_End(std::string & str, std::string const& match);

std::string& Remove_Matching_Beginning_Part_Of_String(std::string & str, std::string const& match);
std::string As_Beginning_Matching_Part_Of_String_Removed(std::string const& str, std::string const& match);
std::string& Keep_Matching_Beginning_Part_Of_String(std::string & str, std::string const& match);
std::string As_Beginning_Matching_Part_Of_String_Kept(std::string const& str, std::string const& match);
std::string& Keep_Only_First_N_Characters(std::string & str, unsigned int const& count);

std::string& Empty_String_If_It_Only_Contains_Whitespace(std::string & str);
std::string As_Empty_String_If_It_Only_Contains_Whitespace(std::string str);

std::string& Escape_Double_Quote_String_Content_For_Shell(std::string & str);
std::string As_Escaped_Double_Quote_String_Content_For_Shell(std::string str);
std::string& Escape_Single_Quote_String_Content_For_Shell(std::string & str);
std::string As_Escaped_Single_Quote_String_Content_For_Shell(std::string str);

std::string& Wrap_In_Single_Quotes(std::string & str);
std::string As_Wrapped_In_Single_Quotes(std::string str);
std::string& Wrap_In_Double_Quotes(std::string & str);
std::string As_Wrapped_In_Double_Quotes(std::string str);

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
    
    std::string& Move_First_Word_Of_String_To_The_End(std::string & str);
    std::string As_First_Word_Of_String_Moved_To_The_End(std::string str);

//both
std::string& Remove_First_And_Last_Char(std::string & str);

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
    
    std::string& Append_To_Front(std::string & str, std::string const& part);
    std::string& Append_To_Back(std::string & str, std::string const& part);

    std::string& Append_To_Front_Of_Each_Line(std::string & str, std::string const& part);
    std::string& Append_To_Back_Of_Each_Line(std::string & str, std::string const& part);

    std::string& Indent_Each_Line(std::string & str, int indent_amount);


//casing
    std::string& Uppercase(std::string &s);
    std::string As_Uppercase(std::string s);
    
    std::string& Lowercase(std::string &s);
    std::string As_Lowercase(std::string s);
    
    std::string As_Camel_Case(std::string s);
    std::string As_Lower_Camel_Case(std::string s);
    std::string As_Capitalized(std::string s);
    std::string As_Capital_And_Pushed_Together(std::string s);                   //SomethingLikeThis
    std::string Capitalize_Each_With_Space_In_Between(std::string s);            //Something Like This
    std::string Make_Capital_And_Underscored_In_User_Type_Format(std::string s); //Something_Like_This
    std::string As_All_Capital_Letters_With_Spaces_As_Underscores(std::string s); //SOMETHING_LIKE_THIS
    std::string As_All_Lowercase_Letters_With_Spaces_As_Underscores(std::string s);//something_like_this
    std::string As_All_Lowercase_Letters_With_Underscores_As_Spaces(std::string s);//something like this
    std::string As_Capital_And_Pushed_Together_Preserve_Underscores_With_Lowercase_After(std::string s); //something like_this -> SomethingLike_this
    //*look at the sublime plugin for different case names
    //Title Case
    //Upper Case
    //Lower Case
    //Swap Case
    //snake_case
    //camelCase
    //PascalCase
    //dot.case
    //dash-case
    //seperate words
    //seperate/with/slash
    //Toggle Case
    
    
//CLASS NAME
//Class Name
//class name
//class Name

//CLASS_NAME
//Class_Name
//class_name
//class_Name

//CLASS-NAME
//Class-Name
//class-name
//class-Name

//CLASSNAME
//ClassName
//classname
//className

std::string& Convert_Non_Digits_To_Spaces(std::string& s);

//search and replace
    std::string string_replace_first_instance( std::string src, std::string const& target, std::string const& repl);
    std::string string_replace_all( std::string src, std::string const& target, std::string const& repl);
    std::string& replace_all( std::string & src, char const& c1, char const& c2);
    std::string& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::string & str);

//stripping
   std::string Strip_Out_Data_Between_First_Set_Of_Single_Quotes(std::string const& str);
   std::string Strip_Out_Data_Between_First_Set_Of_Double_Quotes(std::string const& str);
   std::string Strip_Out_Data_Between_First_Set_Of_Square_Brackets(std::string & str);
   std::string Strip_Out_From_End_Until_Char_Is_Found(std::string const& str, char const& c);
   std::string Strip_Out_From_Front_Until_Char_Is_Found(std::string const& str, char const& c);
   std::string Strip_Out_From_Front_Until_Number_Is_Found(std::string const& str);
   std::string Strip_Out_All_Numbers(std::string const& str);
   
   std::string Get_File_Name_From_File_Path(std::string const& file_path);

//strings and bools
void Falsify_Bool_If_Line_Is_Empty(std::string const& line, bool & b);
