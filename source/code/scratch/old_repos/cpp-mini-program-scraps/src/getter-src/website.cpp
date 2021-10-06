#include "website.hpp"

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
 */std::string to_string(Website const& enum_website){
	std::string str{"INVALID"};
	switch (enum_website){
		case Website::IDEONE: str = "ideone"; break;
		case Website::PASTE_BIN: str = "paste bin"; break;
		default:;
	}
	return str;
}

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
 */std::ostream& operator << (std::ostream &out, Website const& enum_website){
	out << to_string(enum_website);
	return out;
}