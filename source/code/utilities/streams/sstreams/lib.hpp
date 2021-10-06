#pragma once
#include <string>
#include <sstream>

template <typename Object>
std::string Get_String_Of_Stream_Inserted_Object(Object const& o){
   std::stringstream s;
   s << o;
   return s.str();
}
