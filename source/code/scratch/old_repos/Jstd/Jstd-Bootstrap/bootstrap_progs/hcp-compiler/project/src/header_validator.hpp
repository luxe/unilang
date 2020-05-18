#pragma once
#include "utilities.hpp"

class Header_Validator: public Non_Constructible{




public:

static void Validate(std::string const& class_name, std::wstring const& include_name_with_possible_quotes, bool const& is_header);


friend std::ostream &operator<<( std::ostream & out, Header_Validator const& self){
	return out;
}


private:
//❪❫ 	header includes
//⚯ 	header seperator for hpp and cpp
//⚞⚟ 	inheritence
//☀ 	start of function name
//◈ 	class name
//◀ ▶ 	header only
//◖ ◗ 	source only
//❰ ❱ 	function body
};