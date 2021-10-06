#pragma once
#include <iostream>
#include <string>
#include "global.hpp"
#include "utilities.hpp"
#include "program_options.hpp"
#include "warn_machine.hpp"
#include "pseudo_library_resource_scanner_printer.hpp"

class Pseudo_Library_Resource_Scanner {

public:
	static bool Scan(Program_Options const& program_options, Warn_Machine & warn_machine, std::time_t const& last_run_time);

};
