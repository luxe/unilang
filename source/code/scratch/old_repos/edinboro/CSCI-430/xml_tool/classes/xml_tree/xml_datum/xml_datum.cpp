#include "xml_datum.h"

//Constructors
XML_DatumT::XML_DatumT(XML_ElementT const& element_,std::string const& data_)
: element{element_}
, data{data_}
{}
XML_DatumT::XML_DatumT(void){}
