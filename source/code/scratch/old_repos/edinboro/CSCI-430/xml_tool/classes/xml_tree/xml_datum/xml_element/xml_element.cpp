#include "xml_element.h"

//Constructors
XML_ElementT::XML_ElementT(std::string const& tag_, std::vector<XML_AttributeT> const& attributes_, bool const& single_tag_)
: start_tag{tag_}
, attributes{attributes_}
, single_tag{single_tag_}
{}
XML_ElementT::XML_ElementT(void){}