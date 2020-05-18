#include "pseudo_library_resource_scanner.hpp"
#include "pseudo_library_resource_scanner_printer.hpp"
#include "compact_directory_scanner.hpp"
#include "expression_directory_scanner.hpp"

bool Pseudo_Library_Resource_Scanner::Scan(Program_Options const& program_options, Warn_Machine & warn_machine, std::time_t const& last_run_time) {

	//create the object that will keep track of the percentage
	Pseudo_Library_Resource_Scanner_Printer printer;

	//scan other things that are not a part of the pseudo library structure
	if (!Compact_Directory_Scanner::Scan(warn_machine, printer))      {return false;}
	if (!Expression_Directory_Scanner::Scan(warn_machine, printer))   {return false;}

	//scan of the pseudo library resources is complete
	printer.Update();

	return true;
}
