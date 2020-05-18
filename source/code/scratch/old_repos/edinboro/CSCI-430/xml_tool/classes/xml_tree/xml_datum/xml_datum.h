#pragma once
#ifndef XML_DATUMT_H
#define XML_DATUMT_H

#include <string>
#include "xml_element/xml_element.h"

struct XML_DatumT{
	
	XML_ElementT element;
	std::string data;

	//Constructor
	explicit XML_DatumT(XML_ElementT const& element,std::string const& data);
	explicit XML_DatumT(void);
	
};
#endif
