#include "flag_extractor.hpp"
#include "utilities.hpp"


std::vector<Flag_Line> Flag_Extractor::Extract_Flags(Program_Options const& program_options){

	std::vector<Flag_Line> flag_lines;
	try{
		//put command line flag flags into an easier data structure to traverse
		auto flags_data = Convert_Vector_Of_Strings_To_Vector_Of_Vectors(program_options.Flags());

		//traverse that data structure to create a vector of flag_data objects
		for (auto it: flags_data) {
			flag_lines.push_back(Flag_Line(it[0], it[1], it[2], it[3], it[4], it[5], it[6], it[7], it[8]));
		}
	}catch (...) {
		std::cerr <<  "flag data incorrect\n";
		exit(EXIT_FAILURE);
	}

	return flag_lines;
}