#include "program_options_checker.hpp"
#include "global.hpp"

void Program_Options_Checker::Check(Program_Options const& program_options){

	Make_Sure_An_Actual_Task_Is_Being_Performed(program_options);
	Make_Sure_The_Cases_Flag_Has_An_Appropiate_Value(program_options);
	Make_Sure_At_Least_One_Header_Gaurd_Is_Being_Used(program_options);

	return;
}
void Program_Options_Checker::Make_Sure_An_Actual_Task_Is_Being_Performed(Program_Options const& program_options){

	//must be doing a scan, export, build, document, or stats task
	if (!(program_options.Scan() || program_options.Export() || program_options.Build() || program_options.Documentation() || program_options.Stats())){
		std::cerr << "You need to perform at least one task!\n";
		exit(EXIT_FAILURE);
	}

	return;
}
void Program_Options_Checker::Make_Sure_The_Cases_Flag_Has_An_Appropiate_Value(Program_Options const& program_options){

	std::string data = program_options.Cases();
    if (data.size() != constant::NUMBER_OF_AVAILABLE_FUNCTION_CASES){
		std::cerr << "--cases flag does not have enough values specified! ";
		std::cerr << "You need to provide " << constant::NUMBER_OF_AVAILABLE_FUNCTION_CASES << '\n';
		exit(EXIT_FAILURE);
	}

	return;
}
void Program_Options_Checker::Make_Sure_At_Least_One_Header_Gaurd_Is_Being_Used(Program_Options const& program_options){

	if (!(program_options.Inclusion_Guards()  ||  program_options.Pragma_Once())) {
		std::cerr << "you need to have at least one kind of guard against multiple inclusion! Use pragma once or inclusion guards.\n";
		exit(EXIT_FAILURE);
	}

	return;
}
