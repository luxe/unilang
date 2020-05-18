#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "warn_machine.hpp"
#include "pseudo_library_resource_scanner_printer.hpp"

class Compact_Directory_Scanner {

public:
	static bool Scan(Warn_Machine & warn_machine, Pseudo_Library_Resource_Scanner_Printer & printer);

private:
	static bool Check_Compact(Warn_Machine & warn_machine, std::string const& compact_file);
	static bool Check_Compact_File_And_Corresponding_Compacts(Warn_Machine & warn_machine, std::vector<std::string> const& lines, std::string const& path_to_file);
};
