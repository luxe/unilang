#pragma once
#include "utilities.hpp"
#include "systems.hpp"
#include "program_options.hpp"
#include "root_settings.hpp"

class Root_Settings_Getter{






public: static Root_Settings Get() ;
//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(Root_Settings_Getter const& class_object);
	friend nlohmann::json As_JSON_Assignable(Root_Settings_Getter const& class_object);
	friend  std::string As_YAML_String(Root_Settings_Getter const& class_object);
	friend  std::string As_XML_String(Root_Settings_Getter const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};