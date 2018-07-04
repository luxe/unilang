#include "code/utilities/types/booleans/lib.hpp"

bool& Flip(bool & b) {
	b = !b; return b;
}
bool& Make_False(bool & b){
	b = false;
	return b;
}
bool& Make_True(bool & b){
	b = true;
	return b;
}
bool& Yes(bool & b){
	b = true; return b;
}
bool& On(bool & b){
	b = true; return b;
}
bool& No(bool & b){
	b = false; return b;
}
bool& Off(bool & b){
	b = false; return b;
}
