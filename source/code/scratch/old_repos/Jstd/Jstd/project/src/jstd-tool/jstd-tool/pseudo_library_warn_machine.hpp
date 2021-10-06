#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <utility>
#include "pseudo_library_warn_log.hpp"

class Pseudo_Library_Warn_Machine {

public:

	Pseudo_Library_Warn_Machine(bool (*check)());

	//needed files (called by root or subfolder scanner)
	bool Record_Missing_File(std::string const& file);
	bool Record_Not_Needed_File(std::string const& file);

	//headers (called by header_scanner)
	bool Record_Duplicate_Header(std::string const& file, std::string const& header);
	bool Record_Uneeded_Header(std::string const& file, std::string const& header);

	//mis-cased folder names
	bool Record_Miscased_Folder(std::string const& folder);

	//unidentified decomposition type
	bool Record_Unidentified_Decomposition_Type(std::string const& file, std::string const& decomposition_type);

private:

	Pseudo_Library_Warn_Log m_warn_log;

	//function pointer to a bool returning function
	//this class does not contain how many total warnings can be held.  The only class
	//that contains that value is the warn_machine,  which inherits from all of the other warn_machine types.
	//in order to check if the limit has been reached each time a warning is logged, we will call the check function of the
	//warn_machine class.  Since inheritance doesn't work both ways, the warn_machine will pass its function to the
	//constructor of this class and any others that need to check the limit after adding a warning
	bool (*check)();

};
