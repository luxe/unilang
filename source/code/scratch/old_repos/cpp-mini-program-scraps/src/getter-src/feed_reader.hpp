#pragma once
#include <string>
#include <cstdlib>
#include "utilities.hpp"
#include "web_feed.hpp"
#include "code_file.hpp"

struct Feed_Reader {


public:
	
	//constructor
	Feed_Reader(Web_Feed const& web_feed_in, unsigned int const& number_of_seconds_to_wait_in = 10)
	: web_feed(web_feed_in)
    , number_of_seconds_to_wait(number_of_seconds_to_wait_in)
    {}

    //transformer (might change number_of_seconds_to_wait before refreshing)
    void Get_New_Files();

private:
    // two different ways to obtain a feed of code files;
    // they make the current one the previous,  and fill the current one
	void Get_Ideone_Feed(std::ifstream & infile);
	void Get_Paste_Bin_Feed(std::ifstream & infile);

	//utility functions
    //possibly split ideone and pastebin into different objs
	static std::string Strip_Out_Url_For_Ideone(std::string line);
	static Pre_Check Strip_Out_Pre_Check_For_Ideone(std::string line);
	static std::string Strip_Out_Time_For_Ideone(std::string line);
	void Get_Run_Data_For_Ideone(std::string const& url_tag, std::string const& time, Pre_Check const& pre_check, std::string & input, std::string & output, std::string & compiler);
	static std::string Strip_Out_Input_For_Ideone(std::ifstream & infile);
	static std::string Strip_Out_Output_For_Ideone(std::string const& top_line,std::ifstream & infile);
	static std::string Strip_Out_Compiler_Message_For_Ideone(std::string const& top_line,std::ifstream & infile);
	
	void Download_New_Files();
		void Download_Ideone_Files();
		void Download_Pastebin_Files();
		
		static void Download_File(std::string const& url_tag, std::string const& file_name, std::string const& suffix);

public:
	
	//data members
	Web_Feed web_feed;
	std::vector<Code_File> previous;
	std::vector<Code_File> current;
	unsigned int number_of_seconds_to_wait;

};
