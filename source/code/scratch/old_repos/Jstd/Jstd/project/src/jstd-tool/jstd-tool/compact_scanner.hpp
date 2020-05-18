#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "warn_machine.hpp"

class Compact_Scanner {

public:
	static bool Scan(Warn_Machine & warn_machine, std::string const& compact, int const& line_number, bool & anything_wrong_with_compact);

private:
	static bool Contains_Invalid_Characters(std::string const& compact);
};
