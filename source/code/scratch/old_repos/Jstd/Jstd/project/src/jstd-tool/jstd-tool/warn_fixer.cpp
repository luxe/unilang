#include "warn_fixer.hpp"
#include "warn_fix_prompter.hpp"
#include "utilities.hpp"
#include <fstream>

void Warn_Fixer::Fix_Warnings(bool const& prompt, Warn_Log const& warn_log) {

	//needed files
	for (auto const& file: warn_log.Get_Missing_Files()) {
		Add_Missing_File(prompt,file);
	}
	for (auto const& file: warn_log.Get_Not_Needed_Files()) {
		Delete_Uneeded_File(prompt,file);
	}

	//headers
	for (auto const& it: warn_log.Get_Duplicate_Headers()) {
		Remove_Dups_From_Header(prompt,it);
	}
	for (auto const& it: warn_log.Get_Uneeded_Headers()) {
		Remove_Uneeded_From_Header(prompt,it);
	}

	//compacts
	for (auto const& it: warn_log.Get_Invalid_Compacts()) {
		Fix_Invalid_Compact(prompt,it);
	}
	for (auto const& it: warn_log.Get_Duplicate_Compacts()) {
		Remove_Dups_From_Compact(prompt,it);
	}

	//mis-cased folder names
	for (auto const& file: warn_log.Get_Miscased_Folders()) {
		Fix_Miscased_Folder(prompt,file);
	}

	return;
}

//needed files
void Warn_Fixer::Add_Missing_File(bool const& prompt, std::string const& file) {

	//decide whether to actually perform the fix if prompted
	if (prompt) {if (!Warn_Fix_Prompter::Prompt_To_Add_File(file)) {return;}}

	//add file
	system(("touch " + file).c_str());

	return;
 }
void Warn_Fixer::Delete_Uneeded_File(bool const& prompt, std::string const& file) {

	//decide whether to actually perform the fix if prompted
	if (prompt) {if (!Warn_Fix_Prompter::Prompt_To_Delete_File(file)) {return;}}

	//delete file
	system(("rm -f " + file).c_str());

	return;
  }

//header
void Warn_Fixer::Remove_Dups_From_Header(bool const& prompt, std::pair<std::string,std::string> const& it) {

	//decide whether to actually perform the fix if prompted
	if (prompt) {if (!Warn_Fix_Prompter::Prompt_To_Delete_Duplicate_Header(it)) {return;}}

	//read all the lines of the header into a vector
	 std::vector<std::string> vec;
	 std::ifstream infile(it.first);
	 std::string str;
	 std::getline(infile,str);
	 while (infile){
		vec.push_back(str);
		std::getline(infile,str);
	}
	 infile.close();
	std::cout <<  std::endl <<  it.first <<  std::endl;
	 //spit all the information back into the file,
	 //but makes sure the duplicate header in question is only put back in once
	 std::ofstream outfile(it.first);
	 bool found = false;
	for (auto it2: vec){
		if (it2 == it.second){
			if (!found){
				outfile << it2 << '\n';
				found = true;
			}
		}else{
			outfile << it2 << '\n';
		}
	}



	return;
  }
void Warn_Fixer::Remove_Uneeded_From_Header(bool const& prompt, std::pair<std::string,std::string> const& it) {

	//decide whether to actually perform the fix if prompted
	if (prompt) {if (!Warn_Fix_Prompter::Prompt_To_Delete_Uneeded_Header(it)) {return;}}

	//read all the lines of the header into a vector
	std::vector<std::string> vec;
	std::ifstream infile(it.first);
	std::string str;
	std::getline(infile,str);
	while (infile){
	 vec.push_back(str);
	 std::getline(infile,str);
   }
	infile.close();

	//spit all the information back into the file,
	//but makes sure the uneeded header in question is not put back in
	std::ofstream outfile(it.first);
	for (auto it2: vec){
	 if (it2 != it.second){
	  outfile << it2 << '\n';
	}
   }

	return;
  }

//compact
void Warn_Fixer::Fix_Invalid_Compact(bool const& prompt, std::tuple<std::string,int,std::string> const& it) {


	//decide whether to handle a whitespace problem
	//if (Space_At_The_Beginning(compact)  || Space_At_The_End(compact)  || Consecutive_Space_In_The_Middle(compact)) {
	// if (prompt) {if (!Warn_Fix_Prompter::Prompt_To_Fix_Spacing_In_Compact(it)) {return;}}
	//}

	//decide whether to handle a whitespace problem
	//if ()
	//decide whether to actually perform the fix if prompted
	//if (prompt) {if (!Warn_Fix_Prompter::Prompt_To_Delete_Duplicate_Compact(it)) {return;}}


	//BUG: THIS IS DIFFERENT NOW.  IT WAS CODED FOR EMPTY COMPACTS,  NOT INVALID COMPACTS.  NEEDS TO BE MORE COMPLEX
	//decide whether to actually perform the fix if prompted
	/*
	if (prompt) {if (!Warn_Fix_Prompter::Prompt_To_Delete_Empty_Compact(it)) {return;}}

	//read all the lines of the compact into a vector
	std::vector<std::string> vec;
	std::ifstream infile(it.first);
	std::string str;
	std::getline(infile,str);
	while (infile){
		vec.push_back(str);
		std::getline(infile,str);
   }
	infile.close();

	//spit all the information back into the file,
	//but makes sure the empty lines are not put back in
	std::ofstream outfile(it.first);
	for (auto it2: vec){
	 if (it2 != it.second){
	  outfile << it2 << '\n';
	}
   }*/

	return;
  }
void Warn_Fixer::Remove_Dups_From_Compact(bool const& prompt, std::pair<std::string,std::string> const& it) {

	//decide whether to actually perform the fix if prompted
	if (prompt) {if (!Warn_Fix_Prompter::Prompt_To_Delete_Duplicate_Compact(it)) {return;}}

	//read all the lines of the compact into a vector
	std::vector<std::string> vec;
	std::ifstream infile(it.first);
	std::string str;
	std::getline(infile,str);
	while (infile){
	 vec.push_back(str);
	 std::getline(infile,str);
   }
	infile.close();

	//spit all the information back into the file,
	//but makes sure the duplicate compact in question is only put back in once
	std::ofstream outfile(it.first);
	bool found = false;
	for (auto it2: vec){
	 if (it2 == it.second){
	  if (!found){
	   outfile << it2 << '\n';
	   found = true;
	 }

	}else{
	 outfile << it2 << '\n';
   }
   }

	return;
  }

//mis-cased folder names
void Warn_Fixer::Fix_Miscased_Folder(bool const& prompt, std::pair<std::string,std::string> const& it) {

	//decide whether to actually perform the fix if prompted
	if (prompt) {if (!Warn_Fix_Prompter::Prompt_To_Fix_Folder_Casing(it)) {return;}}

	//remove spaces and capitalize folder
	system(("mv -f " + it.first + it.second + " " + it.first + Make_Capital_And_Underscored_In_User_Type_Format(it.second)).c_str());




	return;
  }





