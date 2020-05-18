#include "pseudo_library_warn_log.hpp"
#include "utilities.hpp"

//needed files
void Pseudo_Library_Warn_Log::Record_Missing_File(std::string const& file){
	m_missing_files.push_back(file);
	return;
  }
void Pseudo_Library_Warn_Log::Record_Not_Needed_File(std::string const& file){
	m_not_needed_files.push_back(file);
	return;
  }
std::vector<std::string> Pseudo_Library_Warn_Log::Get_Missing_Files() const{
	return m_missing_files;
  }
std::vector<std::string> Pseudo_Library_Warn_Log::Get_Not_Needed_Files() const{
	return m_not_needed_files;
  }

//headers
void Pseudo_Library_Warn_Log::Record_Duplicate_Header(std::string const& file, std::string const& header){
	m_duplicated_headers.push_back(std::pair<std::string,std::string>(file,header));
	return;
  }
void Pseudo_Library_Warn_Log::Record_Uneeded_Header(std::string const& file, std::string const& header){
	m_uneeded_headers.push_back(std::pair<std::string,std::string>(file,header));
	return;
  }
std::vector<std::pair<std::string,std::string>> Pseudo_Library_Warn_Log::Get_Duplicate_Headers() const{
	return m_duplicated_headers;
  }
std::vector<std::pair<std::string,std::string>> Pseudo_Library_Warn_Log::Get_Uneeded_Headers() const{
	return m_uneeded_headers;
  }

//mis-cased folder names
void Pseudo_Library_Warn_Log::Record_Miscased_Folder(std::string const& path, std::string const& folder) {
	m_miscased_folders.push_back(std::pair<std::string,std::string>(path,folder));
	return;
 }
std::vector<std::pair<std::string,std::string>> Pseudo_Library_Warn_Log::Get_Miscased_Folders() const {
	return m_miscased_folders;
 }

//unidentified decomposition type
void Pseudo_Library_Warn_Log::Record_Unidentified_Decomposition_Type(std::string const& file, std::string const& decomposition_type) {
	m_unidentified_decomposition_types.push_back(std::pair<std::string,std::string>(file, decomposition_type));
	return;
 }
std::vector<std::pair<std::string,std::string>> Pseudo_Library_Warn_Log::Get_Unidentified_Decomposition_Types() const {
	return m_unidentified_decomposition_types;
 }
