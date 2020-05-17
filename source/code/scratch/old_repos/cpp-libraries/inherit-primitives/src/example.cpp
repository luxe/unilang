#include "inheritable_primitives.hpp"
#include <iostream>

class Class: public Inherit_From<int>{

	FULLY_MATCH_PRIMITIVE(Class,int)

	//here is an example of a function to change the primitive
	public: Class& add_four(){
		(*this)+=4;
		return *this;
	}

};

int main(){

	//although this is a user-defined type,
	//you will see that it behaves exactly like an int
	Class c = 0; //<- so here we declare basically an int which contains extra functionality

	//we can now use that extend functionality from the class
	std::cout << c.add_four().add_four() << std::endl; //outputs 8

	//we can still do all the normal things that ints can do
	std::cout << ++c << std::endl; //outputs 9

}
