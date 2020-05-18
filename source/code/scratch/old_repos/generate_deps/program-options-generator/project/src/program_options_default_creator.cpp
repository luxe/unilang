#include "program_options_default_creator.hpp"

void Program_Options_Default_Creator::Create_HPP(std::ofstream & outfile, Program_Options const& program_options) {

	outfile << "#pragma once\n";
	outfile << "#include <string>\n";
	outfile << '\n';
	outfile << "class Program_Options_Default{\n";
	outfile << "\t\n";
	outfile << "\t// Constructor\n";
	outfile <<  "\tprotected: explicit Program_Options_Default();\n";
	outfile << "\t\n";

	if (!program_options.Author().empty()){
		outfile << "\t// the author or organization responsible for the software\n";
		outfile << "\t// (applied by the flag value --author)\n";
		outfile << "\tconst std::string AUTHOR =\n";
		outfile << "\t\"" << program_options.Author() << "\"\n\t;\n\t\n";
	}

	if (!program_options.Description().empty()){
		outfile << "\t// a description of the software\n";
		outfile << "\t// (applied by the flag value --description)\n";
		outfile << "\tconst std::string DESCRIPTION =\n";
		outfile << "\t\"" << program_options.Description() << "\"\n\t;\n\t\n";
	}

	if (!program_options.Website().empty()){
		outfile << "\t//website to get code and further information about the software\n";
		outfile << "\t// (applied by the flag value --website)\n";
		outfile << "\tconst std::string WEBSITE =\n";
		outfile << "\t\"" << program_options.Website() << "\"\n\t;\n\t\n";
	}

	if (!program_options.Email_Address().empty()){
		outfile << "\t//email address to contact about the software\n";
		outfile << "\t// (applied by the flag value --email_address)\n";
		outfile << "\tconst std::string EMAIL_ADDRESS =\n";
		outfile << "\t\"" << program_options.Email_Address() << "\"\n\t;\n\t\n";
	}

	if (!program_options.Tool_Name().empty()){
		outfile << "\t//the name of the software tool\n";
		outfile << "\t// (applied by the flag value --tool_name)\n";
		outfile << "\tconst std::string TOOL_NAME =\n";
		outfile << "\t\"" << program_options.Tool_Name() << "\"\n\t;\n\t\n";
	}

	if (!program_options.Version_Number().empty()){
		outfile << "\t//the version number of the software\n";
		outfile << "\t// (applied by the flag value --version_number)\n";
		outfile << "\tconst std::string VERSION_NUMBER =\n";
		outfile << "\t\"" << program_options.Version_Number() << "\"\n\t;\n\t\n";
	}

	if (!program_options.License().empty()){
		outfile << "\t//the license that the software is under\n";
		outfile << "\t// (applied by the flag value --license)\n";
		outfile << "\tconst std::string LICENSE =\n";
		outfile << "\t\"" << program_options.License() << "\"\n\t;\n\t\n";
	}

	outfile << "};\n";

	return;
}
void Program_Options_Default_Creator::Create_CPP(std::ofstream & outfile, Program_Options const& program_options) {
	outfile << "#include \"program_options_default.hpp\"\n";
	outfile << "Program_Options_Default::Program_Options_Default(){}\n";
	return;
}
