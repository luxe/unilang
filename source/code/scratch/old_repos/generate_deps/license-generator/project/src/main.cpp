#include <locale>
#include "program_options_creator.hpp"
#include "utilities.hpp"

//this is where we expect git-it to place the repo
const std::string LICENSE_DIRECTORY = exec("echo $HOME") + "/.github/generative-dependencies/license-generator/project/src/license_data/";

int main(int const argc, char** const argv) {

	//Unicode please
	std::locale::global(std::locale("en_US.UTF-8"));

	//get program options from command line
	auto program_options = Program_Options_Creator::Create(argc, argv);
    
    //get the available licenses
    auto license_names = Get_Regular_Files_Of_Path(LICENSE_DIRECTORY);
    
    //make sure a valid license has been passed
    if (!String_In_Vector(license_names,As_Lowercase(program_options.License()))){
        std::cerr << "You did not pass a valid license name.  Your following options are:\n";
        std::cerr << Get_As_String_With_Element_On_Each_Line(license_names);
        exit(EXIT_FAILURE);
    }
    
    //get the chosen license
    auto license_str = Read_Entire_File_Into_String(LICENSE_DIRECTORY + As_Lowercase(program_options.License()));
    
    //get the year
    std::string year;
    if (program_options.Year() == ""){
        year = std::to_string(Current_Year());
    }
    
    //fill out the license
    auto license_filled_out = string_replace_all(license_str,"[year]",year);
    license_filled_out = string_replace_all(license_filled_out,"[fullname]",program_options.Name());
    
    //create the license
    std::ofstream out("LICENSE.md");
    out << license_filled_out << std::endl;

	return EXIT_SUCCESS;
}
