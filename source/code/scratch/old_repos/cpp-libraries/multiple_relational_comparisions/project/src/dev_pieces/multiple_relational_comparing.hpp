#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
#include <tuple>
#include <cassert>
#include <algorithm>
#include <type_traits>

namespace multiple_relational_comparing_namespace{
#include "utilities.hpp"
#include "tuple_unrollers.hpp"
#include "overloaded_tuple_operators.hpp"
#include "overloaded_pair_operators.hpp"
}

//returns an OR-able tuple
template <typename... Args>
inline std::tuple <multiple_relational_comparing_namespace::OR_DISPATCH, Args...> Any_Of (Args&&... args){
    auto and_able_tuple = std::tuple <multiple_relational_comparing_namespace::OR_DISPATCH, Args...>
    (multiple_relational_comparing_namespace::OR_DISPATCH(), std::forward<Args>(args)...);

    //fail when zero parameters are passed
    static_assert(std::tuple_size<std::tuple <multiple_relational_comparing_namespace::OR_DISPATCH, Args...>>::value > 1,
    "\x1b[38;5;1mIt is invalid to pass 0 parameters to the Any_Of function\x1b[0m");

    #ifdef DEBUG_TRACE
    std::cout << "creates OR-able tuple\n";
    #endif

    return and_able_tuple;
}

//returns an AND-able tuple
template <typename... Args>
inline std::tuple <multiple_relational_comparing_namespace::AND_DISPATCH, Args...> All_Of (Args&&... args){
    auto or_able_tuple = std::tuple <multiple_relational_comparing_namespace::AND_DISPATCH, Args...>
    (multiple_relational_comparing_namespace::AND_DISPATCH(), std::forward<Args>(args)...);

    //fail when zero parameters are passed
    static_assert(std::tuple_size<std::tuple <multiple_relational_comparing_namespace::AND_DISPATCH, Args...>>::value > 1,
    "\x1b[38;5;1mIt is invalid to pass 0 parameters to the All_Of function\x1b[0m");

    #ifdef DEBUG_TRACE
    std::cout << "creates AND-able tuple\n";
    #endif

    return or_able_tuple;
}

//returns an NAND-able tuple
template <typename... Args>
inline std::tuple <multiple_relational_comparing_namespace::NAND_DISPATCH, Args...> None_Of (Args&&... args){
    auto or_able_tuple = std::tuple <multiple_relational_comparing_namespace::NAND_DISPATCH, Args...>
    (multiple_relational_comparing_namespace::NAND_DISPATCH(), std::forward<Args>(args)...);

    //fail when zero parameters are passed
    static_assert(std::tuple_size<std::tuple <multiple_relational_comparing_namespace::NAND_DISPATCH, Args...>>::value > 1,
    "\x1b[38;5;1mIt is invalid to pass 0 parameters to the None_Of function\x1b[0m");

    #ifdef DEBUG_TRACE
    std::cout << "creates NAND-able tuple\n";
    #endif

    return or_able_tuple;
}
