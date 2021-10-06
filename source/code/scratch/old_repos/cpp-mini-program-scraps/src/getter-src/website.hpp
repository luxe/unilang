#pragma once

/*
	 enumerated Website class
*/

#include <string>
enum class Website: char { INVALID
	,IDEONE
	,PASTE_BIN
};

/**
 * \brief converts a Website to a string representation.
 * 
 * the function takes any value of Website and returns the string representation of that value.
 * 
 * \param[in] enum_website the Website that is going to be used to get a corresponding string value.
 * 
 * \return a string representation of the Website passed in.
 * 
 * \sa C++11 enum classes
 * \note All values should be accounted for.  The string representation returned should be identical to the type value, except that it will be in lowercase.
 * \warning the Website has a value of INVALID, and the string representation will be "invalid" if it is passed in.
 */std::string to_string(Website const& enum_website);

/**
 * \brief sends a string representation of Website to an output stream
 * 
 * the function overloads the insertion operator for all classes of and deriving from ostream.
 * The string representation is sent into the stream.
 * 
 * \param[in] enum_website the Website that is going to be used to get a corresponding string value.
 * \param[out] out the stream which receives the string representation of Website
 * 
 * \return the output stream is returned with the the string value added.
 * 
 * \sa C++11 enum classes.  overloaded operators.  ostream.  insertion operator
 * \note All values should be accounted for.  The string representation returned should be identical to the type value, except that it will be in lowercase.
 * \warning the Website has a value of INVALID, and the string representation will be "invalid" if it is passed in.
 */std::ostream& operator << (std::ostream &out, Website const& enum_website);

/**
 * \brief converts a string representation of Website to the enumerated class value
 * 
 * the function takes a string representation of the enumerated class and converts it into the enumerated class value if possible
 * 
 * \param[in] std::string_website the Website that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 * 
 * \return the enumerated class value is returned.
 * 
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All string values should be accounted for.  The enum class representation returned should be identical to the string-- if the string is invalid, it will be matched with the INVALID type
 * \warning any string value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Website> Website enum_cast(std::string s){
	Website website{Website::INVALID};
	if (s == "ideone"){website = Website::IDEONE;}
	else if(s == "paste bin"){website = Website::PASTE_BIN;}
		return website;
}

/**
 * \brief converts an int representation of Website to the enumerated class value
 * 
 * the function takes an int representation of the enumerated class and converts it into the enumerated class value if possible
 * 
 * \param[in] intwebsite the Website that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 * 
 * \return the enumerated class value is returned.
 * 
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All int values in range will be accounted for.  The enum class representation returned should be should match the int as the placement of the enum class deceleration
 * \warning any int value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Website> Website enum_cast(int const& i){
	Website website{Website::INVALID};
	switch(i){
	case 0: return Website::IDEONE;
	case 1: return Website::PASTE_BIN;
	default:;
}		return website;
}

/**
 * \brief converts a char(char must be a number character) representation of Website to the enumerated class value
 * 
 * the function takes a char representation of the enumerated class and converts it into the enumerated class value if possible
 * 
 * \param[in] charwebsite the Website that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 * 
 * \return the enumerated class value is returned.
 * 
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All char values whose number value is in range will be accounted for.  The enum class representation returned should be should match the char numerical value as the placement of the enum class deceleration
 * \warning any char value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Website> Website enum_cast(char const& i){
	Website website{Website::INVALID};
	switch(i){
	case '0': return Website::IDEONE;
	case '1': return Website::PASTE_BIN;
	default:;
}		return website;
}
