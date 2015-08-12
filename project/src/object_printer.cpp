#include "object_printer.hpp"
#include "meta_block_printer.hpp"
#include "code_wrap_printer.hpp"
#include "header_printer.hpp"
#include "component_struct_printer.hpp"
#include "initialize_printer.hpp"
#include "update_printer.hpp"
#include "api_printer.hpp"






//printers used










 void Object_Printer::Print_Object_Interface_File(CodeLang_Structure const& structure){

    std::wofstream out(As_Capital_And_Pushed_Together(structure.name) + ".h");
    Meta_Block_Printer::Print(structure.name,out,"Interface",structure.meta);
    Code_Wrap_Printer::Print_Beginning_Of_Header_Include_Gaurd(structure.name,out);
    Header_Printer::Print_Object_Interface_Headers(structure.name,out,structure.imports.interface_dependencies);
    
    Initialize_Printer::Print_Initialize_Declaration(out,structure);
    Update_Printer::Print_Update_Declaration(out,structure);
    
    Code_Wrap_Printer::Possibly_Print_Close_Markers(out,structure.name,structure.meta,true);
}
 void Object_Printer::Print_Object_Implementation_File(CodeLang_Structure const& structure){

    std::wofstream out(As_Capital_And_Pushed_Together(structure.name) + ".c");
    Meta_Block_Printer::Print(structure.name,out,"Implementation",structure.meta);
    Header_Printer::Print_Object_Implementation_Headers(structure.name,out,structure.imports.implementation_dependencies);
    
    Api_Printer::Print_Declerations(out,structure);
    Initialize_Printer::Print_Initialize_Definition(out,structure);
    Update_Printer::Print_Update_Definition(out,structure);
    Api_Printer::Print_Definitions(out,structure);
    
    Code_Wrap_Printer::Possibly_Print_Close_Markers(out,structure.name,structure.meta,false);
}
 void Object_Printer::Print_Object_Data_File(CodeLang_Structure const& structure){

    std::wofstream out(As_Capital_And_Pushed_Together(structure.name) + "Data.h");
    Meta_Block_Printer::Print(structure.name,out,"Data",structure.meta);
    Code_Wrap_Printer::Print_Beginning_Of_Header_Include_Gaurd(structure.name,out);
    Header_Printer::Print_Object_Data_Headers(structure.name,out,structure.imports.interface_dependencies);
    Component_Struct_Printer::Print_Data_Structs(out,structure);
    Code_Wrap_Printer::Possibly_Print_Close_Markers(out,structure.name,structure.meta,true);
}//functions added automatically by hcp-compiler
nlohmann::json As_JSON_Assignable(Object_Printer const& class_object){
	nlohmann::json j;
	return j;
}std::string Class_Name(Object_Printer const& class_object){
	return "Object_Printer";
}std::string As_YAML_String(Object_Printer const& class_object){
	std::string yaml_str;
	return yaml_str;
}std::string As_XML_String(Object_Printer const& class_object){
	std::string xml_str;
	return xml_str;
}