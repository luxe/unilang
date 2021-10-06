#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "processor/processor.hpp"
#include "main_memory/main_memory.hpp"
#include "shut_down_code/shut_down_code.hpp"
#include "operating_system/operating_system.hpp"
/*

*/
class SIM: public Operating_System{

	public:

	//Constructors

	//Observers

	friend std::ostream& operator << (std::ostream &out, SIM const& sim);

	//Transformers
	void Setup(std::vector<std::string> const& program_files);
	Shut_Down_Code Run(void);


	protected:
	private:

	void Execute_Statement(bool & shut_down_code);

	//functions
	void Boot_Message(void);
	void Run_Program(void);
	void Load_Program(void);
	bool Load_Program(std::string const& program_name);
	
	void Add(Process_Signal signal);
	void Sub(Process_Signal signal);
	void Ld(Process_Signal signal);
	void St(Process_Signal signal);
	void Halt(Process_Signal signal, bool & shut_down);
	void Done(Process_Signal signal);

	void Dump_Memory(std::ostream & out);

	//data members
	Processor processor;
	Main_Memory main_memory;
	std::vector<std::string> program_files;


};
