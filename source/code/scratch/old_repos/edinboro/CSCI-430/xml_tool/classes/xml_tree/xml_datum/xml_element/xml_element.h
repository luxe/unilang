#pragma once
#ifndef XML_ELEMENTT_H
#define XML_ELEMENTT_H

#include <string>
#include <vector>
#include <iostream>
#include "xml_attribute/xml_attribute.h"

struct XML_ElementT{

	std::string start_tag;
	std::vector<XML_AttributeT> attributes;
	bool single_tag;
	
	//Constructors
	explicit XML_ElementT(std::string const& start_tag, std::vector<XML_AttributeT> const& attributes, bool const& single_tag);
	explicit XML_ElementT(void);
	
	//overloaded extraction operator
	friend std::ostream& operator << (std::ostream &out, XML_ElementT const& element){
		out << "<" << element.start_tag;
		for (std::size_t i = 0; i < element.attributes.size(); ++i){
			out << " " << element.attributes[i];
		}
		if (element.single_tag){
			out << " />";
		}else{
			out << ">";
		}
		
		return out;// << element.attributes[element.attributes.size()-1];
	}
	
};
#endif
