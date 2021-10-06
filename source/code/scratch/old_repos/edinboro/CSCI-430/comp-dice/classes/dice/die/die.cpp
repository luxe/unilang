#include "die.h"
#include <ctime>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

boost::random::mt19937 DieT::gen(std::time(0));

//Constructor
DieT::DieT(int const& min_dice_value_, int const& max_dice_value_)
: min_dice_value(min_dice_value_)
, max_dice_value(max_dice_value_)
{Roll();} /* roll so the value isn't garbage */

DieT::DieT(int const& min_dice_value_, int const& max_dice_value_, int const& value_)
: min_dice_value(min_dice_value_)
, max_dice_value(max_dice_value_)
, value{value_}
{}

//Transformer
void DieT::Roll(void){
	if (min_dice_value <= max_dice_value){
		boost::random::uniform_int_distribution<> dist(min_dice_value, max_dice_value);
		value = dist(gen);
	}
	return;
}

//Observer
int DieT::Value(void){
	return value;
}

//Overload
std::ostream& operator << (std::ostream &out, DieT const& die){
	return out << die.value;
}
