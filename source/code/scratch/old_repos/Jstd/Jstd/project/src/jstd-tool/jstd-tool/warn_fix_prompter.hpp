#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

class Warn_Fix_Prompter {

	//non-constructible
	Warn_Fix_Prompter()=delete;

public:

	static bool Prompt_To_Add_File(std::string const& file);
	static bool Prompt_To_Delete_File(std::string const& file);
	static bool Prompt_To_Delete_Duplicate_Header(std::pair<std::string,std::string> const& it);
	static bool Prompt_To_Delete_Uneeded_Header(std::pair<std::string,std::string> const& it);
	static bool Prompt_To_Delete_Empty_Compact(std::pair<std::string,std::string> const& it);
	static bool Prompt_To_Delete_Duplicate_Compact(std::pair<std::string,std::string> const& it);
	static bool Prompt_To_Fix_Folder_Casing(std::pair<std::string,std::string>  const& it);
private:
	static bool Prompt();

};
