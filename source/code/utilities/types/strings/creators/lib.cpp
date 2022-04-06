#include "code/utilities/types/strings/creators/lib.hpp"

std::string Create_String_Of_N_Chars(unsigned int const& num_of_chars, char const& c){
  return std::string(num_of_chars,c);
}
std::string Create_String_Of_N_Strs(unsigned int const& num_of_chars, std::string const& c)
{
  std::string str;
  for (size_t i = 0; i < num_of_chars; ++i){
    str += c;
  }
  return str;
}

std::string Create_String_Of_N_Spaces(unsigned int num_spaces){
  return Create_String_Of_N_Chars(num_spaces, ' ');
}
std::string Char_To_String(unsigned char c){
  std::string str;
  str += c;
  return str;
}
std::string Chars_To_String(std::vector<char> chars){
  std::string str;
  for (auto it: chars){
    str+=it;
  }
  return str;
}

std::string Start_Tag(std::string const& tag_name, std::string const& key, std::string const& value)
{
  std::string str;
  str += "<";
  str += tag_name;
  str += " ";
  str += Create_XML_Attribute_Equals_Quoted_Value(key,value);
  str += ">";
  return str;
}

std::string Tag_Content(std::string const& tag_name,std::string const& content)
{
  std::string str;
  str += "<";
  str += tag_name;
  str += ">";
  str += content;
  str += "</";
  str += tag_name;
  str += ">";
  return str;
}

std::string Single_End_Tag(std::string const& tag_name)
{
  std::string str;
  str += "<";
  str += tag_name;
  str += "/>";
  return str;
}

std::string Single_End_Tag(std::string const& tag_name, std::string const& key, std::string const& value)
{
  std::string str;
  str += "<";
  str += tag_name;
  str += " ";
  str += Create_XML_Attribute_Equals_Quoted_Value(key,value);
  str += "/>";
  return str;
}

std::string Create_XML_Attribute_Equals_Quoted_Value(std::string const& key, std::string const& value)
{
  std::string str;
  str += key;
  str += "=";
  str += "\"";
  str += value;
  str += "\"";
  return str;
}

std::string End_Tag(std::string const& tag_name)
{
  std::string str;
  str += "</";
  str += tag_name;
  str += ">";
  return str;
}

std::string CreateStaircase(int size){
  
  std::string result;
   for (size_t i = 0; i < n; ++i){
       //print spaces
       result += Create_String_Of_N_Strs(n-(i+1)," ");
       
       //print stairs
       result += Create_String_Of_N_Strs(i+1,"#");
       result += "\n";
   }
   return result;
}