void Sleep_For_N_Nanoseconds(unsigned int const& number_of_nanoseconds){
    std::this_thread::sleep_for(std::chrono::nanoseconds(number_of_nanoseconds));return;
}
void Sleep_For_N_Microseconds(unsigned int const& number_of_microseconds){
    std::this_thread::sleep_for(std::chrono::microseconds(number_of_microseconds));return;
}
void Sleep_For_N_Milliseconds(unsigned int const& number_of_milliseconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(number_of_milliseconds));return;
}
void Sleep_For_N_Seconds(unsigned int const& number_of_seconds){
    std::this_thread::sleep_for(std::chrono::seconds(number_of_seconds));return;
}
void Sleep_For_N_Minutes(unsigned int const& number_of_minutes){
    std::this_thread::sleep_for(std::chrono::minutes(number_of_minutes));return;
}
void Sleep_For_N_Hours(unsigned int const& number_of_hours){
    std::this_thread::sleep_for(std::chrono::hours(number_of_hours));return;
}
void Sleep_For_N_Days(unsigned int const& number_of_days){
    std::this_thread::sleep_for(std::chrono::duration<long long, std::ratio<86400>>(number_of_days));return;
}
void Sleep_For_N_Years(unsigned int const& number_of_years){
    std::this_thread::sleep_for(std::chrono::duration<long long, std::ratio<31557600>>(number_of_years));return;
    return;
}

void Wait_For_Directory_To_Exist_Emitting_A_Message_Each_Second(std::string directory_name, std::string wait_message, int seconds_to_sleep){
    while (!Directory_Exists(directory_name)){
      std::cout << wait_message;
      Sleep_For_N_Seconds(seconds_to_sleep);
  }
}
