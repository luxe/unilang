#include "cleaner.hpp"
#include "utilities.hpp"
#include "file_system_traverser.hpp"









 void Cleaner::Clean_Dependencies_Of_Current_Dir(){

    //get all the names of the .sympull files of the current pulls directory
	auto files = Get_Regular_Files_Of_Path(".pulls/");
    
    //replace their file extensions with .pulled to get the directory names
    for (auto & it: files){Replace_File_Extension(it,"pulled");}
        
    //get the names of all of the files in these directories
    std::vector<std::string> all_files;
    for (auto const& it: files){
        all_files += Get_Everything_At_Path(".pulls/" + it + "/");
    }
    
    //delete the symbolic links
    for (auto const& it: all_files){
        execute_quietly("rm -rf " + it);
    }
    
    //delete the .pulled folders
    for (auto const& it: files){
        execute_quietly("rm -rf .pulls/" + it);
    }
    
    
	return;
}
 void Cleaner::Clean_Listed_Dependencies_Of_Dir(std::vector<std::string> symbolic_pull_files){

    //take the passed in .sympull files and derive the .pulled directories
	for (auto & it: symbolic_pull_files){Replace_File_Extension(it,"pulled");}
        
    //get the names of all of the files in these directories
    std::vector<std::string> all_files;
    for (auto const& it: symbolic_pull_files){
        all_files += Get_Everything_At_Path(".pulls/" + it + "/");
    }
    
    //delete the symbolic links
    for (auto const& it: all_files){
        execute_quietly("rm -rf " + it);
    }
    
    //delete the .pulled folders
    for (auto const& it: symbolic_pull_files){
        execute_quietly("rm -rf .pulls/" + it);
    }
    
	return;
}
 void Cleaner::Clean_Dependencies_Recursively(){

    auto current_path = Current_Path();
    
    File_System_Traverser file_system_traverser;
    Clean_Dependencies_Of_Current_Dir();
    while (file_system_traverser.Move_Into_Next_Directory()) {
        Clean_Dependencies_Of_Current_Dir();
    }
    
    Set_Path(current_path);

	return;
}
 void Cleaner::Clean_All_Dependencies(){
    auto current_path = Current_Path();
    
    Go_To_Git_Repo_Root();
    Clean_Dependencies_Recursively();
    
    Set_Path(current_path);

	return;
}
