//observers
bool Is_A_Control_Character(char const& c);
bool Is_A_Printable_Character(char const& c);
bool Is_A_Whitespace_Character(char const& c);
bool Is_A_Blank_Character(char const& c);
bool Is_A_Graphical_Character(char const& c);
bool Is_A_Puncuation_Character(char const& c);
bool Is_An_Alphanumberic_Character(char const& c);
bool Is_An_Alpha_Character(char const& c);
bool Is_An_Uppercase_Character(char const& c);
bool Is_A_Lowercase_Character(char const& c);
bool Is_A_Numeric_Character(char const& c);
bool Is_A_Hexidecimal_Character(char const& c);

//printers
void Print_Character_N_Times(char const& c, unsigned int const& amount);

//get individuals
//the double/single quote functions exist because I've confused the syntax highlighter.  This is a work-around
//when working hcp 
char Get_Double_Quote();
char Get_Single_Quote();
