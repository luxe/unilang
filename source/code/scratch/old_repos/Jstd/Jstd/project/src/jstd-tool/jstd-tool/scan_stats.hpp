#pragma once
#include "stat_timer.hpp"
#include <vector>
#include <string>

class Scan_Stats: public Stat_Timer{


public:

		//transformers
		void Store_If_Max_Depth(uint const& namespace_depth);

		//observers
		unsigned int Get_Max_Depth();

private:

	//other stats
	unsigned int max_namespace_depth;

};
