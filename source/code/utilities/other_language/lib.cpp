#include "code/utilities/other_language/lib.hpp"
#include "code/utilities/types/strings/transformers/trimming/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/types/strings/observers/other/lib.hpp"

bool Is_Header_Include_Line(std::string line){
	trim(line);
	if (Begins_With(line,"#include")){
		return true;
	}
	return false;
}

bool Is_System_Header_Include_Line(std::string line){
	std::string look_for = "#include";
	trim(line);
	if (Begins_With(line,look_for)){
		Remove_First_N_Chars(line,look_for.size());
		trim(line);
		if (Begins_With(line,"<")){
			return true;
		}
	}
	return false;
}

bool Is_Local_Header_Include_Line(std::string line){
	std::string look_for = "#include";
	trim(line);
	if (Begins_With(line,look_for)){
		Remove_First_N_Chars(line,look_for.size());
		trim(line);
		if (Begins_With(line,"\"")){
			return true;
		}
	}
	return false;
}
