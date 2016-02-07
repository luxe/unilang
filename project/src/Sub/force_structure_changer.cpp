#include "force_structure_changer.hpp"










 void Force_Structure_Changer::Manipulate_Code_Structure_Based_Off_Of_Options(Structure & structure, Struct_Manipulation_Settings const& options){
    
    //perform manipulations on each section of the UniLang structure:
    Manipulate_Meta_Section(options,structure.meta);
    Manipulate_Import_Section(options,structure.imports);
}

 void Force_Structure_Changer::Manipulate_Meta_Section(Struct_Manipulation_Settings const& options, Meta_Section & meta_section){
    //not implemented
}


 void Force_Structure_Changer::Manipulate_Import_Section(Struct_Manipulation_Settings const& options, Import_Section & import_section){

    //some headers we force to be system headers.  
    //change the type flag to 'a system flag', if we see this:
    Force_Headers_To_Be_System(import_section,options.force_to_be_system_imports);
    Force_Headers_To_Have_A_Dot_H(import_section,options.force_header_to_have_a_dot_h);
}


 void Force_Structure_Changer::Force_Headers_To_Be_System(Import_Section & import_section, std::vector<std::string> const& header_names){
    for (auto & it: import_section.interface_dependencies){
        if (In_Vector(header_names,as_string(it.name.value))){
            it.type = Import_Type::SYSTEM;
        }
    }
    
    for (auto & it: import_section.implementation_dependencies){
        if (In_Vector(header_names,as_string(it.name.value))){
            it.type = Import_Type::SYSTEM;
        }
    }
}


 void Force_Structure_Changer::Force_Headers_To_Have_A_Dot_H(Import_Section & import_section, std::vector<std::string> const& header_names){
    for (auto & it: import_section.interface_dependencies){
        if (In_Vector(header_names,as_string(it.name.value))){
            it.name.value = it.name.value + L".h";
        }
    }
    
    for (auto & it: import_section.implementation_dependencies){
        if (In_Vector(header_names,as_string(it.name.value))){
            it.name.value = it.name.value + L".h";
        }
    }
}


