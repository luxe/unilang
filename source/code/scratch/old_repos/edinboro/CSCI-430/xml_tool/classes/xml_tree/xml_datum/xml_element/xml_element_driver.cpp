#include <iostream>
#include <cstdlib>
#include "xml_attribute/xml_attribute.h"
#include "xml_element.h"

int main(){
	using namespace std;
	
	std::vector<XML_AttributeT> attributes;
	std::string value1, value2;
	XML_AttributeT att{value1,value2};
	attributes.push_back(XML_AttributeT{"name1","value1"});
	attributes.push_back(XML_AttributeT{"name2","value2"});
	XML_ElementT e("start",attributes,false);
	cout << e << endl;
	
	return EXIT_SUCCESS;
}