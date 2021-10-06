#include "pseudo_library_scanner.hpp"

bool Pseudo_Library_Scanner::Scan(Program_Options const& program_options, Warn_Machine & warn_machine, std::time_t const& last_run_time) {

	//print starting scan message
	Pseudo_Library_Scanner_Printer printer;

		//perform the scan
		if (!Scan_Directories(program_options, warn_machine, printer)) {return false;}

	//scan is complete (an analysis of the pseudo library has been completed)
	printer.Update();

	return true;
}

bool Pseudo_Library_Scanner::Scan_Directories(Program_Options const& program_options, Warn_Machine & warn_machine, Pseudo_Library_Scanner_Printer & printer){

	//update scan message
	printer.Update();

	//scan the root first
	if (!Root_Scanner::Scan(warn_machine))   {return false;}

	//recursively do this across all sub-directories
	if (!Scan_All_The_Sub_Folders(program_options,warn_machine, printer))   {return false;}

	return true;
 }
bool Pseudo_Library_Scanner::Scan_All_The_Sub_Folders(Program_Options const& program_options, Warn_Machine & warn_machine, Pseudo_Library_Scanner_Printer & printer){

	static unsigned int namespace_depth = 1;//<- we start at one, because we are already in the jstd:: namespace

	//get all the directories of the pseudo library node
	auto dirs = Get_Dirs_Of_Path(boost::filesystem::current_path().string());


	for (auto const& dir: dirs){
	 Step_Into_Folder(dir);
	 ++namespace_depth;

	 if (!Scan_Directory_And_All_Sub_Directories(program_options,warn_machine, printer))   {return false;}

	 Step_Out_Of_Folder();
	 --namespace_depth;
   }

	//we've reached a leaf node namespace, record it if it's the deepest we've found thus far.
	//if (dirs.empty()){
		//stats.Store_If_Max_Depth(namespace_depth);
	//}

	return true;
  }
bool Pseudo_Library_Scanner::Scan_Directory_And_All_Sub_Directories(Program_Options const& program_options, Warn_Machine & warn_machine, Pseudo_Library_Scanner_Printer & printer){

	//update scan message
	printer.Update();

	//scan the subdirectory
	if (!Subfolder_Scanner::Scan(warn_machine))   {return false;}
	if (!Scan_All_The_Sub_Folders(program_options, warn_machine, printer))   {return false;}

	return true;
 }

