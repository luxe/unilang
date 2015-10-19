#include "in_out_design_wrapper_printer.hpp"
#include "stream_creator.hpp"
#include "shared_printer.hpp"
#include "header_printer.hpp"
#include "methods_printer.hpp"
#include "data_member_to_hungarian_notation_converter.hpp"
#include "test_wrapper_utilities.hpp"















 void In_Out_Design_Wrapper_Printer::Print(CodeLang_Structure const& structure, Export_Options const& options){
    Print_Header(structure,options);
    Print_Source(structure,options);
}

 void In_Out_Design_Wrapper_Printer::Print_Header(CodeLang_Structure const& structure, Export_Options const& options){

    //open file stream
    auto out = Stream_Creator::Create_Cpp_Header_Stream(structure,options,"Wrapper");
    
    //print top stuff
    Print_To_Stream_With_Newline(out,Test_Wrapper_Utilities::Get_Top_Comment());
    Print_To_Stream_With_Newline(out,"#pragma once");
    auto object_we_are_wrapping = As_Capital_And_Pushed_Together(structure.name) + ".h";
    Print_To_Stream_With_Newline(out,"    #include \"" + object_we_are_wrapping + "\"");
    Print_To_Stream_With_Newline(out,"");
    
    //class body
    Print_To_Stream(out,"class " + As_Capital_And_Pushed_Together(structure.name));
    Print_To_Stream_With_Newline(out," {");
    Print_To_Stream_With_Newline(out,"");
    Print_To_Stream_With_Newline(out,"//the component state we are wrapping in order to make testing easier");
    Print_To_Stream_With_Newline(out,As_Capital_And_Pushed_Together(structure.name) + "OutputsT o;");
    Print_Destructure_Deceleration(out,structure);
    Print_To_Stream_With_Newline(out,"");
    
    //functions and data members
    Print_Declerations(out,structure,options);
    Print_Data_Members(out,structure,options);

    //end of class body
    Print_To_Stream_With_Newline(out,"};");
}


//destructure method
 void In_Out_Design_Wrapper_Printer::Print_Destructure_Deceleration(std::wofstream & out, CodeLang_Structure const& structure){
    Print_To_Stream_With_Newline(out,"void Destructure();");
}

 void In_Out_Design_Wrapper_Printer::Print_Data_Members(std::wofstream & out, CodeLang_Structure const& structure, Export_Options const& options){
    Print_To_Stream_With_Newline(out,"//data members for direct access");
    for (auto it: structure.data_members.data_members){
        
        if (it.is_observable || it.is_obtainable){
            auto base_type = as_string(it.type.value);
            auto array_part = Strip_Out_Data_Between_First_Set_Of_Square_Brackets(base_type);
        
            Print_To_Stream(out,base_type + " ");
            Print_To_Stream_With_Newline(out,As_All_Lowercase_Letters_With_Spaces_As_Underscores(as_string(it.name.value)) + array_part + ";");
        }
    }
}

 void In_Out_Design_Wrapper_Printer::Print_Destructure_Definition(std::wofstream & out, CodeLang_Structure const& structure){
    Print_To_Stream_With_Newline(out,"void " + As_Capital_And_Pushed_Together(structure.name) + "::Destructure(){");
    Print_Destructure_Body(out,structure);
    Print_To_Stream_With_Newline(out,"}");
}
 void In_Out_Design_Wrapper_Printer::Print_Destructure_Body(std::wofstream & out, CodeLang_Structure const& structure){
for (auto it: structure.data_members.data_members){

    if (it.is_observable || it.is_obtainable){
        Print_To_Stream(out,"util::Assign(");
        Print_To_Stream(out,As_All_Lowercase_Letters_With_Spaces_As_Underscores(as_string(it.name.value)));
        Print_To_Stream(out, ",");

        auto name = Shared_Printer::Derive_Data_Member_Name(as_string(it.name.value));
        auto prefix = Data_Member_To_Hungarian_Notation_Converter::Get_Hungarian_Notation_Prefix(it,false,true);
        Print_To_Stream_With_Newline(out,"o." + prefix + name + ");");
   }
}
}



 void In_Out_Design_Wrapper_Printer::Print_Source(CodeLang_Structure const& structure, Export_Options const& options){
    auto out = Stream_Creator::Create_Cpp_Source_Stream(structure,options,"Wrapper");
    Print_To_Stream_With_Newline(out,"//Wrapper class for easier testing");
    Print_To_Stream_With_Newline(out,"//DO NOT EDIT; this is generated code");
    auto object_we_are_wrapping = As_Capital_And_Pushed_Together(structure.name);
    Print_To_Stream(out, "#include \"");
    Print_To_Stream(out,object_we_are_wrapping + "Wrapper.hpp");
    Print_To_Stream_With_Newline(out, "\"");
    Print_To_Stream(out, "#include \"test_utilities.hpp\"");
    Print_To_Stream_With_Newline(out, "");
    Print_To_Stream_With_Newline(out, "");
    auto method_count = Number_Of_Non_Constructing_Public_Methods(structure.name,structure.methods.methods);
    Methods_Printer::Print_Wrapper_Definition_Methods(structure.name,out,structure.methods.methods,method_count,options);
    Print_Destructure_Definition(out,structure);
}

 void In_Out_Design_Wrapper_Printer::Print_Declerations(std::wofstream & out, CodeLang_Structure const& structure, Export_Options const& options){
    Print_To_Stream_With_Newline(out,"public:");
    Print_To_Stream_With_Newline(out,"//expose the backend API of the component");
    Print_To_Stream_With_Newline(out,"");
    Methods_Printer::Print_Wrapper_Decleration_Methods(structure.name,out,structure.methods.methods,options);
}

 unsigned int In_Out_Design_Wrapper_Printer::Number_Of_Non_Constructing_Public_Methods(std::string file_name, std::vector<Method_Item> methods){
    //first get the number of callable methods
    unsigned int number_of_methods_not_counting_constructor = 0;
    for (auto it: methods){
        if (!Is_Constructor(file_name,it)){
            if (it.class_access == Class_Access::PUBLIC){
              ++number_of_methods_not_counting_constructor;
            }
        }
    }
    return number_of_methods_not_counting_constructor;
}

 bool In_Out_Design_Wrapper_Printer::Is_Constructor(std::string file_name, Method_Item const& m){
        if (As_Capital_And_Pushed_Together(file_name) == As_Capital_And_Pushed_Together(as_string(m.function_name.value))){
            return true;
        }
        return false;
}//functions added automatically by hcp-compiler
nlohmann::json As_JSON_Assignable(In_Out_Design_Wrapper_Printer const& class_object){
	nlohmann::json j;
	return j;
}std::string Class_Name(In_Out_Design_Wrapper_Printer const& class_object){
	return "In_Out_Design_Wrapper_Printer";
}std::string As_YAML_String(In_Out_Design_Wrapper_Printer const& class_object){
	std::string yaml_str;
	return yaml_str;
}std::string As_XML_String(In_Out_Design_Wrapper_Printer const& class_object){
	std::string xml_str;
	return xml_str;
}