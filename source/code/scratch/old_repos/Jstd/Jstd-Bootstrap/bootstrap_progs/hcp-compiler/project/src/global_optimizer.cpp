#include "global_optimizer.hpp"
#include "class_compiler.hpp"
#include "utilities.hpp"









//use the optimizer to print the new version of the hcp file
//also has to call make to make sure the changes are valid, so it also compiles the hcp as well as the c++ to create a .o
 void Global_Optimizer::Optimize_HCP_File(Class_Structure structure, std::string const& hcp_file){
    
    //make sure that it already compiles before we try to optimize it
    Initial_Test(structure,hcp_file);
    
    //sort remove the duplicate headers in a .hpp and .cpp portion
    Sort_And_Remove_Duplicates_Test(structure,hcp_file);
    
    //take anything that exists in both the header and source, and delete it from the source
    //(we do this because the source gets everything from the header anyway)
    Remove_Sources_Based_On_Headers_Test(structure,hcp_file);
    
    //move everything in the headers that can be moved successfully to the source
    Move_As_Many_Includes_From_Header_To_Source_Test(structure,hcp_file);
    
    //try raw deletes on header on the header and source
    std::wcout << "trying raw deletes on headers..." << std::endl;
    Try_Raw_Deletes(structure.header_includes,structure,hcp_file);
    std::wcout << "trying raw deletes on sources..." << std::endl;
    Try_Raw_Deletes(structure.source_includes,structure,hcp_file);
    
    //final sort
    std::wcout << "final sort and remove test..." << std::endl;
    Sort_And_Remove_Duplicates_Test(structure,hcp_file);
    
    //we have finished optimizing the header and source portions; time to re-print the hcp file
    Reprint_Hcp_File(structure,hcp_file);
}

 void Global_Optimizer::Initial_Test(Class_Structure const& structure, std::string const& hcp_file){
    std::wcout << "initial valid c++ test..." << std::endl;
    if (!Compiles(structure,hcp_file)){
        std::wcerr << hcp_file << ": can't optimize because the c++ code generated, doesn't initially compile." << std::endl;
        exit(EXIT_FAILURE);
    }
}
 void Global_Optimizer::Sort_And_Remove_Duplicates_Test(Class_Structure & structure, std::string const& hcp_file){
    std::wcout << "sorting an removing duplicates..." << std::endl;
    Sort_And_Remove_Duplicates(structure.header_includes);
    Sort_And_Remove_Duplicates(structure.source_includes);
    if (!Compiles(structure,hcp_file)){
        std::wcerr << hcp_file << ": sorting headers and removing duplicates has caused the c++ generated code to not compile.  This should not happen." << std::endl;
        exit(EXIT_FAILURE);
    }
}
 void Global_Optimizer::Remove_Sources_Based_On_Headers_Test(Class_Structure & structure, std::string const& hcp_file){
    std::wcout << "removing source items that are already in header..." << std::endl;
    // std::wcout << structure.header_includes << std::endl;
    // std::wcout << structure.source_includes << std::endl;
    Remove_Elements_Of_Vector_One_Found_In_Vector_Two(structure.source_includes,structure.header_includes);
    // std::wcout << "-----------------" << std::endl;
    // std::wcout << structure.header_includes << std::endl;
    // std::wcout << structure.source_includes << std::endl;
    
    if (!Compiles(structure,hcp_file)){
        std::wcerr << hcp_file << ": removing headers in the source that already exist in the header, some how caused a problem."
        << "[did not think this was possible]" << std::endl;
        exit(EXIT_FAILURE);
    }
}
 void Global_Optimizer::Move_As_Many_Includes_From_Header_To_Source_Test(Class_Structure & structure, std::string const& hcp_file){
    std::wcout << "trying to move from headers to source..." << std::endl;
    for (auto & it: structure.header_includes){
        std::wcout << structure.header_includes << std::endl;
        if (it.second){
            //move from header to source
            structure.source_includes.push_back(it);
            it.second = false;
            
            //revert if failed
            if (!Compiles(structure,hcp_file)){
                structure.source_includes.pop_back();
                it.second = true;
            }
        }
    }
    
    if (!Compiles(structure,hcp_file)){
        std::wcerr << hcp_file << ": moving all possible headers to source has caused the c++ generated code to not compile.  This should not happen." << std::endl;
        exit(EXIT_FAILURE);
    }
}
 void Global_Optimizer::Try_Raw_Deletes(std::vector<std::pair<std::wstring,bool>> & includes, Class_Structure & structure, std::string const& hcp_file){
    
    for (auto & it: includes){
        std::wcout << includes << std::endl;
        if (it.second){
            //delete header
            it.second = false;
            
            //revert if failed
            if (!Compiles(structure,hcp_file)){
                it.second = true;
            }
        }
    }
    
    if (!Compiles(structure,hcp_file)){
        std::wcerr << hcp_file << ": deleting unneeded headers caused the c++ generated code to not compile.  This should not happen." << std::endl;
        exit(EXIT_FAILURE);
    }
}
 void Global_Optimizer::Reprint_Hcp_File(Class_Structure const& structure, std::string const& hcp_file){
    
    std::wofstream outfile(hcp_file);
    
    //dealing with unicode in c++ is a disaster
    //outputting a wstring just doesn't work; but if you iterate over each element and flush it does.. sigh...
    //this should be asked about on stackoverflow
    std::wstring wstr;
    for (auto const& it: structure.file_type){
        wstr += it;
    }
    
    for (auto const& it: structure.header_includes){
        if (it.second){
            wstr+= L"❪";
            wstr += it.first;
            wstr+= L"❫";
            wstr += L"\n";
        }
    }
    
    //output the header headers (notice the needed flush)
    for (auto const& it: wstr){outfile << it; outfile.flush();}
        
    wstr = L"⚯";
    wstr += L"\n";
    for (auto const& it: wstr){
        outfile << it;
    }
        
        
    //build the string for source headers
    wstr.clear();
    for (auto const& it: structure.source_includes){
        if (it.second){
            wstr+= L"❪";
            wstr += it.first;
            wstr+= L"❫";
            wstr += L"\n";
        }
    }

    //output the source headers (notice the needed flush)
    for (auto const& it: wstr){outfile << it; outfile.flush();}
        
    for (auto it: structure.everything_after_headers){
        outfile << it; outfile.flush();
    }
}

 bool Global_Optimizer::Compiles(Class_Structure const& structure, std::string hcp_file){

    Sleep_For_N_Seconds(1);
    Class_Compiler::Compile_HCP_File(structure,hcp_file);
    Sleep_For_N_Seconds(1); //wait for the timestamp to be older than the current time
    return !Silence_Output_And_Get_Return_Value_Of_Running("make " + Replace_File_Extension(hcp_file,"o"));
}





