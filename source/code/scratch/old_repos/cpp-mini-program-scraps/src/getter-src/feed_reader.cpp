#include "feed_reader.hpp"
#include "global.hpp"
#include "code_info.hpp"


//transformer (might change number_of_seconds_to_wait before refreshing)
void Feed_Reader::Get_New_Files() {

	//download the html feed file
	std::string file_name = constant::TESTING_DIRECTORY + Make_Lowercased_And_Underscored_In_User_Type_Format(to_string(web_feed.website) + "-" + web_feed.name + ".html");
	Download_And_Save_HTML_File(web_feed.url, file_name);

	//parse through it to get a list of code files
	std::ifstream infile(file_name);
	switch  (web_feed.website) {
		case Website::IDEONE:    Get_Ideone_Feed(infile);    break;
		case Website::PASTE_BIN: Get_Paste_Bin_Feed(infile); break;
		default:;
	}

	//now that we have a list of code files,
	//we will download the new ones
	Download_New_Files();

	return;
}

void Feed_Reader::Get_Ideone_Feed(std::ifstream & infile) {
	previous = current;
	current.clear();
	std::string line;
	std::string url_tag;
	std::string time;

	std::getline(infile, line);
	while (infile) {
		if (line == "<div class=\"source-view\">") {
			std::getline(infile, line);
			std::getline(infile, line);
			url_tag = Strip_Out_Url_For_Ideone(line);
			std::getline(infile, line);
			std::getline(infile, line);
			std::getline(infile, line);
			time = Strip_Out_Time_For_Ideone(line);
			//std::getline(infile, line);
			//std::getline(infile, line);
			//std::getline(infile, line);
			//std::getline(infile, line);
			//std::getline(infile, line);
			//std::getline(infile, line);
			//std::getline(infile, line);
			//std::getline(infile, line);
			//std::getline(infile, line);
			current.push_back(Code_File(url_tag, time));
		}
	std::getline(infile, line);
	}

	return;
}
std::string Feed_Reader::Strip_Out_Time_For_Ideone(std::string line) {
	auto it = line.find("title=\"");
	line.erase(0, it+7);
	std::string new_line;
	for (auto const& it: line) {
		if (it != '"') {
			new_line+=it;
		}else{break;}
	}


	//test to make sure time is read right
	//std::cout <<   "|" <<  new_line << "|" <<  std::endl;
	return new_line;
}
std::string Feed_Reader::Strip_Out_Url_For_Ideone(std::string line) {


	line.erase(0,std::string("<strong><a href=\"/").size()+2);
	std::string new_line;
	for (auto const it: line) {
		if (it != '"') {
			new_line+= it;
		}
		else{
			return new_line;
		}
	}


	return line;
}
/*
Pre_Check Feed_Reader::Strip_Out_Pre_Check_For_Ideone(std::string line) {

	std::size_t found = line.find("Success");
	if (found!=std::string::npos) { return Pre_Check::SUCCESS; }

	found = line.find("Compilation error");
	if (found!=std::string::npos) { return Pre_Check::FAILURE; }

	found = line.find("Runtime error");
	if (found!=std::string::npos) { return Pre_Check::RUN_TIME_ERROR; }

	found = line.find("Time limit exceeded");
	if (found!=std::string::npos){return Pre_Check::TIME_LIMIT_EXCEEDED; }

	return Pre_Check::TIME_LIMIT_EXCEEDED;
}
*/
/*
void Feed_Reader::Get_Run_Data_For_Ideone(std::string const& url_tag, std::string const& time, Pre_Check const& pre_check, std::string & input, std::string & output, std::string & compiler){


	//download the page that has the run data on it
	std::string file_name = constant::TESTING_DIRECTORY + Make_Lowercased_And_Underscored_In_User_Type_Format(to_string(web_feed.website) + "-" + web_feed.name + "-" + url_tag + "-" + time + "-" + as_abbreviation(pre_check) + ".run");
	Download_And_Save_HTML_File("http://ideone.com/" + url_tag, file_name);


	//get the input and output data
	std::ifstream infile(file_name);
	std::string line;
	std::getline(infile, line);
	while(infile){

		if (String_Starts_With_String(line,"<div id=\"stdin-text\" class=\"hidden\">")){
			input = Strip_Out_Input_For_Ideone(infile);

			while(infile){
				if (String_Starts_With_String(line,"		<pre id=\"output-text\">")){
					output = Strip_Out_Output_For_Ideone(line,infile);
				}

				std::getline(infile, line);
			}
		}
		std::getline(infile, line);
	}

	//get compiler options if there are any
	infile.close();
	infile.open(file_name);
	std::getline(infile, line);
	while(infile){
		if (String_Starts_With_String(line,"	<pre class=\"box\" id=\"view_cmperr_content\">")){
			compiler = Strip_Out_Compiler_Message_For_Ideone(line,infile);
		}
		std::getline(infile, line);
	}

	//remove that run file
	system(("rm -f " + file_name).c_str());




	return;
}
std::string Feed_Reader::Strip_Out_Input_For_Ideone(std::ifstream & infile){
	std::string str;
	std::string line;
	str+=line;
	while (!String_Ends_With_String(line,"</pre></div>")){
		std::getline(infile,line);
		str+='\n'+line;
	}

	Remove_First_N_Characters(str, 10);
	Remove_Last_N_Characters(str, 12);


	return str;

}
std::string Feed_Reader::Strip_Out_Output_For_Ideone(std::string const& top_line,std::ifstream & infile){
	std::string str;
	std::string line = top_line;
	str+=line;
	while (!String_Ends_With_String(line,"</pre>")){
		std::getline(infile,line);
		str+='\n'+line;
	}

	Remove_First_N_Characters(str, 24);
	Remove_Last_N_Characters(str, 6);

	if(String_Starts_With_String(str,"<p class=\"empty\">") && String_Ends_With_String(str,"</p>")){
		Remove_First_N_Characters(str, 17);
		Remove_Last_N_Characters(str, 4);
	}


	return str;
}
std::string Feed_Reader::Strip_Out_Compiler_Message_For_Ideone(std::string const& top_line,std::ifstream & infile){
	std::string str;
	std::string line = top_line;
	str+=line;
	while (!String_Ends_With_String(line,"</pre>")){
		std::getline(infile,line);
		str+='\n'+line;
	}

	Remove_First_N_Characters(str, 43);
	Remove_Last_N_Characters(str, 7);

	return str;
}
*/

void Feed_Reader::Get_Paste_Bin_Feed(std::ifstream & infile) {

	return;
}
void Feed_Reader::Download_New_Files() {

	// test that the time delay was an ok amount
	// and filter the current vector to only contain NEW files.
	// keep in mind,  they might only be new based on a timestamp and not actually a new code url
	auto size = current.size();
	std::sort(current.begin(), current.end());
	std::vector<Code_File> files_to_test;
	for (auto const& it: previous) {
		auto low = std::lower_bound (current.begin(), current.end(), it);
		if (low != current.end()) {
			current.erase(low);
		}
	}
	if (size ==  current.size()) {
		if (previous.size() !=  0) {
		std::cerr <<  std::string("delay was too long for " + web_feed.url + "\n"); std::cout.flush();
		//TODO: we should decrease it, so that it doesn't happen again.  But I'll wait to see if that ever actually happens
		}
	}


	switch  (web_feed.website) {
		case Website::IDEONE:    Download_Ideone_Files();   break;
		case Website::PASTE_BIN: Download_Pastebin_Files(); break;
		default:;
	}

	return;
};
void Feed_Reader::Download_Ideone_Files(){
	
	for (auto const& it: current) {
		Download_File(it.url_tag,
		constant::TESTING_DIRECTORY + Make_Lowercased_And_Underscored_In_User_Type_Format(to_string(web_feed.website) + "-" + web_feed.name + "-" + it.File_Name_Part() + ".cpp"),
		to_string(web_feed.website) + "-" + web_feed.name
		);
	}

	return;
}
void Feed_Reader::Download_File(std::string const& url_tag, std::string const& file_name, std::string const& suffix){
	
	//get code parts
	Code_Info code_info(url_tag,suffix);
	
	if (!code_info.skipped){
		std::ofstream outfile(file_name);
		outfile << code_info.source_code;
		
		outfile <<"\n/*";
		outfile << "stdin: " << code_info.stdin << '\n';
		outfile << "stdout: " << code_info.stdout << '\n';
		outfile << "stderr: " << code_info.stderr << '\n';
		outfile << "error: " << code_info.error << '\n';
		outfile << "status: " << code_info.status << '\n';
		outfile << "signal: " << code_info.signal << '\n';
		outfile << "result: " << code_info.result << '\n';
		outfile <<"\n*/";
		outfile.close();
	}else{
		std::cerr << "bail out downloading this apparently NEVER READY file" << std::endl;
	}
	
	return;
}
	
	
void Feed_Reader::Download_Pastebin_Files(){

	return;
}
