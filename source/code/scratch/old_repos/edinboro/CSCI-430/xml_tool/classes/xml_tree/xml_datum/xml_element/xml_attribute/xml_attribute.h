#pragma once
#ifndef XML_ATTRIBUTET_H
#define XML_ATTRIBUTET_H

#include <string>
#include <iostream>

struct XML_AttributeT{

	std::string tag;
	std::string value;

	//constructors
	explicit XML_AttributeT(std::string const& tag, std::string const& value);
	explicit XML_AttributeT(void);
	
	//overloaded extraction operator
	friend std::ostream& operator << (std::ostream &out, XML_AttributeT const& attribute){
		return out << attribute.tag << "=\"" << attribute.value << '"';
	}
};
#endif
