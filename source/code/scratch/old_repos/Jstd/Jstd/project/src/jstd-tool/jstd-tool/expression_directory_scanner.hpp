#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "warn_machine.hpp"
#include "pseudo_library_resource_scanner_printer.hpp"

class Expression_Directory_Scanner {

public:
	static bool Scan(Warn_Machine & warn_machine, Pseudo_Library_Resource_Scanner_Printer & printer);

private:
	static bool Check_Expression(Warn_Machine & warn_machine, std::string const& compact_file);
};
