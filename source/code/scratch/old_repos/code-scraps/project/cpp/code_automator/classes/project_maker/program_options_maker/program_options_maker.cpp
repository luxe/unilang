#include "program_options_maker.hpp"
#include "class_maker/class_maker.hpp"
#include "code_paster/code_paster.hpp"
#include "include_manager/include_manager.hpp"

void Program_Options_Maker::Make(std::string const& path, std::string name){
	
	Class_Maker::Make_Class(path,name);
	
	//constructor
	Code_Paster::Put_Program_Options_Decleration_Constructor(path + name + "/class/class_parts/deceleration/object_functions_part/constructors.hpp");
	Code_Paster::Put_Program_Options_Definition_Constructor(path + name + "/class/class_parts/definition/object_functions_part/constructors.hpp");
	
	//private internal functions
	Code_Paster::Put_Program_Options_Decleration_Transformer_Functions(path + name + "/class/class_parts/deceleration/object_functions_part/transformers.hpp");
	Code_Paster::Put_Program_Options_Definition_Transformer_Functions(path + name + "/class/class_parts/definition/object_functions_part/transformers.hpp");
	
	//private internal data
	Code_Paster::Put_Program_Options_Decleration_Data(path + name + "/class/class_parts/deceleration/data.hpp");
	Code_Paster::Put_Program_Options_Definition_Data(path + name + "/class/class_parts/definition/data.hpp");
	
	//private static data
	Code_Paster::Put_Program_Options_Decleration_Static_Data(path + name + "/class/class_parts/deceleration/static_part/data.hpp");
	Code_Paster::Put_Program_Options_Definition_Static_Data(path + name + "/class/class_parts/definition/static_part/data.hpp");
	
	Include_Manager::Turn_On_Header(path + name + "/class/class_parts/deceleration/includes_part/","<boost/program_options.hpp>");
	
	return;
}
