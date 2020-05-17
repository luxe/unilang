#pragma once
#include "systems.hpp"
#include "utilities.hpp"

class Test{





public:


friend std::ostream &operator<<( std::ostream & out, Test const& self){
	return out;
}


private:

int x;
char i = 'd';


//❪❫ 	header includes
//⚯ 	header seperator for hpp and cpp
//⚞⚟ 	inheritence
//☀ 	start of function name
//◈ 	class name
//◀ ▶ 	header only
//◖ ◗ 	source only
//❰ ❱ 	function body
//ͼ ͽ shell command
// ፠ ፠ data member name
public: friend nlohmann::json As_JSON_Assignable(Test const& class_object);
};