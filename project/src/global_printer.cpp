#include "global_printer.hpp"
#include "meta_block_printer.hpp"
#include "code_wrap_printer.hpp"
#include "header_printer.hpp"
#include "methods_printer.hpp"






//printers








 void Global_Printer::Print_Global_Interface_File(CodeLang_Structure const& structure){

    std::wofstream out(As_Capital_And_Pushed_Together(structure.name) + ".h");
    Meta_Block_Printer::Print(structure.name,out,"Interface",structure.meta);
    Code_Wrap_Printer::Print_Beginning_Of_Header_Include_Gaurd(structure.name,out);
    Header_Printer::Print_Global_Interface_Headers(structure.name,out,structure.imports.interface_dependencies);
    Methods_Printer::Print_Global_Interface_Methods(out,structure.methods.methods);
    Code_Wrap_Printer::Possibly_Print_Close_Markers(out,structure.name,structure.meta,true);
}
 void Global_Printer::Print_Global_Implementation_File(CodeLang_Structure const& structure){

    std::wofstream out(As_Capital_And_Pushed_Together(structure.name) + ".c");
    Meta_Block_Printer::Print(structure.name,out,"Implementation",structure.meta);
    Header_Printer::Print_Global_Implementation_Headers(structure.name,out,structure.imports.implementation_dependencies);
    Methods_Printer::Print_Global_Implementation_Methods(out,structure.methods.methods);
    Code_Wrap_Printer::Possibly_Print_Close_Markers(out,structure.name,structure.meta,false);
}//functions added automatically by hcp-compiler
nlohmann::json As_JSON_Assignable(Global_Printer const& class_object){
	nlohmann::json j;
	return j;
}std::string Class_Name(Global_Printer const& class_object){
	return "Global_Printer";
}std::string As_YAML_String(Global_Printer const& class_object){
	std::string yaml_str;
	return yaml_str;
}std::string As_XML_String(Global_Printer const& class_object){
	std::string xml_str;
	return xml_str;
}