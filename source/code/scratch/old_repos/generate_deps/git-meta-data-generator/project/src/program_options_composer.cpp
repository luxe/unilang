#include "program_options_composer.hpp"







 Composed_Program_Options Program_Options_Composer::Compose(Program_Options const& program_options) {

  Composed_Program_Options composed;
  
  //converts all the program_options into a composed version.
  //this way we can organize information into nested structures as desired
  
  return composed;

}
//functions added automatically by hcp-compiler
nlohmann::json As_JSON_Assignable(Program_Options_Composer const& class_object){
	nlohmann::json j;
	return j;
}std::string Class_Name(Program_Options_Composer const& class_object){
	return "Program_Options_Composer";
}std::string As_YAML_String(Program_Options_Composer const& class_object){
	std::string yaml_str;
	return yaml_str;
}std::string As_XML_String(Program_Options_Composer const& class_object){
	std::string xml_str;
	return xml_str;
}