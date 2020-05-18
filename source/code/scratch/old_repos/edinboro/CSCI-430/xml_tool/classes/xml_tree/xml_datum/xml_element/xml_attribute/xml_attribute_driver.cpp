#include <iostream>
#include <cstdlib>
#include "xml_attribute.h"

int main(){
	using namespace std;
	
	XML_AttributeT a("name","value");
	cout << a << endl;
	
	return EXIT_SUCCESS;
}