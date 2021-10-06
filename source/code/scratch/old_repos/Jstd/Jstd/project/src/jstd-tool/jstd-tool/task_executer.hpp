#pragma once
#include <string>

class Task_Executer {

	//non-constructible
	Task_Executer()=delete;

protected:

	//given the string name of an object, give back a message that said object failed
	static std::string Error_Message(std::string const& object);


};
