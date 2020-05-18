#pragma once
#ifndef DIET_H
#define DIET_H

//never pass up an excuse to play with boost!
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

class DieT{

public:

	//Constructor
	explicit DieT(int const& min_dice_value, int const& max_dice_value);
	explicit DieT(int const& min_dice_value, int const& max_dice_value, int const& value);
	
	//Transformer
	void Roll(void);
	
	//Observer
	int Value(void);
	
	friend std::ostream& operator << (std::ostream &out, DieT const& die);

private:

	//dice range
	int min_dice_value;
	int max_dice_value;
	
	//dice value (it will be somewhere in the range)
	int value;

	//the random number generator(uses time for seed)
	static boost::random::mt19937 gen;

};
#endif
