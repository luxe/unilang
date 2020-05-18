#pragma once
#include <string>
#include <vector>
#include <boost/filesystem.hpp>


// extern to avoid multiple inclusion
namespace global{
	extern bool COLORS_ENABLED ;
	extern unsigned long long include_gaurd_global;
	extern unsigned long long pragma_unique_maker_global;
}

namespace constant{

	//file name constants
	const std::string CODE_FILE = "code.hpp";
	const std::string HEADER_HPPS_FILE = "header_hpps";
	const std::string SOURCE_HPPS_FILE = "source_hpps";
	const std::string THIS_PROGRAM_FILE = "jstd-tool";
	const std::string INFO_FILE = "info";
	const std::string LAST_TIME_RAN_FILE = "last_time_ran";

	//directory location constants
	const std::string NAME_Of_ROOT_FOLDER_THAT_EXPORTER_SHOULD_RUN_IN = "pseudo";
	const std::string EXPORT_LIBRARY_ROOT_RELATIVE_TO_PSEUDO_LIBRARY_ROOT = "../jstd-export/raw/";
	const std::string BUILT_LIBRARY_ROOT_RELATIVE_TO_PSEUDO_LIBRARY_ROOT = "../jstd-export/built/";
	const std::string DOCUMENTATION_ROOT_RELATIVE_TO_PSEUDO_LIBRARY_ROOT = "../jstd-export/doc/";
	const std::string PATH_TO_REGEX_COMPACTS = (boost::filesystem::current_path() /= "../../src/" + THIS_PROGRAM_FILE +"/regex_compacts/").string();
	const std::string PATH_TO_REGEX_EXPRESSIONS = (boost::filesystem::current_path() /= "../../src/" + THIS_PROGRAM_FILE +"/regex_expressions/").string();

	//code file makers for pseudo library
	const std::string FUNCTION_PART_DELIMITER = "<----DELIM---->";
	const std::string START_OF_FUNCTION_MARKER = "<----------------------------START---------------------------->";
	const std::string END_OF_FUNCTION_MARKER = "<-----------------------------END----------------------------->";

	//used by pseudo library scanner
	const std::vector<std::string> NEEDED_FILES_FOR_EACH_PSEUDO_SUB_DIRECTORY = {CODE_FILE,HEADER_HPPS_FILE,SOURCE_HPPS_FILE,INFO_FILE};
	const std::vector<std::string> NEEDED_FILES_FOR_PSEUDO_ROOT_DIRECTORY =     {CODE_FILE,HEADER_HPPS_FILE,SOURCE_HPPS_FILE,INFO_FILE, THIS_PROGRAM_FILE,LAST_TIME_RAN_FILE};
	const std::vector<std::string> VALID_FOLDER_DECOMPOSITION_TYPES = {"root",
																		"function_root", "type_category", "type", "type_behaviour",
																		"constant_root", "constant_category",
																		"macro_root",    "macro_category",
																		"type_root",    "type_category",
																		};

	//default values
	constexpr unsigned short NUMBER_OF_AVAILABLE_FUNCTION_CASES = 4;
	// ^ ^ ^ ^ ^ ^ ^ ^ ^
	//not decided yet (I'm thinking more than functions because of a T at the end of the name.
	//Might want to do a fun_ infront of functions though too. So both might double or something.
	//def no all lowercase, because that is probably what the variable names will be.)
	constexpr unsigned short NUMBER_OF_AVAILABLE_TYPE_CASES = 0; //<- ?
	constexpr unsigned short NUMBER_OF_AVAILABLE_CONSTANT_CASES = 0; //<- ?

}
