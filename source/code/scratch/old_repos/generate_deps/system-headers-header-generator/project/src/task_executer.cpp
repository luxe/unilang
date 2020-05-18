#include "task_executer.hpp"













 void Task_Executer::Execute_Needed_Tasks(Program_Options const& input) {

    //not used...
    const std::vector<std::string> FULL_PATHS_TO_SYSTEM_LIBRARIES 
    { "/usr/local/include/c++/4.7.2/"
    ,"/usr/local/include/c++/4.8.2/"
    ,"/usr/include/c++/4.6/"
    };

    std::ofstream outfile("systems.hpp");
    
    //possibly print all of the system libraries (takes into account flag options)
    Possibly_Print_STD_Headers(outfile,input);
    Possibly_Print_Boost_Headers(outfile,input);
    Possibly_Print_QT_Headers(outfile,input);
    Possibly_Print_NCurses_Headers(outfile,input);
    
    //print any additional headers
    Print_All_The_Added_Headers(outfile,input);
}

 void Task_Executer::Possibly_Print_STD_Headers(std::ofstream & outfile,Program_Options const& program_options){
    if (Any_True(program_options.All(),program_options.Std())){
        Print_Headers(outfile,constant::STD_HEADERS,program_options);
    }
}
 void Task_Executer::Possibly_Print_Boost_Headers(std::ofstream & outfile,Program_Options const& program_options){
    if (Any_True(program_options.All(),program_options.Boost())){
        Print_Headers(outfile,constant::BOOST_HEADERS,program_options);
    }
}
 void Task_Executer::Possibly_Print_QT_Headers(std::ofstream & outfile,Program_Options const& program_options){
    if (Any_True(program_options.All(),program_options.Qt())){
        Print_Headers(outfile,constant::QT_HEADERS,program_options);
    }
}
 void Task_Executer::Possibly_Print_NCurses_Headers(std::ofstream & outfile,Program_Options const& program_options){
    if (Any_True(program_options.All(),program_options.Ncurses())){
        Print_Headers(outfile,constant::NCURSES_HEADERS,program_options);
    }
}
 void Task_Executer::Print_Headers(std::ofstream & outfile,Include_Category const& include_category,Program_Options const& program_options){
    outfile << "//" << include_category.Name() << '\n';
    
    //turn multi line string into vector
    std::vector<std::string> removes;
    for (auto const& it: program_options.Removes()){
        removes += Put_Each_Line_Of_String_Into_A_Vector(it);
    }
    
    for (auto const& it: include_category.Lines()){
        if (!String_In_Vector(removes,it)){
            outfile << "#include <" << it << ">\n";
        }else{
            outfile << "//#include <" << it << "> set to be ignored\n";
        }
    }
    outfile << '\n';
}
 void Task_Executer::Print_All_The_Added_Headers(std::ofstream & outfile,Program_Options const& program_options){
    outfile << "//user added\n";
    for (auto const& it: program_options.Adds()){
        outfile << "#include <" << it << ">\n";
    }
    outfile << '\n';
}

 bool Task_Executer::System_Library_Exists(std::string file_name, const std::vector<std::string> system_paths){

	for (auto const& it: system_paths){
		if (File_Exists(it + file_name)){
			return true;
		}
	}

	return false;
}
