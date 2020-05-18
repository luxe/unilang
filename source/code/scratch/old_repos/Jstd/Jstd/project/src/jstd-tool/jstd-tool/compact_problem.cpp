#include "compact_problem.hpp"

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
 */std::string to_string(Compact_Problem const& enum_compact_problem){
	std::string str{"INVALID"};
	switch (enum_compact_problem){
		case Compact_Problem::LEFT_SPACE: str = "left_space"; break;
		case Compact_Problem::RIGHT_SPACE: str = "right_space"; break;
		case Compact_Problem::MIDDLE_SPACE: str = "middle_space"; break;
		case Compact_Problem::CAPITAL_LETTERS: str = "capital_letters"; break;
		case Compact_Problem::INVALID_CHARACTERS: str = "invalid_characters"; break;
		case Compact_Problem::NO_VALID_CHARACTERS: str = "no_valid_characters"; break;
		default:;
	}
	return str;
}

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
 */std::ostream& operator << (std::ostream &out, Compact_Problem const& enum_compact_problem){
	out << to_string(enum_compact_problem);
	return out;
}