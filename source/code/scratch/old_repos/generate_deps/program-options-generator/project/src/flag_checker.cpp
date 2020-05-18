#include "flag_checker.hpp"
#include "flag_extractor.hpp"

void Flag_Checker::Run_Check(Program_Options const& program_options){

	//warn about empty meta data
	if (program_options.Author() == ""){
		std::cerr << "you should specify an author.\n";
	}
	if (program_options.Description() == ""){
		std::cerr << "you should specify a description.\n";
	}
	if (program_options.Website() == ""){
		std::cerr << "you should specify a website.\n";
	}
	if (program_options.Email_Address() == ""){
		std::cerr << "you should specify an email address.\n";
	}
	if (program_options.Tool_Name() == ""){
		std::cerr << "you should specify a tool name.\n";
	}
	if (program_options.Version_Number() == ""){
		std::cerr << "you should specify a version number.\n";
	}
	if (program_options.License() == ""){
		std::cerr << "you should specify the license that the software is under.\n";
	}


	//make sure flag structure is ok
	auto flags = Flag_Extractor::Extract_Flags(program_options);

	//make sure all the flags have either 'true' or 'false' for the boolean flags
	bool fatal_problem = false;
	for (auto const& it: flags) {

		if (it.mandatory != "true" && it.mandatory !=  "false") {
			fatal_problem = true;
			std::cout << it.mandatory << '\n';
			std::cerr << "Invalid mandatory flag. Use 'true' or 'false'\n";
		}

		if (it.positional != "true" && it.positional !=  "false") {
			fatal_problem = true;
			std::cout << it.positional << '\n';
			std::cerr << "Invalid positional flag. Use 'true' or 'false'\n";
		}

		if (it.multitoken != "true" && it.multitoken !=  "false") {
			fatal_problem = true;
			std::cout << it.multitoken << '\n';
			std::cerr << "Invalid multitoken flag. Use 'true' or 'false'\n";
		}

	}

	//quit if there are any fatal problems with the flags passed
	if (fatal_problem){
		exit(EXIT_FAILURE);
	}

	return;

	return;
}