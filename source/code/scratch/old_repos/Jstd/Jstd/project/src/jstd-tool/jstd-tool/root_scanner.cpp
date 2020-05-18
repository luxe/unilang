#include "root_scanner.hpp"
#include "global.hpp"
#include "utilities.hpp"
#include "warn_machine.hpp"
#include "header_scanner.hpp"
#include "code_scanner.hpp"
#include "info_scanner.hpp"

bool Root_Scanner::Scan(Warn_Machine & warn_machine) {

	if (!Make_Sure_The_Necessary_Files_Are_Present_At_Root(warn_machine)) { return false;}
	else if (!Make_Sure_No_Extra_Files_Exist_At_Root(warn_machine))       { return false;}
	else if (!Header_Scanner::Scan(warn_machine))                         { return false;}
	else if (!Code_Scanner::Scan(warn_machine))                           { return false;}
	else if (!Info_Scanner::Scan(warn_machine))                           { return false;}
	return true;
}
bool Root_Scanner::Make_Sure_The_Necessary_Files_Are_Present_At_Root(Warn_Machine & warn_machine){

	for (auto const& file: constant::NEEDED_FILES_FOR_PSEUDO_ROOT_DIRECTORY){
	 if (!File_Exists(file)){
	  if (!warn_machine.Record_Missing_File(file)) { return false;}
	}
   }

	return true;
  }
bool Root_Scanner::Make_Sure_No_Extra_Files_Exist_At_Root(Warn_Machine & warn_machine){

	auto files = Get_Files_Of_Path(boost::filesystem::current_path().string());

	for (auto const& file: files){
	 if (!String_In_Vector(constant::NEEDED_FILES_FOR_PSEUDO_ROOT_DIRECTORY, file)){
	  if (!warn_machine.Record_Not_Needed_File(file)) { return false; }
	}
   }
	return true;
  }
