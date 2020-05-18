#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "root_settings.hpp"
#include "composed_program_options.hpp"

class Program_Input{








public: Program_Input(Root_Settings const& settings, Composed_Program_Options const& options);
             
public:
    Root_Settings settings;
    Composed_Program_Options options;

//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(Program_Input const& class_object);
	friend nlohmann::json As_JSON_Assignable(Program_Input const& class_object);
	friend  std::string As_YAML_String(Program_Input const& class_object);
	friend  std::string As_XML_String(Program_Input const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};