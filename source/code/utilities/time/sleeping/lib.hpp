#pragma once
#include <chrono>
#include <thread>
#include <gmpxx.h>
#include <iostream>

// sleep functions
void Sleep_For_N_Nanoseconds(unsigned int const& number_of_nanoseconds);
void Sleep_For_N_Microseconds(unsigned int const& number_of_microseconds);
void Sleep_For_N_Milliseconds(unsigned int const& number_of_milliseconds);
void Sleep_For_N_Seconds(unsigned int const& number_of_seconds);
void Sleep_For_N_Minutes(unsigned int const& number_of_minutes);
void Sleep_For_N_Hours(unsigned int const& number_of_hours);
void Sleep_For_N_Days(unsigned int const& number_of_days);
void Sleep_For_N_Years(unsigned int const& number_of_years);

template <typename Function>
auto Sleep_For_N_Nanoseconds_Then_Call_Function(unsigned int const& delay_amount, Function f) -> decltype(f) {
  Sleep_For_N_Nanoseconds(delay_amount);
  return f();
}

template <typename Function>
auto Sleep_For_N_Microseconds_Then_Call_Function(unsigned int const& delay_amount, Function f) -> decltype(f) {
  Sleep_For_N_Microseconds(delay_amount);
  return f();
}

template <typename Function>
auto Sleep_For_N_Milliseconds_Then_Call_Function(unsigned int const& delay_amount, Function f) -> decltype(f) {
  Sleep_For_N_Milliseconds(delay_amount);
  return f();
}

template <typename Function>
auto Sleep_For_N_Seconds_Then_Call_Function(unsigned int const& delay_amount, Function f) -> decltype(f) {
  Sleep_For_N_Seconds(delay_amount);
  return f();
}

template <typename Function>
auto Sleep_For_N_Minutes_Then_Call_Function(unsigned int const& delay_amount, Function f) -> decltype(f) {
  Sleep_For_N_Minutes(delay_amount);
  return f();
}

template <typename Function>
auto Sleep_For_N_Hours_Then_Call_Function(unsigned int const& delay_amount, Function f) -> decltype(f) {
  Sleep_For_N_Hours(delay_amount);
  return f();
}

template <typename Function>
auto Sleep_For_N_Days_Then_Call_Function(unsigned int const& delay_amount, Function f) -> decltype(f) {
  Sleep_For_N_Days(delay_amount);
  return f();
}

template <typename Function>
auto Sleep_For_N_Years_Then_Call_Function(unsigned int const& delay_amount, Function f) -> decltype(f) {
  Sleep_For_N_Years(delay_amount);
  return f();
}

//forever looping
template <typename Function, typename ShouldSkipFun>
void For_Every_N_Milliseconds_With_Exception_Catching(int mseconds, Function f, ShouldSkipFun should_exit){
  while (!should_exit()){
    
    try{
      f();
    }
    catch(std::exception const& e){
      std::cout << e.what() << std::endl;
    }
    Sleep_For_N_Milliseconds(mseconds);
  }
}

//nanosecond delay looping
template <typename Function>
void Repeat_N_Times_With_N_Nanosecond_Delay_In_Between(Function f, unsigned int amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Nanoseconds(delay_amount); amount -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Nanosecond_Delay_In_Between(Function f, std::string amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Nanoseconds(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Nanosecond_Delay_In_Between(Function f, const char* amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Nanoseconds(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Nanosecond_Delay_In_Between(Function f, mpz_class amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Nanoseconds(delay_amount); amount -= 1;}
  return;
}
//microsecond delay looping
template <typename Function>
void Repeat_N_Times_With_N_Microsecond_Delay_In_Between(Function f, unsigned int amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Microseconds(delay_amount); amount -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Microsecond_Delay_In_Between(Function f, std::string amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Microseconds(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Microsecond_Delay_In_Between(Function f, const char* amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Microseconds(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Microsecond_Delay_In_Between(Function f, mpz_class amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Microseconds(delay_amount); amount -= 1;}
  return;
}
//millisecond delay looping
template <typename Function>
void Repeat_N_Times_With_N_Millisecond_Delay_In_Between(Function f, unsigned int amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Milliseconds(delay_amount); amount -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Millisecond_Delay_In_Between(Function f, std::string amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Milliseconds(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Millisecond_Delay_In_Between(Function f, const char* amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Milliseconds(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Millisecond_Delay_In_Between(Function f, mpz_class amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Milliseconds(delay_amount); amount -= 1;}
  return;
}
//second delay looping
template <typename Function>
void Repeat_N_Times_With_N_Second_Delay_In_Between(Function f, unsigned int amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Seconds(delay_amount); amount -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Second_Delay_In_Between(Function f, std::string amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Seconds(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Second_Delay_In_Between(Function f, const char* amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Seconds(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Second_Delay_In_Between(Function f, mpz_class amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Seconds(delay_amount); amount -= 1;}
  return;
}
//minute delay looping
template <typename Function>
void Repeat_N_Times_With_N_Minute_Delay_In_Between(Function f, unsigned int amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Minutes(delay_amount); amount -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Minute_Delay_In_Between(Function f, std::string amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Minutes(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Minute_Delay_In_Between(Function f, const char* amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Minutes(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Minute_Delay_In_Between(Function f, mpz_class amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Minutes(delay_amount); amount -= 1;}
  return;
}
//hour delay looping
template <typename Function>
void Repeat_N_Times_With_N_Hour_Delay_In_Between(Function f, unsigned int amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Hours(delay_amount); amount -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Hour_Delay_In_Between(Function f, std::string amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Hours(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Hour_Delay_In_Between(Function f, const char* amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Hours(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Hour_Delay_In_Between(Function f, mpz_class amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Hours(delay_amount); amount -= 1;}
  return;
}
//day delay looping
template <typename Function>
void Repeat_N_Times_With_N_Day_Delay_In_Between(Function f, unsigned int amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Days(delay_amount); amount -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Day_Delay_In_Between(Function f, std::string amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Days(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Day_Delay_In_Between(Function f, const char* amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Days(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Day_Delay_In_Between(Function f, mpz_class amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Days(delay_amount); amount -= 1;}
  return;
}
//year delay looping
template <typename Function>
void Repeat_N_Times_With_N_Year_Delay_In_Between(Function f, unsigned int amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Years(delay_amount); amount -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Year_Delay_In_Between(Function f, std::string amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Years(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Year_Delay_In_Between(Function f, const char* amount, unsigned int const& delay_amount) {
  mpz_class i (amount);
    while (i > 0) {f(); Sleep_For_N_Years(delay_amount); i -= 1;}
  return;
}
template <typename Function>
void Repeat_N_Times_With_N_Year_Delay_In_Between(Function f, mpz_class amount, unsigned int const& delay_amount) {
    while (amount > 0) {f(); Sleep_For_N_Years(delay_amount); amount -= 1;}
  return;
}

void Wait_For_Directory_To_Exist_Emitting_A_Message_Each_Second(std::string directory_name, std::string wait_message, int seconds_to_sleep);
