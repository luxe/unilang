//should probably pull more from
// https://github.com/github/gitignore/blob/master/Global/Windows.gitignore


#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "global.hpp"
#include "program_options_creator.hpp"


void Build_Groupings(Program_Options const& program_options);
void Go_Through_All_Categories_And_Add_Them_To_Gitignore_File(Program_Options const& program_options);
void Print_Vector(std::ofstream & outfile, Ignore_Category const& ignore_category);


// utility
bool All_Are_False(std::vector<bool> const& vec);
bool Any_Are_True(std::vector<bool> const& vec);

#include "generated_grouping_names.hpp"

int main(int const argc, char** const argv) {

	auto program_options = Program_Options_Creator::Create(argc,argv);

	Build_Groupings(program_options);
	Go_Through_All_Categories_And_Add_Them_To_Gitignore_File(program_options);

	return EXIT_SUCCESS;
}

void Build_Groupings(Program_Options const& program_options) {

	//NOTE: could be generated
	NO_OBJECT_FILES = {program_options.No_Object_Files(), program_options.No_Compiled_Libraries(), program_options.No_Binaries()};
	YES_OBJECT_FILES = {program_options.All(), program_options.Object_Files(), program_options.Compiled_Libraries(), program_options.Binaries()};

	NO_DYNAMIC_LIBRARIES = {program_options.No_Dynamic_Libraries(), program_options.No_Compiled_Libraries(), program_options.No_Binaries()};
	YES_DYNAMIC_LIBRARIES = {program_options.All(), program_options.Dynamic_Libraries(), program_options.Compiled_Libraries(), program_options.Binaries()};

	NO_STATIC_LIBRARIES = {program_options.No_Static_Libraries(), program_options.No_Compiled_Libraries(), program_options.No_Binaries()};
	YES_STATIC_LIBRARIES = {program_options.All(), program_options.Static_Libraries(), program_options.Compiled_Libraries(), program_options.Binaries()};

	NO_EXECUTABLES = {program_options.No_Executables(), program_options.No_Binaries()};
	YES_EXECUTABLES = {program_options.All(), program_options.Executables(), program_options.Binaries()};

	NO_BACKUPS = {program_options.No_Backups()};
	YES_BACKUPS = {program_options.All(), program_options.Backups()};

	NO_DEPENDENCIES = {program_options.No_Dependencies()};
	YES_DEPENDENCIES = {program_options.All(), program_options.Dependencies()};

	NO_WINDOWS_GENERATED = {program_options.No_Windows_Generated(), program_options.No_OS_Generated()};
	YES_WINDOWS_GENERATED = {program_options.All(), program_options.Windows_Generated(), program_options.OS_Generated()};

	NO_MAC_GENERATED = {program_options.No_Mac_Generated(), program_options.No_OS_Generated()};
	YES_MAC_GENERATED = {program_options.All(), program_options.Mac_Generated(), program_options.OS_Generated()};

	NO_LINUX_GENERATED = {program_options.No_Linux_Generated(), program_options.No_OS_Generated()};
	YES_LINUX_GENERATED = {program_options.All(), program_options.Linux_Generated(), program_options.OS_Generated()};

	NO_ARCHIVED = {program_options.No_Archived()};
	YES_ARCHIVED = {program_options.All(), program_options.Archived()};

	NO_DATABASE = {program_options.No_Database()};
	YES_DATABASE = {program_options.All(), program_options.Database()};

	NO_NOTEPADPLUSPLUS = {program_options.No_Notepad_Plus_Plus(), program_options.No_Editor()};
	YES_NOTEPADPLUSPLUS = {program_options.All(), program_options.Notepad_Plus_Plus(), program_options.Editor()};

	NO_VIM = {program_options.No_Vim(), program_options.No_Editor()};
	YES_VIM = {program_options.All(), program_options.Vim(), program_options.Editor()};

	NO_EMACS = {program_options.No_Emacs(), program_options.No_Editor()};
	YES_EMACS = {program_options.All(), program_options.Emacs(), program_options.Editor()};

	NO_KATE = {program_options.No_Kate(), program_options.No_Editor()};
	YES_KATE = {program_options.All(), program_options.Kate(), program_options.Editor()};

	NO_SUBLIME = {program_options.No_Sublime(), program_options.No_Editor()};
	YES_SUBLIME = {program_options.All(), program_options.Sublime(), program_options.Editor()};

    NO_AUTO_TOOLS = {program_options.No_Auto_Tools(), program_options.No_Build_System()};
	YES_AUTO_TOOLS = {program_options.All(), program_options.Auto_Tools(), program_options.Build_System()};

	NO_SCONS = {program_options.No_SCons(), program_options.No_Build_System()};
	YES_SCONS = {program_options.All(), program_options.SCons(), program_options.Build_System()};

	NO_CMAKE = {program_options.No_CMake(), program_options.No_Build_System()};
	YES_CMAKE = {program_options.All(), program_options.CMake(), program_options.Build_System()};

	NO_QT = {program_options.No_Qt(), program_options.No_Build_System()};
	YES_QT = {program_options.All(), program_options.Qt(), program_options.Build_System()};
	#include "generated_groupings.hpp"

	return;
}
void Go_Through_All_Categories_And_Add_Them_To_Gitignore_File(Program_Options const& program_options){

	std::ofstream outfile(constant::IGNORE_FILE);
	#include "generated_calls.hpp"

	//add the additional ignore statements
	//auto more_ignore_statements = Put_Each_Line_Of_String_Into_A_Vector(program_options.Additional());
	//for (auto const& it: more_ignore_statements)
	outfile << program_options.Additional();

	return;
}

void Print_Vector(std::ofstream & outfile, Ignore_Category const& ignore_category) {

	outfile << "# "<< ignore_category.Name() <<  "\n";
	for (auto const it: ignore_category.Lines()) {
		outfile << it << "\n";
	}
	outfile <<  "\n";
}

bool All_Are_False(std::vector<bool> const& vec) {

	if (vec.empty()) {return false;}
	for (auto const& it: vec) {
		if (it == true) {
			return false;
		}
	}
	return true;
}
bool Any_Are_True(std::vector<bool> const& vec) {

	return !All_Are_False(vec);
}
