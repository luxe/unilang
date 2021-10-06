// Trevor Hickey
// Dan Bennett
// Program 2 (Time Keeper)
// 10-8-10
/*
Updates:
	10-11-2010: Added an if statement to properly output the total number of seconds
		    Declared constants for numbers 86400, 3600, and 60
*/

/* This program asks for a start time and an end time to be submited by the user
   and then calculates the two times to determine how long the user spent working on a particular activity */

#include <iostream>

using namespace std;

int main()
{
    //declares variables that hold time information from when the activity was started
    int startDay,
        startHour,
        startMinute,
        startSecond;

    //declares variables that hold time information from when the activity was finished
    int endDay,
        endHour,
        endMinute,
        endSecond;
    
    //declares variable constants that hold second breakdowns
    const int SECONDS_PER_DAY = 86400,
              SECONDS_PER_HOUR = 3600,
              SECONDS_PER_MINUTE = 60;

    //prompts user and stores values for the day, hour, minute, and second the activity was started.
    cout << endl;
    cout << "When you started the activity," << endl;
    cout << "What day of the year was it? (1 -365) ";
    cin >> startDay;
    cout << "What hour of that day was it? (0 -24) ";
    cin >> startHour;
    cout << "What minute of that hour was it? (0 - 59) ";
    cin >> startMinute;
    cout << "What second of that minute was it? (0 - 59) ";
    cin >> startSecond;
    cout << endl;

    //prompts user and stores values for the day, hour, minute, and second the activity was finnished.
    cout << "When you finished the activity," << endl;
    cout << "What day of the year was it? (1 -365) ";
    cin >> endDay;
    cout << "What hour of that day was it? (0 -24) ";
    cin >> endHour;
    cout << "What minute of that hour was it? (0 - 59) ";
    cin >> endMinute;
    cout << "What second of that minute was it? (0 - 59) ";
    cin >> endSecond;
    
    //converts start time into all seconds
    startSecond = (startDay * SECONDS_PER_DAY) + (startHour * SECONDS_PER_HOUR) + (startMinute * SECONDS_PER_MINUTE) + startSecond;

    //converts finnish time to all seconds
    endSecond = (endDay * SECONDS_PER_DAY) + (endHour * SECONDS_PER_HOUR) + (endMinute * SECONDS_PER_MINUTE) + endSecond;

    //calulates the total amount of seconds spent on the activity
    endSecond = endSecond - startSecond;

    //Displays results about how long the activity took to finnish in seconds
    cout << endl; 
    cout << "It took you " << endSecond << " second";
        if (endSecond != 1)
	{
	  cout << "s";
	}
    cout << " to finnish the activity!" <<endl;
    
    

    //converts the amount of seconds the activity took into days, hours, minutes, and seconds
    //finds out my days fit into the seconds
    endDay = endSecond / SECONDS_PER_DAY;

    //subtracts those seconds from the total
    endSecond = endSecond - (endDay*SECONDS_PER_DAY);

    //finds out my days fit into the seconds
    endHour = endSecond / SECONDS_PER_HOUR;

    //subtracts those seconds from the total
    endSecond = endSecond - (endHour*SECONDS_PER_HOUR);

    //finds out my minutes fit into the seconds
    endMinute = endSecond / SECONDS_PER_MINUTE;

    //subtracts those seconds from the total
    endSecond = endSecond - (endMinute*SECONDS_PER_MINUTE);

    //displays the amount of day(s) the activity took
    cout << "That's " << endDay << " day";
        if (endDay != 1)
	{
	  cout << "s";
	}

    //displays the amount of hour(s) the activity took
    cout << ", " << endHour << " hour";
        if (endHour != 1)
	{
	  cout << "s";
	}

    //displays the amount of minute(s) the activity took
    cout << ", " << endMinute << " minute";
        if (endMinute != 1)
	{
	  cout << "s";
	}

    //displays the amount of second(s) the activity took
    cout << ", and " << endSecond << " second";
        if (endSecond != 1)
	{
	  cout << "s";
	}
    cout << "!" << endl;
return 0;
}