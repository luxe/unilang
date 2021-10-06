
#include "program_options.hpp"

class Program_Options_Checker {

	//If there are any additional issues with the flags you would like to check for, that can be done here.
	//these checks should deal with logical issues of the flag values, and not how flag values were passed.
	//If there are no logic errors, then the function will return; else it will exit the program inside the function.
	//This function is called automatically by the Program_Options object, and it is also called by the "test"
	//flag to support the "test" concept of symbolic pull-ins.
	public: static void Check(Program_Options const& program_options);
};
