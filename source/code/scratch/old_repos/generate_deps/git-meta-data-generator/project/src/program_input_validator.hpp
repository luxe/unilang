#pragma once
#include "utilities.hpp"
#include "systems.hpp"
#include "program_options.hpp"
#include "program_input.hpp"

class Program_Input_Validator{






public: static void Validate(Program_Input & input) ;
//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(Program_Input_Validator const& class_object);
	friend nlohmann::json As_JSON_Assignable(Program_Input_Validator const& class_object);
	friend  std::string As_YAML_String(Program_Input_Validator const& class_object);
	friend  std::string As_XML_String(Program_Input_Validator const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};