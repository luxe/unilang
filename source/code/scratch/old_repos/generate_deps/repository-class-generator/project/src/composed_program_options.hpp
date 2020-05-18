#pragma once
#include "utilities.hpp"
#include "systems.hpp"

class Composed_Program_Options{




public:

  //an organized composition of passed in command line options
 

//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(Composed_Program_Options const& class_object);
	friend nlohmann::json As_JSON_Assignable(Composed_Program_Options const& class_object);
	friend  std::string As_YAML_String(Composed_Program_Options const& class_object);
	friend  std::string As_XML_String(Composed_Program_Options const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};