#pragma once
#include <iostream>
#include <type_traits>

template<typename T>
using unmodified_type_t = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
