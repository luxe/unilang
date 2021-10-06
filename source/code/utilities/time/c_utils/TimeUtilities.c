
#include "TimeUtilities.h"

struct tm ConvertTimeTypeToCalendarTimeType(time_t tTime)
{
    //to avoid all the memory management that the C time library imposes on you,
    //we handle the allocation and deallocation inside this conversion function.  
    //this allows use to convert between a time_t and a tm all while avoiding the heap outside of this function
    struct tm tReturnTime;
    struct tm *ptAllocatedCalendarTime = localtime(&tTime);
    
    //set this converted time to the outputs (assuming the tm is valid)
    if (ptAllocatedCalendarTime)
    {
        tReturnTime = *ptAllocatedCalendarTime;
    }
    
    //there is no need to relinquish the memory 
    //acquired during the conversion to local time because localtime
    //returns a pointer to statically allocated memory
    
    return tReturnTime;
}

time_t ConvertCalendarTimeTypeToTimeType(struct tm tTime)
{
  //use standard library function
  //although mktime is also used for time normalization, 
  //having a wrapper function makes some code more clear
  return mktime(&tTime);
}

time_t CurrentTime(void)
{
  //creates and returns a copy of the current time
  time_t tCurrentSimulationTime;
  time(&tCurrentSimulationTime);
  
  return tCurrentSimulationTime;
}

struct tm CurrentCalendarTime(void)
{
	//gets the current time as a time_t and performs the conversation to a tm
    return ConvertTimeTypeToCalendarTimeType(CurrentTime());
}
///@}


