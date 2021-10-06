#include "address.hpp"

//Constructors
Address::Address(std::string address){
	value = stoul(address);
}

Address::Address(unsigned int const& address)
: value{address}
{}

Address& Address::operator= (std::string number){

	value = stoul(number);
	return *this;
}
Address& Address::operator= (unsigned int const& number){

	value = number;
	return *this;
}
Address::operator unsigned int () const{
	return value;
}

std::ostream& operator << (std::ostream &out, Address const& address){
	out << address.value;
	return out;
}
