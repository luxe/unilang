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


//observing string functions
bool Space_At_The_Beginning(std::string const& s);
bool Space_At_The_End(std::string const& s);
bool Consecutive_Space_In_The_Middle(std::string s);
bool Contains_Capital_Letters(std::string const& s);
bool Contains_Character(std::string const& s, char const& c);
bool Begins_With(std::string const& str, std::string const& start_part);
bool Ends_With(std::string const& str, std::string const& end_part);
bool Begins_And_Ends_With(std::string const& str, std::string const& part);
bool Begins_With(std::string const& str, char const& start_part);
bool Ends_With(std::string const& str, char const& end_part);
bool Begins_And_Ends_With(std::string const& str, char const& part);
bool Contains_Substring(std::string const& str, std::string const& part);
bool Contains_Only_Whitespace_Characters(std::string const& str);
char First_Char(std::string const& str);
char Last_Char(std::string const& str);

std::pair<std::string,std::string> Split_By_Char(std::string const& str, char const& c);

std::string Get_File_Extension(std::string const& str);

bool First_Char_Comes_Before_Second_Char(std::string const& s, char const& c1, char const& c2);

std::vector<size_t> Get_Indexes_Of_Character(std::string const& s, char const& c);
unsigned int Count_Instances_Of_Character(std::string const& s, char const& c);


//converting to other types
unsigned int as_unsigned(std::string str);
signed int as_signed(std::string str);
long as_long(std::string str);
unsigned long as_unsigned_long(std::string str);
std::vector<std::string> Put_Each_Line_Of_String_Into_A_Vector(std::string const& str);
