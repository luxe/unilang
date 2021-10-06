#pragma once

/*
	 enumerated Compact_Problem class
*/

#include <string>
enum class Compact_Problem: char { INVALID
	,LEFT_SPACE
	,RIGHT_SPACE
	,MIDDLE_SPACE
	,CAPITAL_LETTERS
	,INVALID_CHARACTERS
	,NO_VALID_CHARACTERS
};

/**
 * \brief converts a Compact_Problem to a string representation.
 * 
 * the function takes any value of Compact_Problem and returns the string representation of that value.
 * 
 * \param[in] enum_compact_problem the Compact_Problem that is going to be used to get a corresponding string value.
 * 
 * \return a string representation of the Compact_Problem passed in.
 * 
 * \sa C++11 enum classes
 * \note All values should be accounted for.  The string representation returned should be identical to the type value, except that it will be in lowercase.
 * \warning the Compact_Problem has a value of INVALID, and the string representation will be "invalid" if it is passed in.
 */std::string to_string(Compact_Problem const& enum_compact_problem);

/**
 * \brief sends a string representation of Compact_Problem to an output stream
 * 
 * the function overloads the insertion operator for all classes of and deriving from ostream.
 * The string representation is sent into the stream.
 * 
 * \param[in] enum_compact_problem the Compact_Problem that is going to be used to get a corresponding string value.
 * \param[out] out the stream which receives the string representation of Compact_Problem
 * 
 * \return the output stream is returned with the the string value added.
 * 
 * \sa C++11 enum classes.  overloaded operators.  ostream.  insertion operator
 * \note All values should be accounted for.  The string representation returned should be identical to the type value, except that it will be in lowercase.
 * \warning the Compact_Problem has a value of INVALID, and the string representation will be "invalid" if it is passed in.
 */std::ostream& operator << (std::ostream &out, Compact_Problem const& enum_compact_problem);

/**
 * \brief converts a string representation of Compact_Problem to the enumerated class value
 * 
 * the function takes a string representation of the enumerated class and converts it into the enumerated class value if possible
 * 
 * \param[in] std::string_compact_problem the Compact_Problem that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 * 
 * \return the enumerated class value is returned.
 * 
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All string values should be accounted for.  The enum class representation returned should be identical to the string-- if the string is invalid, it will be matched with the INVALID type
 * \warning any string value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Compact_Problem> Compact_Problem enum_cast(std::string s){
	Compact_Problem compact_problem{Compact_Problem::INVALID};
	if (s == "left_space"){compact_problem = Compact_Problem::LEFT_SPACE;}
	else if(s == "right_space"){compact_problem = Compact_Problem::RIGHT_SPACE;}
	else if(s == "middle_space"){compact_problem = Compact_Problem::MIDDLE_SPACE;}
	else if(s == "capital_letters"){compact_problem = Compact_Problem::CAPITAL_LETTERS;}
	else if(s == "invalid_characters"){compact_problem = Compact_Problem::INVALID_CHARACTERS;}
	else if(s == "no_valid_characters"){compact_problem = Compact_Problem::NO_VALID_CHARACTERS;}
		return compact_problem;
}

/**
 * \brief converts an int representation of Compact_Problem to the enumerated class value
 * 
 * the function takes an int representation of the enumerated class and converts it into the enumerated class value if possible
 * 
 * \param[in] intcompact_problem the Compact_Problem that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 * 
 * \return the enumerated class value is returned.
 * 
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All int values in range will be accounted for.  The enum class representation returned should be should match the int as the placement of the enum class deceleration
 * \warning any int value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Compact_Problem> Compact_Problem enum_cast(int const& i){
	Compact_Problem compact_problem{Compact_Problem::INVALID};
	switch(i){
	case 0: return Compact_Problem::LEFT_SPACE;
	case 1: return Compact_Problem::RIGHT_SPACE;
	case 2: return Compact_Problem::MIDDLE_SPACE;
	case 3: return Compact_Problem::CAPITAL_LETTERS;
	case 4: return Compact_Problem::INVALID_CHARACTERS;
	case 5: return Compact_Problem::NO_VALID_CHARACTERS;
	default:;
}		return compact_problem;
}

/**
 * \brief converts a char(char must be a number character) representation of Compact_Problem to the enumerated class value
 * 
 * the function takes a char representation of the enumerated class and converts it into the enumerated class value if possible
 * 
 * \param[in] charcompact_problem the Compact_Problem that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 * 
 * \return the enumerated class value is returned.
 * 
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All char values whose number value is in range will be accounted for.  The enum class representation returned should be should match the char numerical value as the placement of the enum class deceleration
 * \warning any char value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Compact_Problem> Compact_Problem enum_cast(char const& i){
	Compact_Problem compact_problem{Compact_Problem::INVALID};
	switch(i){
	case '0': return Compact_Problem::LEFT_SPACE;
	case '1': return Compact_Problem::RIGHT_SPACE;
	case '2': return Compact_Problem::MIDDLE_SPACE;
	case '3': return Compact_Problem::CAPITAL_LETTERS;
	case '4': return Compact_Problem::INVALID_CHARACTERS;
	case '5': return Compact_Problem::NO_VALID_CHARACTERS;
	default:;
}		return compact_problem;
}
