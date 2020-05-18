#pragma once

/*

*/

#include <string>
enum class OP_Code: char { INVALID
	,ADD
	,SUB
	,LD
	,ST
	,BR
	,CBR
	,HALT
	,DATA
};

std::string to_string(OP_Code const& enum_op_code);
std::ostream& operator << (std::ostream &out, OP_Code const& enum_op_code);
template<typename OP_Code> OP_Code enum_cast(std::string s){
	OP_Code op_code{OP_Code::INVALID};
	if (s == "ADD"){op_code = OP_Code::ADD;}
	else if(s == "SUB"){op_code = OP_Code::SUB;}
	else if(s == "LD"){op_code = OP_Code::LD;}
	else if(s == "ST"){op_code = OP_Code::ST;}
	else if(s == "BR"){op_code = OP_Code::BR;}
	else if(s == "CBR"){op_code = OP_Code::CBR;}
	else if(s == "HALT"){op_code = OP_Code::HALT;}
	else if(s == "DATA"){op_code = OP_Code::DATA;}
		return op_code;
}
template<typename OP_Code> OP_Code enum_cast(int const& i){
	OP_Code op_code{OP_Code::INVALID};
	switch(i){
	case 1: return OP_Code::SUB;
	case 2: return OP_Code::LD;
	case 3: return OP_Code::ST;
	case 4: return OP_Code::BR;
	case 5: return OP_Code::CBR;
	case 6: return OP_Code::HALT;
	case 7: return OP_Code::DATA;
	default:;
}		return op_code;
}
template<typename OP_Code> OP_Code enum_cast(char const& i){
	OP_Code op_code{OP_Code::INVALID};
	switch(i){
	case '1': return OP_Code::SUB;
	case '2': return OP_Code::LD;
	case '3': return OP_Code::ST;
	case '4': return OP_Code::BR;
	case '5': return OP_Code::CBR;
	case '6': return OP_Code::HALT;
	case '7': return OP_Code::DATA;
	default:;
}		return op_code;
}
