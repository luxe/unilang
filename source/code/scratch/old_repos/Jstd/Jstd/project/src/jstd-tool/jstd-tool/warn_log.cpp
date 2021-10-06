#include "warn_log.hpp"

//compacts
void Warn_Log::Record_Duplicate_Compact(std::string const& file, std::string const& compact){
	m_duplicated_compacts.push_back(std::pair<std::string,std::string>(file,compact));
	return;
  }
void Warn_Log::Record_Invalid_Compact(std::string const& file, int const& line_number, std::string const& problems){
	m_invalid_compacts.push_back(std::tuple<std::string,int,std::string>(file,line_number,problems));
	return;
  }
std::vector<std::pair<std::string,std::string>> Warn_Log::Get_Duplicate_Compacts() const{
	return m_duplicated_compacts;
  }
std::vector<std::tuple<std::string,int,std::string>> Warn_Log::Get_Invalid_Compacts() const{
	return m_invalid_compacts;
  }
