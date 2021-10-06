#include "instruction.hpp"

//constructors
Instruction::Instruction(void)
: op_code{OP_Code::INVALID}
{}

Instruction::Instruction(std::string _op_code,std::string _address){
	op_code = enum_cast<OP_Code>(_op_code);
	address = _address;
}

//Observers
Address Instruction::Get_Address(void) const{
	return address;
}
OP_Code Instruction::Get_OP_Code(void) const{
	return op_code;
}
std::string Instruction::Get_OP_String(void) const{
	return to_string(op_code);
}
std::string Instruction::Get_Address_String(void) const{
	return std::to_string(address);
}

bool Instruction::Is_Empty(void) const{
	bool empty = false;
	if (op_code == OP_Code::INVALID){
		empty = true;
	}
	return empty;
}

//Transformers
void Instruction::Clear(void){
	op_code = OP_Code::INVALID;
	address = 0;
	return;
}

void Instruction::Set_Address(Address const& _address){
	address = _address;
	return;
}
void Instruction::Set_OP_Code(OP_Code const& _op_code){
	op_code = _op_code;
	return;
}

std::ostream& operator << (std::ostream &out, Instruction const& instruction){
	out << "[" << to_string(instruction.op_code) << "," << instruction.address << "]";
	return out;
}
