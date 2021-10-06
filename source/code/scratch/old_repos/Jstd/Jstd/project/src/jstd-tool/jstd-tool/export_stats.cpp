#include "export_stats.hpp"

//constructor
Export_Stats::Export_Stats()
: base_functions(0)
, function_synonyms(0)
{}

//function recorders
void Export_Stats::Increment_Base_Function(){
	++base_functions;
	return;
}
void Export_Stats::Increment_Function_Synonyms(mpz_class const& add_amount){
	function_synonyms += add_amount;
	return;
}

//function observers
mpz_class Export_Stats::Number_Of_Base_Functions() const{
	return base_functions;
}
mpz_class Export_Stats::Number_Of_Function_Synonyms() const{
	return function_synonyms;
}