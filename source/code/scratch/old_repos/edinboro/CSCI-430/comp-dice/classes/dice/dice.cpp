#include "dice.h"

#include <algorithm>
#include <utility>

//Constructor
DiceT::DiceT(int const& dice_amount,int const& sides_)
:amount{dice_amount}
,sides{sides_}
{
	for (int i = 0; i < dice_amount; ++i){
		dice.push_back(DieT(1, sides));
	}
	return;
}
DiceT::DiceT(std::string str){

//hahaha, the tab key doesn't work on this laptop
std::string temp;
auto it = str.begin();

while (*it != ' '){
temp+=*it;
++it;
}
amount  = atoi(temp.c_str());
temp.clear();

++it;
while (*it != ' '){
temp+=*it;
++it;
}
sides  = atoi(temp.c_str());
temp.clear();



for (int i{0}; i < amount; ++i){

++it;
while (*it != ' '){
temp+=*it;
++it;
}
dice.push_back(DieT{amount,sides,atoi(temp.c_str())});
temp.clear();




}






}


//Transformer
void DiceT::Roll(void){

	for (auto & die : dice){
		die.Roll();
	}

	return;
}

//Observers
std::string DiceT::Str(void){
    std::string str;
    str+= std::to_string(amount);
    str+= ' ';
    str+= std::to_string(sides);
    str+= ' ';
    for (auto& it: dice){
        str+= std::to_string(it.Value());
        str+= ' ';
    }

    return str;
}
int DiceT::Amount(void){

    return amount;
}
int DiceT::Sides(void){

    return sides;
}
std::vector<DieT> DiceT::Get(void){
	return dice;
}
int DiceT::Max(void){
	
	int max = 0;
	for (auto & die : dice){
		if (max < die.Value()){
			max = die.Value();
		}
	}
	
	return max;
}
int DiceT::Min(void){
	
	//to throw or not to throw.. that is the question
	//tis it nobler in the mind to suffer the faults of segmentation,
	//or take gaurds against a sea of errors, and by opposing end them:
	//to go to class in 3 hours. to sleep no more;
	int min{0};
	if (!dice.empty()){
		min = dice[0].Value();
	}
	
	for (auto & die : dice){
		if (min > die.Value()){
			min = die.Value();
		}
	}
	
	return min;
}
int DiceT::Sum(void){
	
	int sum = 0;
	for (auto & die : dice){
		sum+= die.Value();
	}
	
	return sum;
}

//Overload
std::ostream& operator << (std::ostream &out, DiceT const& d){
		
	out << '{';
	for (auto it= d.dice.cbegin(); it != d.dice.cend(); ++it){
		out << *it;
		if (it != d.dice.cend()-1){
			out << ", ";
		}
	}
	out << '}';
	return out;
}
