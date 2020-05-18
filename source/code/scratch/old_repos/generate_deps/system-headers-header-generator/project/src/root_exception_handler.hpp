#pragma once
#include "utilities.hpp"
#include <boost/throw_exception.hpp>
#include <boost/exception/all.hpp>

class Root_Exception_Handler{





public: static void Handle_Exceptions() ;

private: static void Handle_Exception(std::string const& e);
private: static void Handle_Exception(std::exception const& e);

private: static void Handle_Exception();

//handle other exceptions...

private: static void Print_Message_Along_With_Diagnostic_Information(std::string const& exception_message);
};