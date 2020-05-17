#include "command_line_validator.hpp"

void Command_Line_Validator::Validate_Task_Flag(Program_Options const& program_options){
	
	//make sure that exactly one program task has been specified
	bool valid_name = false;
	if(program_options.Task() == ""){
		std::cerr << "You must specify a program task to be performed.\n";
		exit(EXIT_FAILURE);
	}
	
	//Project Tasks
	if (program_options.Task()     == "mk_project"       ){valid_name = true;}
	
	//Main Tasks
	else if(program_options.Task() == "mk_main"          ){valid_name = true;}
	else if(program_options.Task() == "rm_main"          ){valid_name = true;}
	else if(program_options.Task() == "rn_main"          ){valid_name = true;}
	else if(program_options.Task() == "cp_main"          ){valid_name = true;}
	
	//Class Tasks
	else if(program_options.Task() == "mk_class"         ){valid_name = true;}
	else if(program_options.Task() == "rm_class"         ){valid_name = true;}
	else if(program_options.Task() == "rn_class"         ){valid_name = true;}
	else if(program_options.Task() == "cp_class"         ){valid_name = true;}
	else if(program_options.Task() == "mv_class"         ){valid_name = true;}
	
	//Enum Class Tasks
	else if(program_options.Task() == "mk_enum_class"    ){valid_name = true;}
	else if(program_options.Task() == "rm_enum_class"    ){valid_name = true;}
	else if(program_options.Task() == "rn_enum_class"    ){valid_name = true;}
	else if(program_options.Task() == "cp_enum_class"    ){valid_name = true;}
	else if(program_options.Task() == "mv_enum_class"    ){valid_name = true;}
	
	if (!valid_name){
		std::cerr << "Invalid Task Specified.\n";
		exit(EXIT_FAILURE);
	}
	
	
	return;
}
void Command_Line_Validator::Validate_MK_Project_Flags(std::vector<std::string> const& project_names, std::vector<std::string> & main_module_names){
	
	//error out if no project names were provided
	if (project_names.empty()){
		std::cerr << "you must provide project names to be built\n";
		exit(EXIT_FAILURE);
	}
	
	//if no main module names are provided, just use "main" as the default
	if (main_module_names.empty()){
		main_module_names.push_back("main");
	}
	
	return;
}
void Command_Line_Validator::Validate_MK_Main_Flags(std::vector<std::string> & main_module_names){
	
	//error out if no main module names were provided
	if (main_module_names.empty()){
		std::cerr << "you must provide main module names to be built\n";
		exit(EXIT_FAILURE);
	}

	return;
}
void Command_Line_Validator::Validate_RM_Main_Flags(std::vector<std::string> & main_module_names){
	
	//error out if no main module names were provided
	if (main_module_names.empty()){
		std::cerr << "you must provide main module names to be removed\n";
		exit(EXIT_FAILURE);
	}

	return;
}
void Command_Line_Validator::Validate_RN_Main_Flags(std::vector<std::pair<std::string,std::string>> & main_module_names){
	
	//error out if no main module names were provided
	if (main_module_names.empty()){
		std::cerr << "you must provide main module names to be renamed\n";
		exit(EXIT_FAILURE);
	}

	return;
}
void Command_Line_Validator::Validate_CP_Main_Flags(std::vector<std::pair<std::string,std::string>> & main_module_names){
	
	//error out if no main module names were provided
	if (main_module_names.empty()){
		std::cerr << "you must provide main module names to be copied\n";
		exit(EXIT_FAILURE);
	}

	return;
}
void Command_Line_Validator::Validate_MK_Class_Flags(std::vector<std::string> const& class_names){
	
	//error out if no class names were provided
	if (class_names.empty()){
		std::cerr << "you must provide class names to be built\n";
		exit(EXIT_FAILURE);
	}
	
	return;
}



