#include "process_signal.hpp"

std::string to_string(Process_Signal const& enum_process_signal){
	std::string str{"INVALID"};
	switch (enum_process_signal){
		case Process_Signal::ADD: str = "add"; break;
		case Process_Signal::SUB: str = "sub"; break;
		case Process_Signal::LD: str = "ld"; break;
		case Process_Signal::ST: str = "st"; break;
		case Process_Signal::HALT: str = "halt"; break;
		case Process_Signal::DONE: str = "done"; break;
		default:;
	}
	return str;
}std::ostream& operator << (std::ostream &out, Process_Signal const& enum_process_signal){
	out << to_string(enum_process_signal);
	return out;
}