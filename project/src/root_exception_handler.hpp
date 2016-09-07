#pragma once
#include "utilities.hpp"
#include "systems.hpp"

class Root_Exception_Handler{




public: static void Handle_Exceptions() ;

private: static void Report_Error_Mesage_With_No_Extra_Data(std::string const& e);

private: static void Report_Unknown_Error();
//functions added automatically by hcp-compiler
public:
	friend  std::string Class_Name(Root_Exception_Handler const& class_object);
	friend nlohmann::json As_JSON_Assignable(Root_Exception_Handler const& class_object);
	friend  std::string As_YAML_String(Root_Exception_Handler const& class_object);
	friend  std::string As_XML_String(Root_Exception_Handler const& class_object);
private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version){
}
};