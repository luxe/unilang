#include "task_executer.hpp"
#include "class_compiler.hpp"
#include "class_optimizer.hpp"
#include "class_structure_creator.hpp"
#include "class_structure.hpp"
#include "global_compiler.hpp"
#include "global_optimizer.hpp"
#include "global_structure_creator.hpp"
#include "global_structure.hpp"





















//A NOTE ON THE COMPILER/OPTIMIZER BEING USED:
//if no flags are passed we compile
//otherwise we do the optimizer which indirectly calls the compiler
//(the optimizer takes a lot longer and relies on a build system)


 void Task_Executer::Execute_Tasks_On_File(Program_Options const& program_options, std::string const& hcp_file){

    //get the file-type first
    std::wstring file_type;
    std::wifstream infile(hcp_file);
    std::getline(infile,file_type);
    
    //decide what kind of file to process based on the file-type
    if (file_type == L"class"){Perform_Task_On_Class_File(program_options,hcp_file,infile,file_type);}
    else if (file_type == L"global"){ Perform_Task_On_Global_File(program_options,hcp_file,infile,file_type);}
    else{ Exit_With_Error(hcp_file + ": invalid file type given on first line");}
    
    return;
}



//handle class files
 void Task_Executer::Perform_Task_On_Class_File(Program_Options const& program_options, std::string const& hcp_file,std::wifstream & infile, std::wstring const& file_type){

    Class_Structure_Creator creator(hcp_file);
    auto structure = creator.Create(infile,file_type);
    
    if (!program_options.Optimize()){ Class_Compiler::Compile_HCP_File(structure,hcp_file);
    }else{ Class_Optimizer::Optimize_HCP_File(structure,hcp_file);}
}

//handle global files
 void Task_Executer::Perform_Task_On_Global_File(Program_Options const& program_options, std::string const& hcp_file,std::wifstream & infile, std::wstring const& file_type){

    Global_Structure_Creator creator(hcp_file);
    auto structure = creator.Create(infile,file_type);
    
    if (!program_options.Optimize()){ Global_Compiler::Compile_HCP_File(structure,hcp_file);
    }else{ Global_Optimizer::Optimize_HCP_File(structure,hcp_file);}
}
