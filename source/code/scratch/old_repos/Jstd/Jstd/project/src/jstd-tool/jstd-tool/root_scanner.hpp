#include <iostream>
#include <string>
#include <cstdlib>
#include "warn_machine.hpp"

class Root_Scanner {

public:
	static bool Scan(Warn_Machine & warn_machine);

private:
	static bool Make_Sure_The_Necessary_Files_Are_Present_At_Root(Warn_Machine & warn_machine);
	static bool Make_Sure_No_Extra_Files_Exist_At_Root(Warn_Machine & warn_machine);
};
