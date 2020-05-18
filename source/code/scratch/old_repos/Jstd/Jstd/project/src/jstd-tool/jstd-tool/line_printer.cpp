#include "line_printer.hpp"


//constructor
Line_Printer::Line_Printer() :
m_length_of_current_line(0)
{}

//transformers
void Line_Printer::Refresh_Current_Line(std::string const& str, int const& actual_size) {

	int the_string_length;
	if (actual_size == -1) {
		the_string_length = static_cast<int>(str.size());
	}else{
		the_string_length = actual_size;
	}

	auto dif = static_cast<int>(m_length_of_current_line) - the_string_length;
	std::cout <<  '\r' << str;


	for (int i{0}; i < dif; ++i) {
		std::cout << ' ';
	}

	std::cout.flush();

	m_length_of_current_line = the_string_length;

	return;
}
void Line_Printer::End_Current_Line(std::string const& str, int const& actual_size) {

	int the_string_length;
	if (actual_size == -1) {
		the_string_length = static_cast<int>(str.size());
	}else{
		the_string_length = actual_size;
	}

	auto dif = static_cast<int>(m_length_of_current_line) - the_string_length;
	std::cout <<  '\r' << str;


	for (int i{0}; i < dif; ++i) {
		std::cout << ' ';
	}
	std::cout << std::endl;

	Reset();

	return;
}
void  Line_Printer::Reset() {
	m_length_of_current_line = 0;
	return;
}
