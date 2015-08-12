#include "code_wrap_printer.hpp"







//begin wrapper
 void Code_Wrap_Printer::Print_Beginning_Of_Header_Include_Gaurd(std::string file_name,std::wofstream & out){
        Print_To_Stream_With_Newline(out,"#ifndef " + As_Capital_And_Pushed_Together(file_name) + "H");
        Print_To_Stream_With_Newline(out,"#define " + As_Capital_And_Pushed_Together(file_name) + "H");
        Print_To_Stream_With_Newline(out,"");
}

//end wrapper
 void Code_Wrap_Printer::Possibly_Print_Close_Markers(std::wofstream & out, std::string file_name,Meta_Section const& meta, bool is_header){

    if (is_header){
        Print_To_Stream_With_Newline(out,"#endif /* " + As_Capital_And_Pushed_Together(file_name) + "H */");
    }
    if (!meta.group_names.empty()){
        Print_To_Stream_With_Newline(out,"///@}");
    }
    Print_To_Stream_With_Newline(out,"");
    
}
//functions added automatically by hcp-compiler
nlohmann::json As_JSON_Assignable(Code_Wrap_Printer const& class_object){
	nlohmann::json j;
	return j;
}std::string Class_Name(Code_Wrap_Printer const& class_object){
	return "Code_Wrap_Printer";
}std::string As_YAML_String(Code_Wrap_Printer const& class_object){
	std::string yaml_str;
	return yaml_str;
}std::string As_XML_String(Code_Wrap_Printer const& class_object){
	std::string xml_str;
	return xml_str;
}