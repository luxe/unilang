#pragma once

/*
	 enumerated Pre_Check class
*/

#include <string>
enum class Pre_Check: char { /*IN*/ INVALID
	/*SU*/,SUCCESS
	/*FA*/,FAILURE
	/*RU*/,RUN_TIME_ERROR
	/*TI*/,TIME_LIMIT_EXCEEDED
	/*ME*/,MEMORY_LIMIT
	/*IL*/,ILLEGAL_SYSTEM_CALL
	/*UN*/,UNKNOWN
};

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
 */std::string to_string(Pre_Check const& enum_pre_check);

/**
 * similar to the to_string function,  this just returns an abbreviation of the name.
 * I attach an abbreviation onto the file name,  so that other threads know what the web feeds
 * diagnostic of the file was
*/std::string as_abbreviation(Pre_Check const& enum_pre_check);
std::string abbreviation_to_word(std::string const& pre_check);

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
 */std::ostream& operator << (std::ostream &out, Pre_Check const& enum_pre_check);

/**
 * \brief converts a string representation of Pre_Check to the enumerated class value
 *
 * the function takes a string representation of the enumerated class and converts it into the enumerated class value if possible
 *
 * \param[in] std::string_pre_check the Pre_Check that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 *
 * \return the enumerated class value is returned.
 *
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All string values should be accounted for.  The enum class representation returned should be identical to the string-- if the string is invalid, it will be matched with the INVALID type
 * \warning any string value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Pre_Check> Pre_Check enum_cast(std::string s){
	Pre_Check pre_check{Pre_Check::INVALID};
	if (s == "success"){pre_check = Pre_Check::SUCCESS;}
	else if(s == "failure"){pre_check = Pre_Check::FAILURE;}
	else if(s == "run time error"){pre_check = Pre_Check::RUN_TIME_ERROR;}
	else if(s == "time limit exceeded"){pre_check = Pre_Check::TIME_LIMIT_EXCEEDED;}
	else if(s == "memory limit"){pre_check = Pre_Check::MEMORY_LIMIT;}
	else if(s == "illegal system call"){pre_check = Pre_Check::ILLEGAL_SYSTEM_CALL;}
	else if(s == "unknown"){pre_check = Pre_Check::UNKNOWN;}
		return pre_check;
}

/**
 * \brief converts an int representation of Pre_Check to the enumerated class value
 *
 * the function takes an int representation of the enumerated class and converts it into the enumerated class value if possible
 *
 * \param[in] intpre_check the Pre_Check that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 *
 * \return the enumerated class value is returned.
 *
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All int values in range will be accounted for.  The enum class representation returned should be should match the int as the placement of the enum class deceleration
 * \warning any int value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Pre_Check> Pre_Check enum_cast(int const& i){
	Pre_Check pre_check{Pre_Check::INVALID};
	switch(i){
	case 0: return Pre_Check::SUCCESS;
	case 1: return Pre_Check::FAILURE;
	case 2: return Pre_Check::RUN_TIME_ERROR;
	case 3: return Pre_Check::TIME_LIMIT_EXCEEDED;
	case 4: return Pre_Check::MEMORY_LIMIT;
	case 5: return Pre_Check::ILLEGAL_SYSTEM_CALL;
	case 6: return Pre_Check::UNKNOWN;
	default:;
}		return pre_check;
}

/**
 * \brief converts a char(char must be a number character) representation of Pre_Check to the enumerated class value
 *
 * the function takes a char representation of the enumerated class and converts it into the enumerated class value if possible
 *
 * \param[in] charpre_check the Pre_Check that is going to be used to get a corresponding enum class value.
 * \param[out] out none
 *
 * \return the enumerated class value is returned.
 *
 * \sa C++11 enum classes.  overloaded operators.  templates.
 * \note All char values whose number value is in range will be accounted for.  The enum class representation returned should be should match the char numerical value as the placement of the enum class deceleration
 * \warning any char value that does not correspond to an enumerated class value, will result in the INVALID enumerated class value returned.
 */template<Pre_Check> Pre_Check enum_cast(char const& i){
	Pre_Check pre_check{Pre_Check::INVALID};
	switch(i){
	case '0': return Pre_Check::SUCCESS;
	case '1': return Pre_Check::FAILURE;
	case '2': return Pre_Check::RUN_TIME_ERROR;
	case '3': return Pre_Check::TIME_LIMIT_EXCEEDED;
	case '4': return Pre_Check::MEMORY_LIMIT;
	case '5': return Pre_Check::ILLEGAL_SYSTEM_CALL;
	case '6': return Pre_Check::UNKNOWN;
	default:;
}		return pre_check;
}
