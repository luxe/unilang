#include "code/utilities/types/strings/observers/char/lib.hpp"
#include "code/utilities/types/strings/transformers/trimming/lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include <cctype>

//apply character testing on all elements of string
bool Is_Only_Control_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Control_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Printable_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Printable_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Whitespace_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Whitespace_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Blank_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Blank_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Graphical_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Graphical_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Puncuation_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Puncuation_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Alphanumberic_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Alphanumberic_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Alpha_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Alpha_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Uppercase_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Uppercase_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Lowercase_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Lowercase_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Numeric_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Numeric_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Hexidecimal_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Hexidecimal_Character(it)){return false;}
    }
    return true;
}
bool Has_Only_Lowercase_Letters_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Lowercase_Character(it) && it != '_'){return false;}
    }
    return true;
}
bool Has_Only_Uppercase_Letters_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Uppercase_Character(it) && it != '_'){return false;}
    }
    return true;
}
bool Has_Only_Lowercase_Letters_Underscores_And_Forward_Slashes(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Lowercase_Character(it) && it != '_' && it != '/'){return false;}
    }
    return true;
}
bool Has_Only_Uppercase_Letters_Underscores_And_Forward_Slashes(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Uppercase_Character(it) && it != '_' && it != '/'){return false;}
    }
    return true;
}
bool Has_Only_Alpha_Letters_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Alpha_Character(it) && it != '_' ){return false;}
    }
    return true;	
}
bool Has_Only_Uppercase_Letters_Numbers_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Uppercase_Character(it) && it != '_' && !Is_A_Numeric_Character(it) ){return false;}
    }
    return true;
}

bool Has_Only_Alphanumeric_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Alphanumberic_Character(it) && it != '_' ){return false;}
    }
    return true;	
}

bool Starts_With_Digit(std::string const& str){
	if (!str.empty()){
		if (Is_A_Numeric_Character(str[0])){
			return true;
		}
	}
	return false;
}

//observing string functions
bool Consecutive_Space_In_The_Middle(std::string s) {

    trim(s);
    bool found = false;
    for (auto const& it: s) {
        if (it == ' ') {
            if (found) {
                return true;
            }
            found = true;
        }
        else{
            found = false;
        }
    }
    return false;
}
bool Contains_Capital_Letters(std::string const& s) {

    for (auto const& it: s) {
        if (std::isupper(it)) {
            return true;
        }
    }

    return false;
}
bool Contains_Character(std::string const& s, char const& c) {

    for (auto const& it: s) {
        if (it == c) {
            return true;
        }
    }
    return false;
}