#include "scanner.hpp"
#include "scan_stats.hpp"
#include "utilities.hpp"
#include "global.hpp"

#include <fstream>

void Scanner::Scan(Program_Options const& program_options){
	Perform_Timed_Scan(program_options);
	return;
}
void Scanner::Perform_Timed_Scan(Program_Options const& program_options){
	
	std::cout << "Scanning... "; std::cout.flush();
	
	//start recording the time it takes to perform the scan
	Scan_Stats stats; stats.Start_Timer();
	
		//perform the scan
		Perform_Scan(program_options,stats);
	
	//scan is done. stop the timer
	stats.End_Timer();
	
	//scan is complete (an analysis of the pseudo library has been completed)
	Green_Message("Success!\n");
	
	return;
}
	void Scanner::Perform_Scan(Program_Options const& program_options, Scan_Stats & stats){
		
	//assuming the program is being run at the root of the pseudo library,
	//this function will scan the pseudo library for any problems.
	Start_The_Library_Scan(program_options,stats);
		
	return;
}
		void Scanner::Start_The_Library_Scan(Program_Options const& program_options, Scan_Stats & stats){
	
	Warn_Machine warn_machine(program_options.Warn_Amount());
	
	//do the root check first
	Make_Sure_The_Necessary_Files_Are_Present_At_Root(program_options,warn_machine,stats);
	Make_Sure_No_Extra_Files_Exist_At_Root(program_options,warn_machine,stats);
	Check_Header_Files(program_options,warn_machine,stats);
	Check_Code_File(program_options,warn_machine,stats);
	
	//recursively do this across all sub-directories
	Scan_All_The_Sub_Files(program_options,warn_machine,stats);
		
	return;
}
			void Scanner::Make_Sure_The_Necessary_Files_Are_Present_At_Root(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats){
				
			for (auto const& file: constant::NEEDED_FILES_FOR_PSEUDO_ROOT_DIRECTORY){
				if (!File_Exists(file)){
					stats.Record_Missing_File(boost::filesystem::current_path().string() + "/" + file);
					warn_machine.Warn(boost::filesystem::current_path().string() + "/" + file + " is missing!\n");
				}
			}
			
			return;
		}
			void Scanner::Make_Sure_No_Extra_Files_Exist_At_Root(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats){
	
	auto files = Get_Files_Of_Path(boost::filesystem::current_path().string());
	for (auto const& file: files){
		if (!String_In_Vector(constant::NEEDED_FILES_FOR_PSEUDO_ROOT_DIRECTORY, file)){
			stats.Record_Not_Needed_File(boost::filesystem::current_path().string() + "/" + file);
			warn_machine.Warn(boost::filesystem::current_path().string() + "/" + file + " should not exist!\n");
		}
	}
	return;
}
			void Scanner::Scan_Directory_And_All_Sub_Directories(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats){
	
	Make_Sure_The_Necessary_Files_Are_Present_In_Subfolder(program_options,warn_machine,stats);
	Make_Sure_No_Extra_Files_Exist_In_Subfolder(program_options,warn_machine,stats);
	Check_Header_Files(program_options,warn_machine,stats);
	Check_Code_File(program_options,warn_machine,stats);
	
	//recursively do this across all sub-directories
	Scan_All_The_Sub_Files(program_options,warn_machine,stats);
		
	return;
}
				void Scanner::Make_Sure_The_Necessary_Files_Are_Present_In_Subfolder(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats){
		
	for (auto const& file: constant::NEEDED_FILES_FOR_EACH_PSEUDO_SUB_DIRECTORY){
		if (!File_Exists(file)){
			stats.Record_Missing_File(boost::filesystem::current_path().string() + "/" + file);
			warn_machine.Warn(boost::filesystem::current_path().string() + "/" + file + " is missing!\n");
		}
	}
	
	return;
}
				void Scanner::Make_Sure_No_Extra_Files_Exist_In_Subfolder(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats){
	
	auto files = Get_Files_Of_Path(boost::filesystem::current_path().string());
	for (auto const& file: files){
		if (!String_In_Vector(constant::NEEDED_FILES_FOR_EACH_PSEUDO_SUB_DIRECTORY, file)){
			stats.Record_Not_Needed_File(boost::filesystem::current_path().string() + "/" + file);
			warn_machine.Warn(boost::filesystem::current_path().string() + "/" + file + " should not exist!\n");
		}
	}
	return;
}
				void Scanner::Check_Header_Files(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats){
	
	
	
	std::ifstream source(boost::filesystem::current_path().string() + "/" + constant::HEADER_HPPS_FILE);
	std::ifstream header(boost::filesystem::current_path().string() + "/" + constant::SOURCE_HPPS_FILE);
	
	std::string line;
	std::vector<std::string> header_lines;
	std::vector<std::string> source_lines;
	
	//checker the header_hpps file for errors if it exists
	if (File_Exists(boost::filesystem::current_path().string() + "/" + constant::HEADER_HPPS_FILE)){
		std::getline(header,line);
		while (header){
			header_lines.push_back(line);
			std::getline(header,line);
		}
		header.close();
		Complain_About_Header_Duplicates(program_options, warn_machine, stats, header_lines,boost::filesystem::current_path().string() + "/" + constant::HEADER_HPPS_FILE);
	}
	
	//checker the source_hpps file for errors if it exists
	if (File_Exists(boost::filesystem::current_path().string() + "/" + constant::SOURCE_HPPS_FILE)){
		std::getline(source,line);
		while (source){
			source_lines.push_back(line);
			std::getline(source,line);
		}
		source.close();
		Complain_About_Source_Duplicates(program_options, warn_machine, stats, header_lines,source_lines,boost::filesystem::current_path().string() + "/" + constant::SOURCE_HPPS_FILE);
	}
	
	
	return;
}
					void Scanner::Complain_About_Header_Duplicates(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats, std::vector<std::string> const& header_lines,std::string const& file_name){
	
	std::vector<std::string> duplicates;
	bool found_duplicate = false;
	
	for (auto it = header_lines.begin(); it != header_lines.end(); ++it){
		for (auto it2 = header_lines.begin(); it2 != header_lines.end() && !found_duplicate; ++it2){
			if (it != it2){
				if (*it == *it2){
					duplicates.push_back(*it);
					found_duplicate = true;
				}
			}
		}
		found_duplicate = false;
	}
	
	Sort_And_Remove_Duplicates(duplicates);
	
	for (auto const& it: duplicates){
		stats.Record_Duplicate_Header(file_name,it);
		warn_machine.Warn(file_name + " contains the header " + it + " multiple times\n");
	}
	
	return;
}
					void Scanner::Complain_About_Source_Duplicates(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats, std::vector<std::string> const& header_lines, std::vector<std::string> const& source_lines,std::string const& file_name){
	
	std::vector<std::string> duplicates;
	bool found_duplicate = false;
	
	for (auto it = source_lines.begin(); it != source_lines.end(); ++it){
		for (auto it2 = source_lines.begin(); it2 != source_lines.end() && !found_duplicate; ++it2){
			if (it != it2){
				if (*it == *it2){
					duplicates.push_back(*it);
					found_duplicate = true;
				}
			}
		}
		found_duplicate = false;
	}
	
	Sort_And_Remove_Duplicates(duplicates);
	
	for (auto const& it: duplicates){
		stats.Record_Duplicate_Header(file_name,it);
		warn_machine.Warn(file_name + " contains the header " + it + " multiple times\n");
	}
	
	//CHECK TO SEE IF A SOURCE HEADER ALREADY EXISTS IN THE HEADER HEADERS
	for (auto i: source_lines){
		for (auto j: header_lines){
			if (i == j){
				stats.Record_Uneeded_Header(file_name,i);
				warn_machine.Warn(file_name + " contains the header " + i + " which already exists in the headers_hpp file\n");
			}
		}
	}
	
	
	return;
}
				void Scanner::Check_Code_File(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats){
	//I have nothing in particular to check right now, but it should try to
	//read in all of the code information,  to make sure that it's valid.
	//yes,  the actual exporting does this as well,  but we should not expect the exporter
	//to be responsible for validating the pseudo library
	return;
}
				void Scanner::Scan_All_The_Sub_Files(Program_Options const& program_options, Warn_Machine & warn_machine, Scan_Stats & stats){
	
	static unsigned int namespace_depth = 1;//<- we start at one, because we are already in the jstd:: namespace
	
	//get all the directories of the pseudo library node
	auto dirs = Get_Dirs_Of_Path(boost::filesystem::current_path().string());
	
	
	for (auto const& dir: dirs){
		Step_Into_Folder(dir);
		++namespace_depth;
		
		Scan_Directory_And_All_Sub_Directories(program_options,warn_machine,stats);
		
		Step_Out_Of_Folder();
		--namespace_depth;
	}
	
	//we've reached a leaf node namespace, record it if it's the deepest we've found thus far.
	if (dirs.empty()){
		stats.Store_If_Max_Depth(namespace_depth);
	}
	
	return;
}


