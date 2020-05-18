#pragma once
#include <iostream>
#include <string>

class Line_Printer{

public:

	//constructor
	Line_Printer();

	//transformers
	void Refresh_Current_Line(std::string const& str, int const& actual_size = -1);
	void End_Current_Line(std::string const& str, int const& actual_size = -1);

private:
	void Reset();
	size_t m_length_of_current_line;



};
