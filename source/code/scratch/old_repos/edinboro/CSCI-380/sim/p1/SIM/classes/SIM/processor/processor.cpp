#include "processor.hpp"

Processor::Processor()
:	ac{0}
,   pc{0}
,   tmpr{0}
,   cs_pc{0}
{}
int Processor::next_instruction_index(void){
	mar = pc;
	return mar;
}
Process_Signal Processor::Signal(void){
	return process_signal;
}
int Processor::MAR(void){
	return mar;
}
Instruction Processor::MBR(void){
	return mbr;
}

//Transformers
void Processor::Execute(Instruction instruction){
	
	//register manipulation for every instruction
	//simulate the fetch/decode/execute
	
	//FETCH
	mbr = instruction;
	tmpr = ac;
	ac = pc;
	ac = ac + 1;
	pc = ac;
	ac = tmpr;
	ir = mbr.Get_OP_Code();
	
	
	//DECODE/EXECUTE
	switch(ir){
		case OP_Code::ADD:  Add();   break;
		case OP_Code::SUB:  Sub();   break;
		case OP_Code::LD:   Ld();    break;
		case OP_Code::ST:   St();    break;
		case OP_Code::BR:   Br();    break;
		case OP_Code::CBR:  Cbr();   break;
		case OP_Code::HALT: Halt();  break;
		case OP_Code::DATA: Data();  break;
		default:;
	}
	
	
	return;
}
void Processor::Execute(Process_Signal signal, Instruction instruction){
	
	//CONTINUE EXECUTION
	switch(signal){
		case Process_Signal::ADD:  Add(instruction);  break;
		case Process_Signal::SUB:  Sub(instruction);  break;
		case Process_Signal::LD:   Ld(instruction);   break;
		default:;
	}
	
	return;
}
void Processor::Add(Instruction instruction){
	mbr = instruction;
	tmpr = mbr.Get_Address();
	ac = ac + tmpr;
	
	return;
}
void Processor::Sub(Instruction instruction){
	mbr = instruction;
	tmpr = mbr.Get_Address();
	ac = ac - tmpr;
	return;
}
void Processor::Ld(Instruction instruction){
	mbr = instruction;
	ac = mbr.Get_Address();
	return;
}
	
void Processor::Add(void){
	tmpr = mbr.Get_Address();
	mar = tmpr;
	process_signal = Process_Signal::ADD;
	return;
}
void Processor::Sub(void){
	tmpr = mbr.Get_Address();
	mar = tmpr;
	process_signal = Process_Signal::SUB;
	return;
}
void Processor::Ld(void){
	tmpr = mbr.Get_Address();
	mar = tmpr;
	process_signal = Process_Signal::LD;
	return;
}
void Processor::St(void){
	tmpr = mbr.Get_Address();
	mar = tmpr;
	mbr.Set_Address(ac);
	process_signal = Process_Signal::ST;
	return;
}
void Processor::Br(void){
	pc = mbr.Get_Address();
	process_signal = Process_Signal::DONE;
	return;
}
void Processor::Cbr(void){
	if (ac == 0){
		pc = mbr.Get_Address();
	}
	process_signal = Process_Signal::DONE;
	return;
}
void Processor::Halt(void){
	process_signal = Process_Signal::HALT;
	return;
};
void Processor::Data(void){
	//do nothing
	process_signal = Process_Signal::DONE;
	return;
}
