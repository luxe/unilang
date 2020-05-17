#include "root.hpp"
#include <iostream>

class Test: public Root{

public:
	void Output(){
		std::cout << a << '\n';
		std::cout << b << '\n';
		std::cout << c << '\n';
		return;
	}

	void Add_To_All(){
		a+=1;
		b+="hi";
		c+=1.1;
		return;
	}


};