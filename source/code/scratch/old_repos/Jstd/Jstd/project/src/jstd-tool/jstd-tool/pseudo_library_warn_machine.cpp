#include "pseudo_library_warn_machine.hpp"
#include <boost/filesystem.hpp>
#include "utilities.hpp"

Pseudo_Library_Warn_Machine::Pseudo_Library_Warn_Machine(bool (*check_in)()) :
check(check_in)
{}

//needed files
bool Pseudo_Library_Warn_Machine::Record_Missing_File(std::string const& file) {

	m_warn_log.Record_Missing_File(boost::filesystem::current_path().string() + "/" + file);
	Red_Message(boost::filesystem::current_path().string() + "/" + file + " is missing!\n");
	return check();
 }
bool Pseudo_Library_Warn_Machine::Record_Not_Needed_File(std::string const& file) {

	m_warn_log.Record_Not_Needed_File(boost::filesystem::current_path().string() + "/" + file);
	Red_Message(boost::filesystem::current_path().string() + "/" + file + " should not exist!\n");
	return check();
  }

//headers
bool Pseudo_Library_Warn_Machine::Record_Duplicate_Header(std::string const& file, std::string const& header) {

	m_warn_log.Record_Duplicate_Header(boost::filesystem::current_path().string() + "/" + file, header);
	Red_Message(boost::filesystem::current_path().string() + "/" + file + " contains the header " + header + " multiple times!\n");
	return check();
  }
bool Pseudo_Library_Warn_Machine::Record_Uneeded_Header(std::string const& file, std::string const& header) {

	m_warn_log.Record_Uneeded_Header(boost::filesystem::current_path().string() + "/" + file, header);
	Red_Message(boost::filesystem::current_path().string() + "/" + file + " contains the uneeded header " + header + "!\n");
	return check();
  }

//mis-cased folder names
bool Pseudo_Library_Warn_Machine::Record_Miscased_Folder(std::string const& folder) {

	m_warn_log.Record_Miscased_Folder(boost::filesystem::current_path().string() + "/", folder);
	Red_Message(boost::filesystem::current_path().string() + "/" + folder + " should be lowercased!\n");
	return check();
 }

//unidentified decomposition type
bool Pseudo_Library_Warn_Machine::Record_Unidentified_Decomposition_Type(std::string const& file, std::string const& decomposition_type) {

	m_warn_log.Record_Unidentified_Decomposition_Type(boost::filesystem::current_path().string() + "/" + file, decomposition_type);
	if (decomposition_type ==  "") {
		Red_Message(boost::filesystem::current_path().string() + "/" + file + " contains a missing decomposition type!\n");
	}else{
		Red_Message(boost::filesystem::current_path().string() + "/" + file + " contains the invalid decomposition type " + decomposition_type + "!\n");
	}
	return check();
  }
