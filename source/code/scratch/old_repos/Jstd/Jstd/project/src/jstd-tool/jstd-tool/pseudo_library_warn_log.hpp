#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <utility>

class Pseudo_Library_Warn_Log {

public:

	//needed files
	void Record_Missing_File(std::string const& file);
	void Record_Not_Needed_File(std::string const& file);
	std::vector<std::string> Get_Missing_Files() const;
	std::vector<std::string> Get_Not_Needed_Files() const;

	//headers
	void Record_Duplicate_Header(std::string const& file, std::string const& header);
	void Record_Uneeded_Header(std::string const& file, std::string const& header);
	std::vector<std::pair<std::string,std::string>> Get_Duplicate_Headers() const;
	std::vector<std::pair<std::string,std::string>> Get_Uneeded_Headers() const;

	//unidentified decomposition type
	void Record_Unidentified_Decomposition_Type(std::string const& file, std::string const& decomposition_type);
	std::vector<std::pair<std::string,std::string>> Get_Unidentified_Decomposition_Types() const;

	//mis-cased folder names
	void Record_Miscased_Folder(std::string const& path, std::string const& folder);
	std::vector<std::pair<std::string,std::string>> Get_Miscased_Folders() const;

	//all the problems wrong pseudo with code..

private:

	//needed files
	std::vector<std::string> m_missing_files;
	std::vector<std::string> m_not_needed_files;

	//headers
	std::vector<std::pair<std::string,std::string>> m_duplicated_headers;
	std::vector<std::pair<std::string,std::string>> m_uneeded_headers;

	//mis-cased folder names
	std::vector<std::pair<std::string,std::string>> m_miscased_folders;

	//unidentified decomposition type
	std::vector<std::pair<std::string,std::string>> m_unidentified_decomposition_types;

	//all the problems wrong with pseudo code..

};
