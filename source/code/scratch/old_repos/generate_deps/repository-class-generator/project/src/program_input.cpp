#include "program_input.hpp"









 Program_Input::Program_Input(Root_Settings const& settings, Composed_Program_Options const& options)
              : settings(settings)
              , options(options)
             {}
             

//functions added automatically by hcp-compiler
nlohmann::json As_JSON_Assignable(Program_Input const& class_object){
	nlohmann::json j;
	return j;
}std::string Class_Name(Program_Input const& class_object){
	return "Program_Input";
}std::string As_YAML_String(Program_Input const& class_object){
	std::string yaml_str;
	return yaml_str;
}std::string As_XML_String(Program_Input const& class_object){
	std::string xml_str;
	return xml_str;
}