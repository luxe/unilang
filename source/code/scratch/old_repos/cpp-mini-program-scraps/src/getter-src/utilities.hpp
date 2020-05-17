#pragma once
#include <boost/filesystem.hpp>
#include <fstream>
#include <gmpxx.h>

//utility

	//general system calling
	std::string exec(std::string const& cmd);
	std::string exec(const char* cmd);

	//filesystem stuff
	void Create_Path_If_It_Doesnt_Already_Exist(boost::filesystem::path const& path);
	std::string Current_Folder_Name(void);
	void Step_Into_Folder(std::string const folder_name);
	void Step_Out_Of_Folder(void);
	bool File_Exists(std::string const& filename);
	std::vector<std::string> Get_Dirs_Of_Path(std::string const& path);
	std::vector<std::string> Get_Files_Of_Path(std::string const& path);
	std::vector<std::string> Recursively_Get_All_Source_File_Paths_Of_Path(std::string const& path);
	int Recursively_Get_Directory_Count(std::string const& path = ".");
	int Get_Number_Of_Files_In_Directory(std::string const& path = ".");
	void Shortify_Path(boost::filesystem::path & path);
	unsigned int Get_Unsigned_Int_From_File(std::string const& file_name);
	void Append_Text_To_The_Top_Of_File(std::string const& file_name, std::string const& append_text);

	void Download_And_Save_HTML_File(std::string const& url, std::string const& file);
	
	std::string Get_Whole_File_As_String(std::string const& file_name);


	//string functions
	std::string& ltrim(std::string &s);
	std::string& rtrim(std::string &s);
	std::string&  trim(std::string &s);
	std::string& Squeeze_Away_Spaces(std::string &s);

		//basically: trim->squeeze away spaces->turn spaces into underscores->capitalize each word
		std::string Make_Capital_And_Underscored_In_User_Type_Format(std::string s);

		//basically: trim->squeeze away spaces->turn spaces into underscores->lowercase each word
		std::string Make_Lowercased_And_Underscored_In_User_Type_Format(std::string s);

	bool Space_At_The_Beginning(std::string const& s);
	bool Space_At_The_End(std::string const& s);
	bool Consecutive_Space_In_The_Middle(std::string s);
	bool Contains_Capital_Letters(std::string const& s);
	
	std::string& Remove_File_Extension(std::string & file_name);
	std::string Without_File_Extension(std::string file_name);
	
	
	bool String_Starts_With_String(std::string const& looking_in, std::string const& looking_for);
	bool String_Ends_With_String(std::string const& looking_in, std::string const& looking_for);
	bool Is_All_Whitespace(std::string const& str);
	
	void Remove_First_N_Characters(std::string & str, int const& amount);
	void Remove_Last_N_Characters(std::string & str, int const& amount);

	//vector functions
	template <typename T> void Sort_And_Remove_Duplicates(std::vector<T>& vec){
		std::sort(vec.begin(), vec.end());
		vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

	}
	bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str);

	//color functions
	std::string colorize(std::string const& message, int const& background, int const& forground);
	std::string colorize_forground(std::string const& message, int const& background);
	std::string colorize_background(std::string const& message, int const& forground);
	void Exit_With_Error_Message(std::string const& str);
	void Green_Message(std::string const& str);
	void Red_Message(std::string const& str);

	//file stream functions
	std::vector<std::vector<std::string>> Get_And_Parse_Each_Line_Of_File(std::string const& file);
	std::vector<std::vector<std::string>> Continue_Getting_And_Parsing_Each_Line_Of_File(std::ifstream & infile);
	std::vector<std::string> Get_All_Lines_of_File(std::string const& file);

	//gmp functions
	mpf_class add_all_elements(std::vector<mpf_class>);
	void Increment_Number_In_File(std::string const& file_name);
