#include "code/utilities/time/date/lib.hpp"
#include "code/utilities/time/calendar/tm_wrappers/lib.hpp"
#include "code/utilities/time/calendar/months/lib.hpp"
#include <string>
#include <time.h>

std::string Date_As_Full_Month_Day_Year()
{
	std::string str = Month_As_Full_Name();
	str += " ";
	str += std::to_string(Current_Month_Day());
	str += ", ";
	str += std::to_string(Current_Year());
	return str;
}


//https://www.epochconverter.com/
uint32_t epoch_time_for_year(int year){

    return epoch_time_for_year_and_month(year,0);
}

uint32_t epoch_time_for_year_and_month(int year, int month){

    struct tm t;
    time_t t_of_day;

    t.tm_year = year-1900;  // Year - 1900
    t.tm_mon = month;           // Month, where 0 = jan
    t.tm_mday = 0;          // Day of the month
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;        // Is DST on? 1 = yes, 0 = no, -1 = unknown
    t_of_day = mktime(&t);

    return (uint32_t ) t_of_day;
}

std::string epoch_to_utc(uint32_t epoch) {
  long temp = epoch;
  const time_t old = (time_t)temp;
  struct tm *oldt = gmtime(&old);
  return asctime(oldt);
}