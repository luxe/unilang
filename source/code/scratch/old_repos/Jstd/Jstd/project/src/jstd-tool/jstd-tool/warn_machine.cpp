#include "warn_machine.hpp"
#include "warn_fixer.hpp"
#include "utilities.hpp"
#include <cstdlib>
#include <string>

//constructor
Warn_Machine::Warn_Machine(int const& warn_amount):
m_warn_amount(warn_amount)
{}

//compacts
bool Warn_Machine::Record_Duplicate_Compact(std::string const& file, std::string const& compact) {

	m_warn_log.Record_Duplicate_Compact(boost::filesystem::current_path().string() + "/" + file, compact);
	Red_Message(boost::filesystem::current_path().string() + "/" + file + " contains the compact " + compact + " multiple times!\n");
	return Decide_If_Limit_Is_Reached();

  }
bool Warn_Machine::Record_Invalid_Compact(std::string const& file, int const& line_number, std::string const& problems) {

	m_warn_log.Record_Invalid_Compact(boost::filesystem::current_path().string() + "/" + file, line_number, problems);
	Red_Message(boost::filesystem::current_path().string() + "/" + file + " contains an invalid compact at line " + std::to_string(line_number) + "!  It has the following problems: " + problems + "\n");
	return Decide_If_Limit_Is_Reached();

  }

void Warn_Machine::Fix_Warnings(bool const& prompt) {
	Warn_Fixer::Fix_Warnings(prompt, m_warn_log);
	return;
 }


bool Warn_Machine::Decide_If_Limit_Is_Reached(){

	if (m_warn_amount >= 0){

	 if (m_warn_amount == 0){
	  return false;
	}
	 --m_warn_amount;

   }

	return true;
  }
