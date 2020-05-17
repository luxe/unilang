/**
*    @file
*    @authors Trevor Hickey
*
*    @brief Utility functions Definitions used by the Time Manager
*           and functions to receive the current local time in a variety of type formats
*
*    @details provides conversion functions for c library time types.
*             and functions to receive the current local time in a variety of type formats
*
*    @copyright Copyright 2015.
*    @n         Fidelity Flight Simulation, Inc. (F2Si)
*    @n         All rights reserved.
*
*    @b Classification:      Unclassified
*
*    @b Project @b Name:     UH-72A Synthetic Flight Training System (SFTS)
*
*    @b Contract @b Number:  #W900KK-09-D-0577
*
*    @b Task @b Order:       0002
*
*    This work was generated under U.S. Government contract and the
*    government has unlimited data rights therein.
*
*    @b DISTRIBUTION @b STATEMENT @b D:
*    @n    Distribution authorized to the Department of Defense and U.S. DoD contractors only.
*    @n    Other requests shall be referred to the controlling DoD office.
*
*    @b Organizations:
*    @n    Fidelity Flight Simulation, Inc. (F2Si)
*    @n    1815 Parkway View Drive
*    @n    Pittsburgh, PA 15205
*    @n    (412) 321-3280
*
*    @addtogroup Time_System
*    @{
*/

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


