#include "code/utilities/time/date/lib.hpp"
#include "code/utilities/time/calendar/tm_wrappers/lib.hpp"
#include "code/utilities/time/calendar/months/lib.hpp"
#include <string>

std::string Date_As_Full_Month_Day_Year()
{
	std::string str = Month_As_Full_Name();
	str += " ";
	str += std::to_string(Current_Month_Day());
	str += ", ";
	str += std::to_string(Current_Year());
	return str;
}