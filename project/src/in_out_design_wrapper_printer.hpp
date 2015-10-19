#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "CodeLang_structure.hpp"
#include "export_options.hpp"

class In_Out_Design_Wrapper_Printer{














public: static void Print(CodeLang_Structure const& structure, Export_Options const& options);

private: static void Print_Header(CodeLang_Structure const& structure, Export_Options const& options);


//destructure method
private: static void Print_Destructure_Deceleration(std::wofstream & out, CodeLang_Structure const& structure);

private: static void Print_Data_Members(std::wofstream & out, CodeLang_Structure const& structure, Export_Options const& options);

private: static void Print_Destructure_Definition(std::wofstream & out, CodeLang_Structure const& structure);
private: static void Print_Destructure_Body(std::wofstream & out, CodeLang_Structure const& structure);



private: static void Print_Source(CodeLang_Structure const& structure, Export_Options const& options);

public: static void Print_Declerations(std::wofstream & out, CodeLang_Structure const& structure, Export_Options const& options);

private: static unsigned int Number_Of_Non_Constructing_Public_Methods(std::string file_name, std::vector<Method_Item> methods);

private: static bool Is_Constructor(std::string file_name, Method_Item const& m);//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(In_Out_Design_Wrapper_Printer const& class_object);
	friend nlohmann::json As_JSON_Assignable(In_Out_Design_Wrapper_Printer const& class_object);
	friend  std::string As_YAML_String(In_Out_Design_Wrapper_Printer const& class_object);
	friend  std::string As_XML_String(In_Out_Design_Wrapper_Printer const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};