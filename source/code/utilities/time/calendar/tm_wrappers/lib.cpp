#include "code/utilities/time/calendar/tm_wrappers/lib.hpp"
#include <chrono>
#include <ctime>

size_t Time_Since_Epoch(){
    auto now = std::chrono::system_clock::now();
    return now.time_since_epoch().count();
}

//struct tm wrappers
unsigned int Current_Second(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    return parts->tm_sec+1;
}
unsigned int Current_Minute(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    return parts->tm_min+1;
}
unsigned int Current_Hour(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    return parts->tm_hour+1;
}
unsigned int Current_Month_Day(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    return parts->tm_mday;
}
unsigned int Current_Month(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    return parts->tm_mon + 1;
}
unsigned int Current_Year(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    return parts->tm_year + 1900;
}
unsigned int Current_Day_Of_Week(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    
    //return 7 for sunday
    if (parts->tm_wday == 0){
        return 7;
    }
    
    //(mon - sat) == (1 - 6)
    return parts->tm_wday;
}

unsigned int Current_Day_Of_Year(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    return parts->tm_yday + 1;
}