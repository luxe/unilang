#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "CodeLang_structure.hpp"

class Global_Printer{





//printers










public: static void Print_Global_Interface_File(CodeLang_Structure const& structure);
public: static void Print_Global_Implementation_File(CodeLang_Structure const& structure);//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(Global_Printer const& class_object);
	friend nlohmann::json As_JSON_Assignable(Global_Printer const& class_object);
	friend  std::string As_YAML_String(Global_Printer const& class_object);
	friend  std::string As_XML_String(Global_Printer const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};