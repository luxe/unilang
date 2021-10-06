#include "compact_scanner.hpp"
#include "utilities.hpp"


bool Compact_Scanner::Scan(Warn_Machine & warn_machine, std::string const& compact, int const& line_number, bool & anything_wrong_with_compact) {

	//record possible problems with the compact
	std::vector<std::string> problems;
	if (Space_At_The_Beginning(compact))             {problems.push_back("space at beginning");}
	if (Space_At_The_End(compact))                   {problems.push_back("space at end");}
	if (Consecutive_Space_In_The_Middle(compact))    {problems.push_back("consecutive space in the middle");}
	if (Contains_Invalid_Characters(compact))        {problems.push_back("contains invalid characters");}

	//if there is at least one problem with the contact,
	//create a string that lists the problems.
	if (!problems.empty()) {
		int number_of_commas = problems.size()-1;
		std::string list_of_problems = "(";
		for (auto const& it: problems) {
			list_of_problems += it;
			if (number_of_commas != 0) {
				list_of_problems += ", ";
				--number_of_commas;
			}
		}
		list_of_problems += ")";

		//log the warning
		if (!warn_machine.Record_Invalid_Compact(compact, line_number, list_of_problems)) {return false;}
	}



	return true;
}
bool Compact_Scanner::Contains_Invalid_Characters(std::string const& compact) {

	for (auto const& it: compact) {
		if (!std::tolower(it) && it != ' ') {
			return true;
		}
	}

	return false;
}
