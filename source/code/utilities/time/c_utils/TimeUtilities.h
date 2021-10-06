#pragma once

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

