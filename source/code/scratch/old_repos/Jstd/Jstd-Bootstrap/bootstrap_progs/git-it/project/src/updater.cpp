#include "updater.hpp"
#include "utilities.hpp"
#include "file_system_traverser.hpp"
#include "dependency_getter.hpp"
#include "symbolic_puller.hpp"
#include "cleaner.hpp"












 void Updater::Update_Symbolic_Pull_Ins_For_Current_Directory(){
    Cleaner::Clean_Dependencies_Of_Current_Dir();
    
    std::vector<std::string> v {Full_Path()};
    Dependency_Getter::Perform_Pulls(v,0,0,0);
}

 void Updater::Update_Specific_Symbolic_Pull_Ins(std::vector<std::string> const& symbolic_pull_files){
    Cleaner::Clean_Listed_Dependencies_Of_Dir(symbolic_pull_files);
    
    auto current_path = Current_Path();
    
    int percent_current = 0;
    int percent_total = symbolic_pull_files.size();
    
    if (symbolic_pull_files.size() > 0){
        Output_And_Flush("\nGenerating content from " + std::to_string(percent_total) + " Dependencies:\n");
    }else{
        Output_And_Flush("\nNo Dependencies.\n");
    }
    
    Set_Path(".pulls");
    for (size_t i = 0; i < symbolic_pull_files.size(); ++i) {
        ++percent_current;
        Symbolic_Puller::Pull_File(symbolic_pull_files[i],0,percent_current,percent_total);
    }
    
    Set_Path(current_path);
}

 void Updater::Update_Symbolic_Pull_Ins_Recursively(){
    
    Cleaner::Clean_Dependencies_Recursively();
    Dependency_Getter::Get_Dependencies(0,0,0);
}

 void Updater::Update_Symbolic_Pull_Ins_For_The_Whole_Repo(){
    Cleaner::Clean_All_Dependencies();
    
    auto current_path = Current_Path();
    
    Go_To_Git_Repo_Root();
    Dependency_Getter::Get_Dependencies(0,0,0);
    
    
    Set_Path(current_path);
}