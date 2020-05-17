#include "test.hpp"











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
nlohmann::json As_JSON_Assignable(test const& class_object){
	nlohmann::json j;
	j["x"] = As_JSON_Assignable(class_object.x);
	j["i"] = As_JSON_Assignable(class_object.i);
return j;
}