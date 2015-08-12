#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "CodeLang_structure.hpp"

class Object_Printer{





//printers used






public: static void Print_Object_Interface_File(CodeLang_Structure const& structure);
public: static void Print_Object_Implementation_File(CodeLang_Structure const& structure);
public: static void Print_Object_Data_File(CodeLang_Structure const& structure);//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(Object_Printer const& class_object);
	friend nlohmann::json As_JSON_Assignable(Object_Printer const& class_object);
	friend  std::string As_YAML_String(Object_Printer const& class_object);
	friend  std::string As_XML_String(Object_Printer const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};