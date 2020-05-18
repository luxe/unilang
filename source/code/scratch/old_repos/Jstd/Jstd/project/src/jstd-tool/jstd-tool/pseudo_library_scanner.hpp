#pragma once
#include <iostream>
#include <string>
#include "global.hpp"
#include "utilities.hpp"
#include "root_scanner.hpp"
#include "subfolder_scanner.hpp"
#include "compact_directory_scanner.hpp"
#include "expression_directory_scanner.hpp"
#include "program_options.hpp"
#include "pseudo_library_scanner_printer.hpp"

class Pseudo_Library_Scanner {

public:
	static bool Scan(Program_Options const& program_options, Warn_Machine & warn_machine, std::time_t const& last_run_time);

private:
	static bool Scan_Directories(Program_Options const& program_options, Warn_Machine & warn_machine, Pseudo_Library_Scanner_Printer & scanner_printer);
	static bool Scan_All_The_Sub_Folders(Program_Options const& program_options, Warn_Machine & warn_machine, Pseudo_Library_Scanner_Printer & scanner_printer);
	static bool Scan_Directory_And_All_Sub_Directories(Program_Options const& program_options, Warn_Machine & warn_machine, Pseudo_Library_Scanner_Printer & scanner_printer);


};
