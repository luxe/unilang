#include <iostream>
#include <string>
#include "json.hpp"


//forward decelerations
struct Sub_Class;
struct Root_Class;

//string wrapper for json file names to avoid collisions with std::string constructors
class JSON_Filename{
  public:
    JSON_Filename(std::string const& str): file_name(str) {}
    operator std::string() const { return file_name; }
  private:
    std::string file_name;
};

//json append for all types that don't derive from an hcp file construct
//so we assume the json library can handle all basic types and std containers
//the function will either return a basic type, a std container, or call an overload that returns a json
template <typename T>
T As_JSON_Assignable(T const& t){
  return t;
}
template <typename T>
std::string As_JSON_String(T const& t){
    auto j = As_JSON_Assignable(t);
    nlohmann::json r = j;
    return r.dump(2);
}


template <typename T>
void JSON_Set(T & value, T const& new_value){
    value = new_value;
}


template <typename T>
std::string As_JSON_String(T const& t){
    auto j = As_JSON_Assignable(t);
    nlohmann::json r = j;
    return r.dump(2);
}



struct Sub_Class{

  //constructors
  Sub_Class(){}
  Sub_Class(JSON_Filename const& json_filename){}
  Sub_Class(nlohmann::json const& json_structure){}
  
  //json append function
  friend nlohmann::json As_JSON_Assignable(Sub_Class s);
  friend void JSON_Set(Sub_Class & s, nlohmann::json const& j);
  
  //data
  int a = 123;
  float b = 3.14;
  char c = 'z';
  std::string d = "hello world";
  
};

struct Root_Class{

  //constructors
  Root_Class(){}
  Root_Class(JSON_Filename const& json_filename){}
  Root_Class(nlohmann::json const& json_structure){}
  
  //json append function
  friend nlohmann::json As_JSON_Assignable(Root_Class s);
  friend void JSON_Set(Root_Class & s, nlohmann::json const& j);
  
  //data
  int a = 456;
  float b = 1.234;
  char c = 'a';
  std::string d = "goodbye world";
  Sub_Class sub;
  
};


//used to create a final json from the root class
nlohmann::json As_JSON_Assignable(Root_Class s){
  nlohmann::json j;
    j["a"] = As_JSON_Assignable(s.a);
    j["b"] = As_JSON_Assignable(s.b);
    j["c"] = As_JSON_Assignable(s.c);
    j["d"] = As_JSON_Assignable(s.d);
    j["sub"] = As_JSON_Assignable(s.sub);
    return j;
}
nlohmann::json As_JSON_Assignable(Sub_Class s){
  nlohmann::json j;
    j["a"] = As_JSON_Assignable(s.a);
    j["b"] = As_JSON_Assignable(s.b);
    j["c"] = As_JSON_Assignable(s.c);
    j["d"] = As_JSON_Assignable(s.d);
    return j;
}

void JSON_Set(Sub_Class & s, nlohmann::json const& j){
    //JSON_Set(s.a,j["a"]);
    //JSON_Set(s.b,j["b"]);
    //JSON_Set(s.c,j["c"]);
    //JSON_Set(s.d,j["d"]);
}
void JSON_Set(Root_Class & s, nlohmann::json const& j){
    //JSON_Set(s.a,j["a"]);
    //JSON_Set(s.b,j["b"]);
    //JSON_Set(s.c,j["c"]);
    //JSON_Set(s.d,j["d"]);
    //JSON_Set(s.sub,j["sub"]);
}

int main(){

  //Root_Class s;
  //std::cout << As_JSON_String(s) << std::endl;
    
    
    //first I create a json object
    nlohmann::json j;
    
    //set some value
    std::vector<int> i{1,2,3,4,5,6};
    j["some_value"] = i;
    
    
    //char b = char(atoi(j["some_value"].dump().c_str()));
    std::cout << std::vector<int>(
                                     j["some_value"].get<std::vector<std::string>>()
                                  ) << std::endl;

  //Sub_Class a(JSON_Filename("sdf"));
  //std::cout << a.As_JSON() << std::endl;
}
