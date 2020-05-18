#include "class_compiler.hpp"
#include "utilities.hpp"








 void Class_Compiler::Compile_HCP_File(Class_Structure const& structure, std::string const& hcp_file){

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
    
    
    //add the json exporting function
    /*
    cpp_stream << "nlohmann::json As_JSON_Assignable(" <<  wstr << " const& class_object){\n";
    cpp_stream << "\tnlohmann::json j;\n";
    auto str1 = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(hcp_file));
    std::wstring wstr1(str.begin(),str.end());
    for (auto const& data_member: structure.Data_Members()){
        cpp_stream << "\tj[\"" << data_member << "\"] = As_JSON_Assignable(class_object." << wstr1 << ");\n";
    }
    */
    //cpp_stream << "\treturn j;\n}";
}

 void Class_Compiler::Print_Include_Files(std::wofstream & outfile, std::vector<std::pair<std::wstring,bool>> const& includes){

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

std::string Class_Compiler::hack_fix(std::string hcp_file, bool do_bootstrap_hack){

    //ADDED IN HACK TO BOOTSTRAP ONLY
    hcp_file = As_Removed_Suffix(hcp_file);
        std::string new_hcp_file;
           if (do_bootstrap_hack){
            for(int i = hcp_file.length() - 1; i >= 0; --i){
                if (hcp_file[i] == '/'){
                break;
                }
                std::string char_str;
                char_str += hcp_file[i];
                new_hcp_file = char_str + new_hcp_file;
            }
        }
        else{
                   new_hcp_file = hcp_file;
        }
        return new_hcp_file;
}

 void Class_Compiler::Dump_HPP(std::wofstream & outfile, Class_Structure const& structure, std::string const& hcp_file){


    auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(Class_Compiler::hack_fix(hcp_file,true)));
    std::wstring wstr(str.begin(),str.end());
    outfile << "class " << wstr;
    if (!structure.Inheritance().empty()){
        outfile << ": " << structure.Inheritance();
    }
    outfile << "{\n";

    //dump
    outfile << structure.HPP_Code();
    
    //outfile << "public: friend nlohmann::json As_JSON_Assignable(" <<  str << " const& class_object);\n";
    
    outfile << "};";
    
}

