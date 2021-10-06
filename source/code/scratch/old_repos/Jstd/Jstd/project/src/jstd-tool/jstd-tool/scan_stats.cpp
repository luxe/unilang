#include "scan_stats.hpp"

//for other stats
void Scan_Stats::Store_If_Max_Depth(uint const& namespace_depth){
	if (namespace_depth > max_namespace_depth){
		max_namespace_depth = namespace_depth;
	}
	return;
}
unsigned int Scan_Stats::Get_Max_Depth(){
	return max_namespace_depth;
}
