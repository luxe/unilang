#pragma once
#include <iostream>
#include <array>
#include "instruction/instruction.hpp"
#include "constants.hpp"
#include <string>
/*

*/

class Main_Memory{
	public:

	//Constructors
	explicit Main_Memory(void);

	//Observers
	friend std::ostream& operator << (std::ostream &out, Main_Memory const& main_memory);

	Instruction Get(unsigned int index);

	std::string Get_OP_String(unsigned int index);
	std::string Get_Address_String(unsigned int index);


	bool Is_Empty(unsigned int index);

	//Transformers
	bool Add_Instruction(std::string const& op_code, std::string const& address);
	void Purge(void);
	void Set(unsigned int index, Instruction const& instruction);
	void Set_Address(unsigned int index, unsigned int address);


	protected:
	private:

	//functions

	//data members
	std::array<Instruction,constants::MAIN_MEMORY_SIZE> cells;
	unsigned short fill_index;

};
