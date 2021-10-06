#include "pseudo_library_scanner_printer.hpp"
#include "utilities.hpp"
#include "global.hpp"

//constructor
Pseudo_Library_Scanner_Printer::Pseudo_Library_Scanner_Printer()
: m_percentage_printer("\tPseudo Library           ",Get_Scan_Steps)
{}

//transformers
void Pseudo_Library_Scanner_Printer::Update() {
	m_percentage_printer.Update();
}

//called during construction
int Pseudo_Library_Scanner_Printer::Get_Scan_Steps() {
	return Recursively_Get_Directory_Count();
}
