#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "warn_machine.hpp"

class Expression_Scanner {

public:
	static bool Scan(Warn_Machine & warn_machine, std::string const& expression);
};
