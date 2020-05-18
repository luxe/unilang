#pragma once

#include <iostream>
#include <string>
#include "percentage_printer.hpp"

class Pseudo_Library_Scanner_Printer {

public:

	//constructor
	Pseudo_Library_Scanner_Printer();

	//transformers
	void Update();

//private:

	//called during construction
	static int Get_Scan_Steps();

private:
	Percentage_Printer m_percentage_printer;
};
