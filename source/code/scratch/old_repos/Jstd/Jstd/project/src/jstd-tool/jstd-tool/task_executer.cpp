#include "task_executer.hpp"

std::string Task_Executer::Error_Message(std::string const& object) {
	return std::string(object + " FAILED FOR AN UNEXPECTED REASON! THERE IS SOMETHING WRONG WITH THE " + object + "!");
}
