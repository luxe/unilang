#include <string>
#include <vector>
#include <set>

//forward decl;
std::string& Remove_Last_Char(std::string & tr);

//add static casts to and from all classes
std::string as_string(std::wstring const& wstr);
std::wstring as_wstring(std::string const& str);

//dummies
std::string as_string(std::string const& s);
std::wstring as_wstring(std::wstring const& s);

template <typename T, template <class> class Container>
std::vector<T> To_Vector(Container<T> const& c){
  return std::vector<T>( c.begin(), c.end() );
}

template <typename T>
std::vector<T> Set_To_Vector(std::set<T> const& c){
  return std::vector<T>( c.begin(), c.end() );
}

template <typename T, template <class> class Container>
std::set<T> To_Set(Container<T> const& c){
  return std::set<T>( c.begin(), c.end() );
}
template<typename C>
std::string Get_Each_Element_Of_Vector_As_A_Line_In_A_String(C const& c){
  std::string str;
  for (auto const& it: c){
    str += std::to_string(it) + '\n';
  }
  Remove_Last_Char(str);
  return str;
}
