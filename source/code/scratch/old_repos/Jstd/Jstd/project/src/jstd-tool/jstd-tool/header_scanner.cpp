#include "header_scanner.hpp"
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include "utilities.hpp"
#include "global.hpp"

bool Header_Scanner::Scan(Warn_Machine & warn_machine) {

	 std::ifstream source(constant::SOURCE_HPPS_FILE);
	 std::ifstream header(constant::HEADER_HPPS_FILE);

	 std::string line;
	 std::vector<std::string> header_lines;
	 std::vector<std::string> source_lines;

	 //check the header_hpps file for errors if it exists
	 if (File_Exists(constant::HEADER_HPPS_FILE)){
		std::getline(header,line);
		while (header){
			header_lines.push_back(line);
			std::getline(header,line);
	 }
	  header.close();
	  Complain_About_Header_Duplicates(warn_machine,header_lines,constant::HEADER_HPPS_FILE);
	}

	 //check the source_hpps file for errors if it exists
	 if (File_Exists(constant::SOURCE_HPPS_FILE)){
	  std::getline(source,line);
	  while (source){
		source_lines.push_back(line);
		std::getline(source,line);
	 }
	  source.close();
	  Complain_About_Source_Duplicates(warn_machine,header_lines,source_lines,constant::SOURCE_HPPS_FILE);
	}

	return true;
}
bool Header_Scanner::Complain_About_Header_Duplicates(Warn_Machine & warn_machine, std::vector<std::string> const& header_lines,std::string const& file_name){

	std::vector<std::string> duplicates;
	bool found_duplicate = false;

	for (auto it = header_lines.begin(); it != header_lines.end(); ++it){
	 for (auto it2 = header_lines.begin(); it2 != header_lines.end() && !found_duplicate; ++it2){
	  if (it != it2){
	   if (*it == *it2){
		duplicates.push_back(*it);
		found_duplicate = true;
	  }
	 }
	}
	 found_duplicate = false;
   }

	Sort_And_Remove_Duplicates(duplicates);

	for (auto const& it: duplicates){
	 if (!warn_machine.Record_Duplicate_Header(file_name,it)) {return false;}
   }

	return true;
  }
bool Header_Scanner::Complain_About_Source_Duplicates(Warn_Machine & warn_machine, std::vector<std::string> const& header_lines, std::vector<std::string> const& source_lines,std::string const& file_name){

	std::vector<std::string> duplicates;
	bool found_duplicate = false;

	for (auto it = source_lines.begin(); it != source_lines.end(); ++it){
	 for (auto it2 = source_lines.begin(); it2 != source_lines.end() && !found_duplicate; ++it2){
	  if (it != it2){
	   if (*it == *it2){
		duplicates.push_back(*it);
		found_duplicate = true;
	  }
	 }
	}
	 found_duplicate = false;
   }

	Sort_And_Remove_Duplicates(duplicates);

	for (auto const& it: duplicates){
	 if (!warn_machine.Record_Duplicate_Header(file_name,it)) {return false;}
   }

	//CHECKS TO SEE IF A SOURCE HEADER ALREADY EXISTS IN THE HEADER HEADERS
	for (auto i: source_lines){
	 for (auto j: header_lines){
	  if (i == j){
	   if (!warn_machine.Record_Uneeded_Header(file_name,i)) {return false;}
	 }
	}
   }


	return true;
  }
