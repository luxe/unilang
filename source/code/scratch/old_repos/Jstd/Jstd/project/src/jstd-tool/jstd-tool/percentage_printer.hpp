#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "line_printer.hpp"

class Percentage_Printer{

public:

	//constructor
	//it will automatically print task [0/amount]
	Percentage_Printer(std::string const& task, int (*function_to_get_number_of_steps)() );

	//transformers
	void Update();


private:

	void Print_End_Message();

	std::string m_task;
	int m_current_step, m_number_of_steps;
	Line_Printer m_line_printer;

};
