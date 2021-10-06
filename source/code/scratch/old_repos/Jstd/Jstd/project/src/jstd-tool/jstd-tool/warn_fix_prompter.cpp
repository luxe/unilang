#include "warn_fix_prompter.hpp"

bool Warn_Fix_Prompter::Prompt_To_Add_File(std::string const& file){
	std::cout << "add file " << file << "?";
	return Prompt();
  }
bool Warn_Fix_Prompter::Prompt_To_Delete_File(std::string const& file){
	std::cout << "delete file " << file << "?";
	return Prompt();
  }
bool Warn_Fix_Prompter::Prompt_To_Delete_Duplicate_Header(std::pair<std::string,std::string> const& it){
	std::cout << "delete duplicate header " << it.second << " in " << it.first << "?";
	return Prompt();
  }
bool Warn_Fix_Prompter::Prompt_To_Delete_Uneeded_Header(std::pair<std::string,std::string> const& it){
	std::cout << "delete unneeded header " << it.second << " in " << it.first << "?";
	return Prompt();
  }
bool Warn_Fix_Prompter::Prompt_To_Delete_Empty_Compact(std::pair<std::string,std::string> const& it){
	std::cout << "delete empty contact in " << it.first << "?";
	return Prompt();
  }
bool Warn_Fix_Prompter::Prompt_To_Delete_Duplicate_Compact(std::pair<std::string,std::string> const& it){
	std::cout << "delete duplicate compact " << it.second << " in " << it.first << "?";
	return Prompt();
  }
bool Warn_Fix_Prompter::Prompt_To_Fix_Folder_Casing(std::pair<std::string,std::string> const& it) {
	std::cout << "fix the casing in folder " << it.first << it.second <<  "?";
	return Prompt();
  }

bool Warn_Fix_Prompter::Prompt(){
	bool yes = true;
	std::cout << " (y/n)? ";
	char c;
	std::cin >> c;
	while (c != 'y' && c != 'n'){
	 std::cout << "(y/n)? ";
	 std::cin >> c;

   }

	if (c != 'y'){
	 yes = false;
   }

	return yes;
  }
