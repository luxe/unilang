#pragma once
#include "stat_timer.hpp"

//3rd Party
#include <gmpxx.h>

class Export_Stats: public Stat_Timer{
	
	
public:
	
	//constructor
	Export_Stats();
	
	//function recorders
	void Increment_Base_Function();
	void Increment_Function_Synonyms(mpz_class const& add_amount);
	
	//function observers
	mpz_class Number_Of_Base_Functions() const;
	mpz_class Number_Of_Function_Synonyms() const;

private:
	
	mpz_class base_functions;
	mpz_class function_synonyms;

};
