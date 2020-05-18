#include "main_memory.hpp"


Main_Memory::Main_Memory(void)
: fill_index{0}
{}

//Observers
void Main_Memory::Set(unsigned int index, Instruction const& instruction){
	cells[index] = instruction;
	return;
}
void Main_Memory::Set_Address(unsigned int index, unsigned int address){
	cells[index].Set_Address(address);
	return;
}
Instruction Main_Memory::Get(unsigned int index){
	return cells[index];
}

std::string Main_Memory::Get_OP_String(unsigned int index){
	return cells[index].Get_OP_String();
}
std::string Main_Memory::Get_Address_String(unsigned int index){
	
	std::string str = cells[index].Get_Address_String();
	if (str == "0"){
		str = "00";
	}
	return str;
}

bool Main_Memory::Is_Empty(unsigned int index){

	return cells[index].Is_Empty();
}

//Transformers
void Main_Memory::Purge(void){

	//wipe memory
	for (auto it: cells){
		it.Clear();
	}
	return;
}
bool Main_Memory::Add_Instruction(std::string const& op_code, std::string const& address){
	bool added = true;
	if (fill_index < constants::MAIN_MEMORY_SIZE){
		cells[fill_index] = Instruction(op_code,address);
		++fill_index;
	}else{
		added = false;
	}

	return added;
}

std::ostream& operator << (std::ostream &out, Main_Memory const& main_memory){
	for (auto it: main_memory.cells){
		out << it << '\n';
	}
	return out;
}
