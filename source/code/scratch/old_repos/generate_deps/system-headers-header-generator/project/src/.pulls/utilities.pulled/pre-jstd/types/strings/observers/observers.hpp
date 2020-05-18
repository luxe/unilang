//apply character testing on all elements of string
bool Is_Only_Control_Characters(std::string const& str);
bool Is_Only_Printable_Characters(std::string const& str);
bool Is_Only_Whitespace_Characters(std::string const& str);
bool Is_Only_Blank_Characters(std::string const& str);
bool Is_Only_Graphical_Characters(std::string const& str);
bool Is_Only_Puncuation_Characters(std::string const& str);
bool Is_Only_Alphanumberic_Characters(std::string const& str);
bool Is_Only_Alpha_Characters(std::string const& str);
bool Is_Only_Uppercase_Characters(std::string const& str);
bool Is_Only_Lowercase_Characters(std::string const& str);
bool Is_Only_Numeric_Characters(std::string const& str);
bool Is_Only_Hexidecimal_Characters(std::string const& str);
bool Has_Only_Lowercase_Letters_And_Underscores(std::string const& str);
bool Has_Only_Uppercase_Letters_And_Underscores(std::string const& str);
bool Has_Only_Lowercase_Letters_Underscores_And_Forward_Slashes(std::string const& str);
bool Has_Only_Uppercase_Letters_Underscores_And_Forward_Slashes(std::string const& str);
bool Has_Only_Alpha_Letters_And_Underscores(std::string const& str);
bool Has_Only_Alphanumeric_And_Underscores(std::string const& str);
bool Has_Only_Uppercase_Letters_Numbers_And_Underscores(std::string const& str);
bool Starts_With_Digit(std::string const& str);

std::string Pop_Off_First_Token(std::string & str);


//observing string functions
bool Space_At_The_Beginning(std::string const& s);
bool Space_At_The_End(std::string const& s);
bool Consecutive_Space_In_The_Middle(std::string s);
bool Contains_Capital_Letters(std::string const& s);
bool Contains_Character(std::string const& s, char const& c);
bool Begins_With(std::string const& str, std::string const& start_part);
bool Ends_With(std::string const& str, std::string const& end_part);
bool Begins_And_Ends_With(std::string const& str, std::string const& part);
bool Begins_Or_Ends_With(std::string const& str, std::string const& part);
bool Begins_With(std::string const& str, char const& start_part);
bool Ends_With(std::string const& str, char const& end_part);
bool Begins_And_Ends_With(std::string const& str, char const& part);
bool Contains_Substring(std::string const& str, std::string const& part);
bool Contains_Only_Whitespace_Characters(std::string const& str);
char First_Char(std::string const& str);
char Last_Char(std::string const& str);
bool IsPalindrome(std::string str);

//comparing two string
bool Case_Insensitive_String_Compare(std::string const& str1, std::string const& str2);
bool Case_Insensitive_Alpha_Compare(std::string str1, std::string str2);
bool String_Is_Combination_Of_Other_String(std::string str1, std::string str2);

//observing from the front
std::string Get_All_Beginning_Characters_Until_Capital_Letter(std::string const& str);

//comparing
bool Non_Case_Sensitive_Compare(std::string str1, std::string str2);
bool Case_Sensitive_Compare(std::string const& str1, std::string const& str2);
bool Case_Insensitive_Undercore_Ignoring_String_Compare(std::string str1, std::string str2);
bool Case_Insensitive_Undercore_And_Space_Ignoring_String_Compare(std::string str1, std::string str2);

std::vector<std::string> Split_Into_Parts_From_Delimiter(std::string const& str, char const& delimiter);
std::vector<std::string> Split_Into_Parts_From_Comma(std::string const& str);
std::vector<std::string> Get_Path_In_Parts(std::string const& str);
std::pair<std::string,std::string> Split_On_First_Instance_Of_Char(std::string const& str, char const& c);
std::pair<std::string,std::string> Split_On_Second_Instance_Of_Char(std::string const& str, char const& c);

std::pair<std::string,std::string> Split_By_Char(std::string const& str, char const& c);
std::pair<size_t,size_t> Get_Start_And_End_Positions_Of_First_Word(std::string const& str);
std::pair<size_t,size_t> Get_Start_Position_And_Length_Of_First_Word(std::string const& str);

std::string Get_File_Extension(std::string const& str);
bool File_Has_Extension(std::string const& path_to_file, std::string const& file_extension);
bool File_Has_Extension(std::string const& path_to_file);
std::string Get_File_Name(std::string const& str);

bool First_Char_Comes_Before_Second_Char(std::string const& s, char const& c1, char const& c2);

std::vector<size_t> Get_Indexes_Of_Character(std::string const& s, char const& c);
std::vector<size_t> Get_Indexes_Of_Substring_Through_Case_Insensitive_Comparing(std::string src, std::string substr);

unsigned int Count_Instances_Of_Character(std::string const& s, char const& c);

std::string Get_Substring_Found_Between_First_Instance_Of_Two_Characters(std::string str, char first, char last);
unsigned int Starts_With_Char_How_Many_Times(std::string const& str, char c);
unsigned int Starts_With_How_Many_Spaces(std::string const& str);

size_t Get_Index_After_Found_Substring(std::string const& str, std::string const& substring);

//parsing out columns
std::vector<std::string> Get_Each_Column(std::string const& str);
std::string Get_Column_By_Index(std::string const& str, int index);
std::string Get_1st_Column(std::string const& str);
std::string Get_2nd_Column(std::string const& str);
std::string Get_3rd_Column(std::string const& str);
std::string Get_4th_Column(std::string const& str);
std::string Get_5th_Column(std::string const& str);


//converting to other types
unsigned int as_unsigned(std::string str);
signed int as_signed(std::string str);
long as_long(std::string str);
unsigned long as_unsigned_long(std::string str);
std::vector<std::string> Put_Each_Line_Of_String_Into_A_Vector(std::string const& str);
std::vector<std::pair<std::string,std::string>> Put_Each_Line_Of_String_Into_A_Vector_Of_Pairs_Where_The_First_Pair_Elements_Are_Empty(std::string const& str);
