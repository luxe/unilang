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