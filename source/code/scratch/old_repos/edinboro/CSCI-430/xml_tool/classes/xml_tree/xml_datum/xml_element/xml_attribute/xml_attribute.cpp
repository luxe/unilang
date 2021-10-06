#include "xml_attribute.h"

//Constructors
XML_AttributeT::XML_AttributeT(std::string const& tag_, std::string const& value_)
: tag{tag_}
, value{value_}
{}
XML_AttributeT::XML_AttributeT(void){}

