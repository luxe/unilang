#include "global_compiler.hpp"
#include "class_compiler.hpp"
#include "utilities.hpp"








 void Global_Compiler::Compile_HCP_File(Class_Structure const& structure, std::string const& hcp_file){

    //use the structure to print the cpp and hpp versions of the file
    std::wofstream hpp_stream(As_Removed_Suffix(hcp_file) + ".hpp");
    std::wofstream cpp_stream(As_Removed_Suffix(hcp_file) + ".cpp");

    auto str = As_Removed_Suffix(hcp_file);
    std::wstring wstr(str.begin(),str.end());
    cpp_stream << "#include " << '"' << wstr << ".hpp" << '"' << '\n';
    hpp_stream << "#pragma once\n";
    Print_Include_Files(hpp_stream,structure.Header_Includes());
    Print_Include_Files(cpp_stream,structure.Source_Includes());
    hpp_stream << '\n';
    cpp_stream << '\n';

    //dump hpp code wrapped in class name
    Dump_HPP(hpp_stream,structure,hcp_file);

    //dump cpp
    cpp_stream << structure.CPP_Code();
}

 void Global_Compiler::Print_Include_Files(std::wofstream & outfile, std::vector<std::pair<std::wstring,bool>> const& includes){

    for (auto it: includes){
        if (it.second){
            outfile << "#include ";
            if (Begins_And_Ends_With(it.first,L'"')){
                outfile << As_Last_Char_Removed(it.first) << ".hpp\"";
            }else{
                outfile << "<" << it.first << ">";
            }
            outfile << '\n';
        }
    }
}

 void Global_Compiler::Dump_HPP(std::wofstream & outfile, Class_Structure const& structure, std::string const& hcp_file){
    auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(Class_Compiler::hack_fix(hcp_file,true)));
    std::wstring wstr(str.begin(),str.end());
    outfile << "class " << wstr;
    if (!structure.Inheritance().empty()){
        outfile << ": " << structure.Inheritance();
    }
    outfile << "{\n";

    //dump
    outfile << structure.HPP_Code();
    outfile << "};";
    
}



