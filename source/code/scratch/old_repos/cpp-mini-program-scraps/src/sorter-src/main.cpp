// STD LIBS
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <thread>
#include <stack>
#include <algorithm>
#include "utilities.hpp"

void Decrement_Number_In_File(std::string const& file_name){
	mpz_class number(Get_Whole_File_As_String(file_name));
	number -= mpf_class("1");
	std::ofstream outfile(file_name);
	outfile << number;
}

namespace constant{
	const std::string STAGED_DIRECTORY = "Downloaded/Staged/";
	const std::string NOT_INTERESTING_DIRECTORY = "Downloaded/Deleted/not_interesting/";
	const std::string SAVED_DIRECTORY = "Downloaded/Saved/";
}



//space: "keep the file and go to the next"
//space: "if file is already kept, the program will set it to be unsaved"
//left & right: cycle through the files, if I skip over one by not hitting space, then I don't want it/
//I might change my mind, go back a few using the left key, and then hit space to save it


//new types
struct File{
	File(std::string const& location_in, std::string const& name_in)
	: location(location_in)
	, name(name_in)
	{}
	std::string location;
	std::string name;
	
	bool operator < (File const& f) const{
		return (name < f.name);
	}
};

enum class Choice: char{
	LEFT,
	RIGHT,
	MOVE,
	INVALID,
};

//function decelerations
std::vector<File> Get_Files_Of_Path_As_Vector_Of_Files(std::string const& path);
void Process_A_File(std::vector<File> & looked_at, std::vector<File> & not_looked_at);
std::string Show_File_And_Get_The_Process_Id(File const& file);
void Kill_Process(std::string const& pid);
Choice Get_Choice(File const& file);
void Perform_Choice(std::vector<File> & looked_at, std::vector<File> & not_looked_at, Choice const& choice);
void Move_File(File & file, Choice const& choice);

int main() {
	
	system ("touch \"if-this-file-is-here-not-interesting-files-WILL-NOT-be-rm\"");
	std::vector<File> not_looked_at = Get_Files_Of_Path_As_Vector_Of_Files(constant::STAGED_DIRECTORY);
	std::vector<File> looked_at;
	std::sort(not_looked_at.begin(),not_looked_at.end());
	
	while(true){
		Process_A_File(looked_at,not_looked_at);
	}
	
	

	return EXIT_SUCCESS;
}

std::vector<File> Get_Files_Of_Path_As_Vector_Of_Files(std::string const& path){
	std::vector<File> dirs;
	std::string list2 = exec("find " + path + " -maxdepth 1 -type f 2>/dev/null;");

	std::string temp;
	for (auto it: list2){
		if (it == '/'){
			temp.clear();
		}else if (it == '\n'){
			dirs.push_back(File(path,temp));
			temp.clear();
		}else{
		temp+=it;
		}
	}
	if (!temp.empty()){
		dirs.push_back(File(path,temp));
	}

	return dirs;
}
void Process_A_File(std::vector<File> & looked_at, std::vector<File> & not_looked_at){
	
	std::string pid = Show_File_And_Get_The_Process_Id(not_looked_at.back());
	system("wmctrl -a \"Terminal\"");
	auto choice = Get_Choice(not_looked_at.back());
	Kill_Process(pid);
	Perform_Choice(looked_at,not_looked_at,choice);
	
	while(!not_looked_at.empty()){
		pid = Show_File_And_Get_The_Process_Id(not_looked_at.back());
		system("wmctrl -a \"Terminal\"");
		choice = Get_Choice(not_looked_at.back());
		Kill_Process(pid);
		Perform_Choice(looked_at,not_looked_at,choice);
	}
	
	return;
}
std::string Show_File_And_Get_The_Process_Id(File const& file){
	return exec(("kate -n --geometry 1600x800+0+143 " + file.location + file.name + " >> /dev/null 2>&1 & echo $!").c_str());
}
void Kill_Process(std::string const& pid){
	system(("kill -9 " + pid).c_str());
	return;
}
Choice Get_Choice(File const& file){
	auto choice = Choice::INVALID;
	char c;
	
	std::string str = "yad  --text--info --geometry 1300x0+0+0 --button=\"BACK:1\" --button=\"SAVE:2\" --button=\"TOSS:3\" --title=\"code look\"";
	str+= " --text=\"" + file.location + " ";
	

	//get the number of kept
	std::ifstream infile("stats/kept");
	std::string temp;
	std::getline(infile,temp);
	mpz_class num1(temp);
	infile.close();

	//get the number of not-kept
	infile.open("stats/deleted_not_interesting");
	std::getline(infile,temp);
	mpz_class num2(temp);
	infile.close();
	
	str += mpz_class(num1+num2).get_str();
	
	
	
	str+= "\"";
	int huh = system(str.c_str());
	std::cout << "[[" << huh << "]]" << std::endl;
	switch (huh){
		case 256: choice = Choice::LEFT; break;
		case 512: choice = Choice::MOVE; break;
		case 768: choice = Choice::RIGHT; break;
		case 64512: 
			system ("rm \"if-this-file-is-here-not-interesting-files-WILL-NOT-be-rm\"");
			exit(EXIT_SUCCESS);
	}
	
	return choice;
}
void Perform_Choice(std::vector<File> & looked_at, std::vector<File> & not_looked_at, Choice const& choice){
	
	switch(choice){
		case Choice::LEFT:
			not_looked_at.push_back(looked_at.back());
			looked_at.pop_back();
		break;
		case Choice::RIGHT:
			looked_at.push_back(not_looked_at.back());
			not_looked_at.pop_back();
			Move_File(looked_at.back(), choice);
		break;
		case Choice::MOVE:
			looked_at.push_back(not_looked_at.back());
			not_looked_at.pop_back();
			Move_File(looked_at.back(), choice);
		break;
		
	}
	
	
	return;
}

void Move_File(File & file, Choice const& choice){
	
	switch(choice){
		case Choice::RIGHT:
			if(file.location == constant::STAGED_DIRECTORY){
				file.location = constant::NOT_INTERESTING_DIRECTORY;
				system(("mv " + constant::STAGED_DIRECTORY + file.name + " " + file.location + file.name).c_str());
			}
			else if(file.location == constant::SAVED_DIRECTORY){
				file.location = constant::NOT_INTERESTING_DIRECTORY;
				system(("mv " + constant::SAVED_DIRECTORY + file.name + " " + file.location + file.name).c_str());
				Decrement_Number_In_File("stats/kept");
			}
			
			
		break;
		
		case Choice::MOVE:
			if(file.location == constant::STAGED_DIRECTORY){
				file.location = constant::SAVED_DIRECTORY;
				system(("mv " + constant::STAGED_DIRECTORY + file.name + " " + file.location + file.name).c_str());
				Increment_Number_In_File("stats/kept");
			}
			else if(file.location == constant::NOT_INTERESTING_DIRECTORY){
				file.location = constant::SAVED_DIRECTORY;
				system(("mv " + constant::NOT_INTERESTING_DIRECTORY + file.name + " " + file.location + file.name).c_str());
				Increment_Number_In_File("stats/kept");
			}
			
			
		break;
	}
		
	return;
}


