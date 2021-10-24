#pragma once
#include <string>
std::string Date_As_Full_Month_Day_Year();


//let's say you want to simulate code in the past
//that used srand(time(null)) for random number generator.
//you can start at the specific year you think is appropriate and get that epoch
uint32_t epoch_time_for_year(int year);
uint32_t epoch_time_for_year_and_month(int year, int month);


std::string epoch_to_utc(uint32_t epoch);
