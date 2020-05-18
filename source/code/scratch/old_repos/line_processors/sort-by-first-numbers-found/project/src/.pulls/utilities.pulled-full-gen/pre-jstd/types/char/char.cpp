//transformers
void Print_Character_N_Times(char const& c, unsigned int const& amount){
  repeat([&]{std::cout << c;},amount);
}

//observers
bool Is_A_Control_Character(char const& c){
  return iscntrl(c);
}
bool Is_A_Printable_Character(char const& c){
  return isprint(c);
}
bool Is_A_Whitespace_Character(char const& c){
  return isspace(c);
}
bool Is_A_Blank_Character(char const& c){
  return isblank(c);
}
bool Is_A_Graphical_Character(char const& c){
  return isgraph(c);
}
bool Is_A_Puncuation_Character(char const& c){
  return ispunct(c);
}
bool Is_An_Alphanumberic_Character(char const& c){
  return isalnum(c);
}
bool Is_An_Alpha_Character(char const& c){
  return isalpha(c);
}

bool Is_An_Uppercase_Character(char const& c){
  return isupper(c);
}

bool Is_A_Lowercase_Character(char const& c){
  return islower(c);
}

bool Is_A_Numeric_Character(char const& c){
  return isdigit(c);
}

bool Is_A_Hexidecimal_Character(char const& c){
  return isxdigit(c);
}

char Get_Double_Quote(){
  return '"';
}
char Get_Single_Quote(){
  return '\'';
}
