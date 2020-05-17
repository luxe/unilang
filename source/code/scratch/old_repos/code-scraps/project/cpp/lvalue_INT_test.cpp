#include <iostream>

struct Int {

	//constructors
	Int(int const& num) :m_num(num) {}
	Int(Int const& rhs){m_num = rhs.m_num;}

	//Arithmetic Operators
	/*plus*/ Int operator+(Int const& rhs) {return Int(m_num+rhs.m_num);}
	/*pre*/  Int& operator++() {++m_num; return *this;}
	/*post*/ Int operator++(int) {Int copy(m_num); ++m_num; return copy;}
	// ...

	//evaluate to an int when needed
	operator int() {return m_num;}

	//making this fundamental type a compound type (more or less)
	int m_num;

};

int main() {

	//declaring ints *wink*
	Int x = 1;
	Int y = 1;

	//a copy of the incremented expression
	//gets returned so we can't access the value
	//influenced by the postfix operator
	std::cout << (x+y)++ <<  '\n';

	//a more logical example, which would be
	//the prefix increment because we can still
	//grab the incremented value
	Int z = ++(x+y);
	std::cout << z <<  '\n';
}
