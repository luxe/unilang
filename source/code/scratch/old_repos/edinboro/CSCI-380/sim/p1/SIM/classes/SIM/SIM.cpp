#include <fstream>
#include <iomanip>
#include "SIM.hpp"
#include "constants.hpp"
#include "process_signal/process_signal.hpp"

//Transformers
void SIM::Setup(std::vector<std::string> const& _program_files){
	program_files= _program_files;
	return;
}
Shut_Down_Code SIM::Run(void){

	//start the OS and load the program(s)
	Boot_Message();
	
	//create a shut down code to send back to the hardware
	//when the operating system shuts down
	Shut_Down_Code shut_down_code;
	
	//run the program interactively or automatically 
	if (!program_files.empty()){
		for (auto program: program_files){
			if (Load_Program(program)){
				Run_Program();
			}
		}
	}else{
		Load_Program();
		Run_Program();
	}


	return shut_down_code;
}
void SIM::Run_Program(void){
	
	//have the processor run the program until the program
	//reaches a halt, or the program crashes.
	bool shut_down = false;
	do{Execute_Statement(shut_down);}while(!shut_down);

	//after finishing the execution of a program,
	//dump the memory
	Dump_Memory(std::cout);
	
	return;
}
void SIM::Dump_Memory(std::ostream & out){

	//dump the memory in a formatted manner (check the constants to adjust)
	for (int i = 0; i < constants::TOP_NEWLINE_COUNT; ++i){out << '\n';}
	out << "Memory:\n";
	for (unsigned int i = 0; i < constants::MAIN_MEMORY_SIZE; ++i){
		if (!main_memory.Is_Empty(i)){
			out << std::setw(constants::MEMORY_INDEX_WIDTH) << i
			<< std::setw(constants::OP_CODE_SET_WIDTH) << main_memory.Get_OP_String(i)
			<< std::setw(constants::ADDRESS_SET_WIDTH) << main_memory.Get_Address_String(i) << '\n';
		}
	}
	for (int i = 0; i < constants::BOTTOM_NEWLINE_COUNT; ++i){out << '\n';}

	return;
}
void SIM::Execute_Statement(bool & shut_down){


	//execute each instruction by taking the PC,
	//grabbing the instruction in that address,
	//and giving it to the processor to ececute.
	int index = processor.next_instruction_index();
	Instruction instr = main_memory.Get(index);
	processor.Execute(instr);

	
	//get the response from the processor.
	//Is there more it needs from main memory?
	auto signal = processor.Signal();
	switch(signal){
		case Process_Signal::ADD:  Add(signal);  break;
		case Process_Signal::SUB:  Sub(signal);  break;
		case Process_Signal::LD:   Ld(signal);   break;
		case Process_Signal::ST:   St(signal);   break;
		case Process_Signal::HALT: Halt(signal,shut_down); break;
		case Process_Signal::DONE: Done(signal); break;
		default:;
	}
	

	return;
}

void SIM::Add(Process_Signal signal){
	int address = processor.MAR();
	Instruction instruction = main_memory.Get(address);
	processor.Execute(signal,instruction);
	
	return;
}
void SIM::Sub(Process_Signal signal){
	int address = processor.MAR();
	Instruction instruction = main_memory.Get(address);
	processor.Execute(signal,instruction);
	return;
}
void SIM::Ld(Process_Signal signal){
	int address = processor.MAR();
	Instruction instruction = main_memory.Get(address);
	processor.Execute(signal,instruction);
	return;
}
void SIM::St(Process_Signal signal){
	int address = processor.MAR();
	Instruction instruction = processor.MBR();
	main_memory.Set_Address(address,instruction.Get_Address());
	return;
}
void SIM::Halt(Process_Signal signal, bool & shut_down){
	shut_down = true;
	return;
}
void SIM::Done(Process_Signal signal){
	return;
}

//functions
void SIM::Boot_Message(void){
	std::cout << "\nThis is a simulation of an Operating System.\n";
	return;
}
void SIM::Load_Program(void){

	//prompt for program
	std::cout << "What program should I run? ";
	std::string program_name;
	std::getline(std::cin,program_name);

	//make sure file exists
	std::ifstream infile{program_name};
	while (!infile.is_open()){
		std::cout << "\nI couldn't open that.\n";
		std::cout << "What file? ";
		std::cout.flush();
		infile.clear();
		std::getline(std::cin,program_name);
		infile.open(program_name);
	}

	//fill up the main memory
	std::string op;
	std::string address;
	infile >> op;
	infile >> address;
	bool successful_add = true;
	for (unsigned short i = 0; i < constants::MAIN_MEMORY_SIZE-1 && infile && successful_add; ++i){
		successful_add = main_memory.Add_Instruction(op,address);
		infile >> op;
		infile >> address;
	}

	//program is too big for the memory
	//NOTE: should be handled (possibly log)
	if (infile){
	}

	return;
}
bool SIM::Load_Program(std::string const& program_name){

	//make sure file exists
	bool success = false;
	std::ifstream infile{program_name};
	if (infile.is_open()){

		//fill up the main memory
		std::string op;
		std::string address;
		infile >> op;
		infile >> address;
		bool successful_add = true;
		for (unsigned short i = 0; i < constants::MAIN_MEMORY_SIZE-1 && infile && successful_add; ++i){
			successful_add = main_memory.Add_Instruction(op,address);
			infile >> op;
			infile >> address;
		}

		//program is too big for the memory
		//NOTE: should be handled (possibly log)
		if (infile){
		}
		success = true;
	}

	return success;
}

std::ostream& operator << (std::ostream &out, SIM const& sim){
	out << "SIM OS";
	return out;
}
