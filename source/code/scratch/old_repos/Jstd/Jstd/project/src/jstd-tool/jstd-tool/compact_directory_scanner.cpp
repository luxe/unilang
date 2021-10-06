#include "compact_directory_scanner.hpp"
#include "compact_scanner.hpp"
#include "global.hpp"
#include "utilities.hpp"
#include <string>
#include <iostream>
#include <fstream>

bool Compact_Directory_Scanner::Scan(Warn_Machine & warn_machine, Pseudo_Library_Resource_Scanner_Printer & printer) {

	auto files = Get_Files_Of_Path(constant::PATH_TO_REGEX_COMPACTS);
	for (auto const& it: files){
		printer.Update();
		if (!Check_Compact(warn_machine,it)) {return false;}
   }

	return true;
}

bool Compact_Directory_Scanner::Check_Compact(Warn_Machine & warn_machine, std::string const& compact_file) {

	//read all entries of compacts into a vector of strings
	std::string path_to_file = constant::PATH_TO_REGEX_COMPACTS + "/" + compact_file;
	std::string line;
	std::vector<std::string> lines;
	std::ifstream infile(path_to_file);
	std::getline(infile,line);
	while (infile){
		lines.push_back(line);
		std::getline(infile,line);
   }
	infile.close();

	//now that we have a vector,  which is easier to work with,
	//check to see if there are any problems with this particular compact file.
	if (!Check_Compact_File_And_Corresponding_Compacts(warn_machine, lines,path_to_file)) {return false;}

	return true;
}
bool Compact_Directory_Scanner::Check_Compact_File_And_Corresponding_Compacts(Warn_Machine & warn_machine, std::vector<std::string> const& lines, std::string const& path_to_file) {


	std::vector<std::string> duplicates;
	bool found_duplicate = false;

	int i = 0;
	bool anything_wrong_with_compact = false;
	for (auto it = lines.cbegin(); it != lines.cend(); ++it){
		for (auto it2 = lines.cbegin(); it2 != lines.cend() && !found_duplicate; ++it2){

			//check if the format of the compact is valid
			if (!Compact_Scanner::Scan(warn_machine, *it, i, anything_wrong_with_compact)){return false;}


			//if nothing is wrong with the compact,  consider it as possibly having a duplicate issue
			if (!anything_wrong_with_compact) {
				if (it != it2){
					if (*it == *it2){
						duplicates.push_back(*it);
						found_duplicate = true;
					}
				}
			}


		}
		found_duplicate = false;
		anything_wrong_with_compact = false;
		++i;
	}

	//record duplicates
	Sort_And_Remove_Duplicates(duplicates);
	for (auto const& it: duplicates){
		if (!warn_machine.Record_Duplicate_Compact(path_to_file, it)) {return false;}
	}

	return true;
  }
