#pragma once
#include <string>
#include "warn_log.hpp"

class Warn_Machine{

public:
	//constructor
	Warn_Machine(int const& warn_amount);

	//compacts (called by compact_scanner)
	bool Record_Duplicate_Compact(std::string const& file, std::string const& compact);
	bool Record_Invalid_Compact(std::string const& file, int const& line_number, std::string const& problems);

	//fix all of the warnings or prompt to fix them all (called by the scanner)
	void Fix_Warnings(bool const& prompt);


private:
	bool Decide_If_Limit_Is_Reached();

	int m_warn_amount; //negative anything is infinity
	Warn_Log m_warn_log;

};
