#include <iostream>
#include <string>
#include <utility>
#include "warn_log.hpp"
#include <tuple>

class Warn_Fixer {

public:
	static void Fix_Warnings(bool const& prompt, Warn_Log const& warn_log);

private:

	//needed files
	static void Add_Missing_File(bool const& prompt, std::string const& file);
	static void Delete_Uneeded_File(bool const& prompt, std::string const& file);

	//header
	static void Remove_Dups_From_Header(bool const& prompt, std::pair<std::string,std::string> const& it);
	static void Remove_Uneeded_From_Header(bool const& prompt, std::pair<std::string,std::string> const& it);

	//compact
	static void Fix_Invalid_Compact(bool const& prompt, std::tuple<std::string,int,std::string> const& it);
	static void Remove_Dups_From_Compact(bool const& prompt, std::pair<std::string,std::string> const& it);

	//mis-cased folder names
	static void Fix_Miscased_Folder(bool const& prompt, std::pair<std::string,std::string> const& it);
};
