#pragma once
#include <string>
#include <gmpxx.h>

//basic constructs
template <typename Boolean_Expression, typename Function>
void While(Boolean_Expression b, Function f){
  while (b) { f(); }
}
template <typename Boolean_Expression, typename Function>
void Do_While(Boolean_Expression b, Function f){
  do { f(); } while(b);
}

template <typename Function>
void Repeat_Forever(Function f) {
    while (true) {f();}
}

template <typename Container, typename Function>
void For_Each_Index(Container const& c, Function f){
    for (size_t i = 0; i < c.size(); ++i){
        f(i);
    }
}
template <typename Container, typename Function>
void For_Each_Index_Backward(Container const& c, Function f){
    if (c.empty()){
        return;
    }
    for (size_t i = c.size()-1; i >= 0; --i){
        f(i);
    }
}


template <typename Container, typename Predicate, typename Function>
void Once_Index_Predicate_Forward(Container const& c, Predicate p, Function f){
    for (size_t i = 0; i < c.size(); ++i){
        if (p(i)){
            f(i);
            break;
        }
    }
}
template <typename Container, typename Predicate, typename Function>
void Once_Index_Predicate_Backward(Container const& c, Predicate p, Function f){
    for (size_t i = c.size()-1; i >= 0; --i){
        if (p(i)){
            f(i);
            break;
        }
    }
}

//looping n times

//when you don't actually care about the index, 
//use this to replace most for loops that iterate an n number of times
template <typename Function>
void repeat(Function f, unsigned int amount) {
    while (amount > 0) {f(); amount -= 1;}
    return;
}

//uses string and in term gmp library
template <typename Function>
void repeat(Function f, std::string amount) {
    mpz_class i (amount);
    while (i > 0) {f(); i -= 1;}
    return;
}

//uses char
template <typename Function>
void repeat(Function f, const char* amount) {
    mpz_class i (amount);
    while (i > 0) {f(); i -= 1;}
    return;
}

//uses gmp library
template <typename Function>
void repeat(Function f, mpz_class amount) {
    while (amount > 0) {f(); amount -= 1;}
    return;
}
template <typename Function>
void repeat(mpz_class amount, Function f) {
    while (amount > 0) {f(); amount -= 1;}
    return;
}

template <typename T, typename F>
T& Transform(T & vec, F const& func){
	for (auto & it: vec){
		func(it);
	}
	return vec;
}
