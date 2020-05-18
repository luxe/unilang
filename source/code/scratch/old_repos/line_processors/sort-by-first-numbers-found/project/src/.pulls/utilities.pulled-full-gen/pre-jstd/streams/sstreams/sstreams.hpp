template <typename Object>
std::string Get_String_Of_Stream_Inserted_Object(Object const& o){
   std::sstream s;
   s << o;
   return s.str();
}
