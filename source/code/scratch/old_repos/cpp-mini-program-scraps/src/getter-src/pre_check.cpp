#include "pre_check.hpp"

/**
 * \brief converts a Pre_Check to a string representation.
 *
 * the function takes any value of Pre_Check and returns the string representation of that value.
 *
 * \param[in] enum_pre_check the Pre_Check that is going to be used to get a corresponding string value.
 *
 * \return a string representation of the Pre_Check passed in.
 *
 * \sa C++11 enum classes
 * \note All values should be accounted for.  The string representation returned should be identical to the type value, except that it will be in lowercase.
 * \warning the Pre_Check has a value of INVALID, and the string representation will be "invalid" if it is passed in.
 */std::string to_string(Pre_Check const& enum_pre_check){
	std::string str{"INVALID"};
	switch (enum_pre_check){
		case Pre_Check::SUCCESS: str = "success"; break;
		case Pre_Check::FAILURE: str = "failure"; break;
		case Pre_Check::RUN_TIME_ERROR: str = "run time error"; break;
		case Pre_Check::TIME_LIMIT_EXCEEDED: str = "time limit exceeded"; break;
		case Pre_Check::MEMORY_LIMIT: str = "memory limit"; break;
		case Pre_Check::ILLEGAL_SYSTEM_CALL: str = "illegal system call"; break;
		case Pre_Check::UNKNOWN: str = "unknown"; break;
		default:;
	}
	return str;
}
//I - Invalid
//S - Success
//F - Failure
//SE - Success (with runtime error)
//SL - Success (with time out)
//U - Unknown (web feed does not test compiles.. or something else went wrong)
std::string as_abbreviation(Pre_Check const& enum_pre_check){
	std::string str{"IN"};
	switch (enum_pre_check){
		case Pre_Check::SUCCESS: str = "SU"; break;
		case Pre_Check::FAILURE: str = "FA"; break;
		case Pre_Check::RUN_TIME_ERROR: str = "RU"; break;
		case Pre_Check::TIME_LIMIT_EXCEEDED: str = "TI"; break;
		case Pre_Check::MEMORY_LIMIT: str = "ME"; break;
		case Pre_Check::ILLEGAL_SYSTEM_CALL: str = "IL"; break;
		case Pre_Check::UNKNOWN: str = "UN"; break;
		default:;
	}
	return str;
}
std::string abbreviation_to_word(std::string const& pre_check){

	std::string str{"INVALID"};
	if (pre_check == "SU") { str = "SUCCESS";}
	else if (pre_check == "FA") {str = "FAILURE";}
	else if (pre_check == "RU") {str = "SUCCESS BUT WITH RUNTIME ERROR";}
	else if (pre_check == "TI") {str = "SUCCESS WITH TIME OUT";}
	else if (pre_check == "ME") {str = "SUCCESS WITH MEMORY LIMIT ERROR";}
	else if (pre_check == "IL") {str = "SUCCESS WITH ILLEGAL SYSTEM CALL";}
	else if (pre_check == "UN") {str = "UNKNOWN";}

	return str;
}

/**
 * \brief sends a string representation of Pre_Check to an output stream
 *
 * the function overloads the insertion operator for all classes of and deriving from ostream.
 * The string representation is sent into the stream.
 *
 * \param[in] enum_pre_check the Pre_Check that is going to be used to get a corresponding string value.
 * \param[out] out the stream which receives the string representation of Pre_Check
 *
 * \return the output stream is returned with the the string value added.
 *
 * \sa C++11 enum classes.  overloaded operators.  ostream.  insertion operator
 * \note All values should be accounted for.  The string representation returned should be identical to the type value, except that it will be in lowercase.
 * \warning the Pre_Check has a value of INVALID, and the string representation will be "invalid" if it is passed in.
 */std::ostream& operator << (std::ostream &out, Pre_Check const& enum_pre_check){
	out << to_string(enum_pre_check);
	return out;
}
