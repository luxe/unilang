#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "meta_section.hpp"

class Code_Wrap_Printer{






//begin wrapper
public: static void Print_Beginning_Of_Header_Include_Gaurd(std::string file_name,std::wofstream & out);

//end wrapper
public: static void Possibly_Print_Close_Markers(std::wofstream & out, std::string file_name,Meta_Section const& meta, bool is_header);
//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(Code_Wrap_Printer const& class_object);
	friend nlohmann::json As_JSON_Assignable(Code_Wrap_Printer const& class_object);
	friend  std::string As_YAML_String(Code_Wrap_Printer const& class_object);
	friend  std::string As_XML_String(Code_Wrap_Printer const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};