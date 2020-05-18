#include "expression_directory_scanner.hpp"
#include "global.hpp"
#include "utilities.hpp"
#include <string>
#include <iostream>
#include <fstream>

bool Expression_Directory_Scanner::Scan(Warn_Machine & warn_machine, Pseudo_Library_Resource_Scanner_Printer & printer) {

	auto files = Get_Files_Of_Path(constant::PATH_TO_REGEX_EXPRESSIONS);
	for (auto const& it: files){
		printer.Update();
		if (!Check_Expression(warn_machine,it)) {return false;}
   }

	return true;
}
bool Expression_Directory_Scanner::Check_Expression(Warn_Machine & warn_machine, std::string const& compact_file) {

	//I'm not quite sure I'm even going to let regular expressions include other regular expressions just yet
	
	return true;
}
