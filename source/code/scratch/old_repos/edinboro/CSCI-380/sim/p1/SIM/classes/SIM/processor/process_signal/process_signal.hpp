#pragma once

/*

*/

#include <string>
enum class Process_Signal: char { INVALID
	,ADD
	,SUB
	,LD
	,ST
	,HALT
	,DONE
};

std::string to_string(Process_Signal const& enum_process_signal);
std::ostream& operator << (std::ostream &out, Process_Signal const& enum_process_signal);
template<Process_Signal> Process_Signal enum_cast(std::string s){
	Process_Signal process_signal{Process_Signal::INVALID};
	if (s == "add"){process_signal = Process_Signal::ADD;}
	else if(s == "sub"){process_signal = Process_Signal::SUB;}
	else if(s == "ld"){process_signal = Process_Signal::LD;}
	else if(s == "st"){process_signal = Process_Signal::ST;}
	else if(s == "halt"){process_signal = Process_Signal::HALT;}
	else if(s == "done"){process_signal = Process_Signal::DONE;}
		return process_signal;
}
template<Process_Signal> Process_Signal enum_cast(int const& i){
	Process_Signal process_signal{Process_Signal::INVALID};
	switch(i){
	case 1: return Process_Signal::SUB;
	case 2: return Process_Signal::LD;
	case 3: return Process_Signal::ST;
	case 4: return Process_Signal::HALT;
	case 5: return Process_Signal::DONE;
	default:;
}		return process_signal;
}
template<Process_Signal> Process_Signal enum_cast(char const& i){
	Process_Signal process_signal{Process_Signal::INVALID};
	switch(i){
	case '1': return Process_Signal::SUB;
	case '2': return Process_Signal::LD;
	case '3': return Process_Signal::ST;
	case '4': return Process_Signal::HALT;
	case '5': return Process_Signal::DONE;
	default:;
}		return process_signal;
}
