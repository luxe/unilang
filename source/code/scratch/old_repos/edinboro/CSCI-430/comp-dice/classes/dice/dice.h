//nice! totally stealing this from the dino dice project
#pragma once
#ifndef DICET_H
#define DICET_H
#include "die/die.h"

#include <iostream>
#include <vector>


class DiceT{

public:
	
	//Constructor
	DiceT(int const& dice_amount,int const& sides);
	DiceT(std::string str);
	
	//Transformers
	void Roll(void);
	
	//Observers
	std::vector<DieT> Get(void);
	int Max(void);
	int Min(void);
	int Sum(void);
	
	int Amount(void);
	int Sides(void);
	
	std::string Str(void);
	
	friend std::ostream& operator << (std::ostream &out, DiceT const& d);

private:
	std::vector<DieT> dice;
	
	int amount;
	int sides;

};
#endif
