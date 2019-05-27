#include "code/utilities/filesystem/files/deleting/lib.hpp"
#include "code/utilities/filesystem/files/getting/lib.hpp"
#include "code/utilities/types/vectors/transformers/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/shell/lib.hpp"
#include <iostream>

void Delete_Files_That_Exist_In_Second_Dir_But_Not_In_First(std::string const& based_on, std::string const& delete_from){

    //get directory trees
    auto based_on_files = Recursively_Get_All_Paths_To_Files_From_Path(based_on);
    auto delete_from_files = Recursively_Get_All_Paths_To_Files_From_Path(delete_from);

    //first element is the name of the directories.  don't want that
    Remove_First_Element(delete_from_files);
    Remove_First_Element(based_on_files);

    //trim off the base directory names
    for (auto & it: delete_from_files){
    	Remove_First_N_Chars(it,delete_from.size()+1);
    }

    for (auto & it: based_on_files){
    	Remove_First_N_Chars(it,based_on.size()+1);
    }

    //sort them
    std::sort(delete_from_files.begin(),delete_from_files.end());
    std::sort(based_on_files.begin(),based_on_files.end());

    //get the files that exist in one directory, but not the other
    std::vector<std::string> differences;
    std::set_difference(
    delete_from_files.begin(),
    delete_from_files.end(),
    based_on_files.begin(),
    based_on_files.end(),
    std::back_inserter(differences));

    for (auto const& it: differences){
    		std::string command = std::string("rm -rf ") + delete_from + "/" + it;
    		//std::cout << command << std::endl;
    		execute_quietly(command);
    }

}
void Delete_Files_That_Exist_In_Second_Dir_But_Not_In_First_Based_On_Basename(std::string const& based_on, std::string const& delete_from){
    
    //get directory trees
    auto based_on_files = Recursively_Get_All_Paths_To_Files_From_Path(based_on);
    auto delete_from_files = Recursively_Get_All_Paths_To_Files_From_Path(delete_from);

    //first element is the name of the directories.  don't want that
    Remove_First_Element(delete_from_files);
    Remove_First_Element(based_on_files);

    //trim off the base directory names
    for (auto & it: delete_from_files){
        Remove_First_N_Chars(it,delete_from.size()+1);
    }

    for (auto & it: based_on_files){
        Remove_First_N_Chars(it,based_on.size()+1);
    }

    //sort them
    std::sort(delete_from_files.begin(),delete_from_files.end());
    std::sort(based_on_files.begin(),based_on_files.end());

    //get the files that exist in one directory, but not the other
    std::vector<std::string> differences;
    std::set_difference(
    delete_from_files.begin(),
    delete_from_files.end(),
    based_on_files.begin(),
    based_on_files.end(),
    std::back_inserter(differences));

    for (auto const& it: differences){
            std::string file_to_delete = delete_from + "/" + it;
            if (!Recursive_Path_Contains_File_With_Same_Basename_As_File(it,based_on)){
                std::string command = std::string("rm -rf ") + file_to_delete;
                execute_quietly(command);
            }
            else
            {
                //std::cout << "skipped: " << it << std::endl;
            }
    }
}

void Empty_Out_Folder_But_Keep_Folder(std::string path){
    
    
    if (path[path.length()-1] != '/'){
        path += "/";
    }
    
    std::string command = std::string("rm -rf ") + path + "*";
    execute_quietly(command);
}

void Delete_File(std::string const& file){
    
    std::string command = std::string("rm -f ") + file;
    execute_quietly(command);
}