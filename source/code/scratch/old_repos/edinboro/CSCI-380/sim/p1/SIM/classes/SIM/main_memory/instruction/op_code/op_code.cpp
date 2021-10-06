#include "op_code.hpp"

std::string to_string(OP_Code const& enum_op_code){
	std::string str{"INVALID"};
	switch (enum_op_code){
		case OP_Code::ADD: str = "ADD"; break;
		case OP_Code::SUB: str = "SUB"; break;
		case OP_Code::LD: str = "LD"; break;
		case OP_Code::ST: str = "ST"; break;
		case OP_Code::BR: str = "BR"; break;
		case OP_Code::CBR: str = "CBR"; break;
		case OP_Code::HALT: str = "HALT"; break;
		case OP_Code::DATA: str = "DATA"; break;
		default:;
	}
	return str;
}std::ostream& operator << (std::ostream &out, OP_Code const& enum_op_code){
	out << to_string(enum_op_code);
	return out;
}