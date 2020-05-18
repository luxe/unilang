#pragma once
#include "utilities.hpp"
#include "systems.hpp"
#include "program_options.hpp"
#include "composed_program_options.hpp"

class Program_Options_Composer{






public: static Composed_Program_Options Compose(Program_Options const& program_options) ;
//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(Program_Options_Composer const& class_object);
	friend nlohmann::json As_JSON_Assignable(Program_Options_Composer const& class_object);
	friend  std::string As_YAML_String(Program_Options_Composer const& class_object);
	friend  std::string As_XML_String(Program_Options_Composer const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};