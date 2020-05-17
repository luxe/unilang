/**
*    @file
*    @authors Trevor Hickey
*
*    @brief Utility functions Interface used by the Time Manager
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

#ifndef TimeUtilitiesH
#define TimeUtilitiesH

#include <time.h>

/**
*	@brief		Converts a generic time structure to a calendar time
*	@details 	time_t to tm
*   @param[In]	tTime	a generic time type
*   @return		struct tm	a calendar time
*/
struct tm ConvertTimeTypeToCalendarTimeType(time_t tTime);

/**
*	@brief		Converts a calendar time to a a generic time structure
*	@details 	tm to time_t
*   @param[In]	tTime	a calendar time
*   @return		time_t	a generic time type
*/
time_t ConvertCalendarTimeTypeToTimeType(struct tm tTime);

/**
*	@brief		Get the Current System Time as a generic time structure
*	@details 	uses localtime()
*   @return		time_t	a generic time type (will hold the current local time from the system)
*/
time_t CurrentTime(void);

/**
*	@brief		Get the Current System Time as a calendar time
*	@details 	uses localtime()
*   @return		struct tm	a calendar time (will hold the current local time from the system)
*/
struct tm CurrentCalendarTime(void);

#endif
///@}


