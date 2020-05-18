#include "pseudo_library_resource_scanner_printer.hpp"
#include "utilities.hpp"
#include "global.hpp"

//constructor
Pseudo_Library_Resource_Scanner_Printer::Pseudo_Library_Resource_Scanner_Printer()
: m_percentage_printer("\tPseudo Library Resources ", Get_Scan_Steps)
{}

//transformers
void Pseudo_Library_Resource_Scanner_Printer::Update() {
	m_percentage_printer.Update();
}

//called during construction
int Pseudo_Library_Resource_Scanner_Printer::Get_Scan_Steps() {
	return Get_Number_Of_Files_In_Directory(constant::PATH_TO_REGEX_COMPACTS) +
	Get_Number_Of_Files_In_Directory(constant::PATH_TO_REGEX_EXPRESSIONS);
}
