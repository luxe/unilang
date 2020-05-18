#pragma once
#include "utilities.hpp"
#include "systems.hpp"
#include <boost/throw_exception.hpp>
#include <boost/exception/all.hpp>

class Root_Exception_Handler{






public: static void Handle_Exceptions() ;

private: static void Handle_Exception(std::string const& e);
private: static void Handle_Exception(std::exception const& e);

private: static void Handle_Exception();

//handle other exceptions...

private: static void Print_Message_Along_With_Diagnostic_Information(std::string const& exception_message);
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