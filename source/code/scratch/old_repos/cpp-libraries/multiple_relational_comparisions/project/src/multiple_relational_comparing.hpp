#pragma once
#include <tuple>
#include <cassert>
#include <algorithm>
#include <type_traits>

namespace multiple_relational_comparing_namespace{
//DISPATCH TYPES:
//unique tuple identification types
//we attach this as a first element to a tuple to distinguish between them and provide specific functionality
//this is also used to keep other tuples from not being canidates to this library's global overloaded operator functions
struct AND_DISPATCH  {};
struct OR_DISPATCH   {};
struct NAND_DISPATCH {};

//comparison type order
struct T_VS_TUPLE_DISPATCH {};
struct TUPLE_VS_T_DISPATCH {};

//why don't we just use std::pair?
//because it has global overloaded operators that don't work the way we want them too, and will cause ambiguity errors later
template <typename A, typename B>
struct dispatch_pair{dispatch_pair(A a, B b):first(a), second(b){}A first; B second;};

//remove the const and remove the reference from the type
//this will remove an lvalue as well as an rvalue reference
template<typename T>
using unmodified_type_t = typename std::remove_cv<typename std::remove_reference<T>::type>::type;


//determine if a type has constant iterators
template<typename T>
struct has_const_iterator{
private:
    typedef char                      yes;
    typedef struct { char array[2]; } no;

    template<typename C> static yes test(typename C::const_iterator*);
    template<typename C> static no  test(...);
public:
    static const bool value = sizeof(test<T>(0)) == sizeof(yes);
    typedef T type;
};

//determine if a type has begin and end iterators
template <typename T>
struct has_begin_end{
  template<typename C> static char (&f(typename std::enable_if<
    std::is_same<decltype(static_cast<typename C::const_iterator (C::*)() const>(&C::begin)),
    typename C::const_iterator(C::*)() const>::value, void>::type*))[1];
  template<typename C> static char (&f(...))[2];
  template<typename C> static char (&g(typename std::enable_if<
    std::is_same<decltype(static_cast<typename C::const_iterator (C::*)() const>(&C::end)),
    typename C::const_iterator(C::*)() const>::value, void>::type*))[1];
  template<typename C> static char (&g(...))[2];
  static bool const beg_value = sizeof(f<T>(0)) == 1;
  static bool const end_value = sizeof(g<T>(0)) == 1;
};

//determine if a type is iterable
//(ensures that the type has constant iterators as well as begin and end functions)
template<typename T>
struct is_iterable : std::integral_constant
<bool, has_const_iterator<unmodified_type_t<T>>::value && has_begin_end<unmodified_type_t<T>>::beg_value && has_begin_end<unmodified_type_t<T>>::end_value>{};

//we'll add the not_iterable for convenience
template<typename T>
struct is_not_iterable : std::integral_constant
<bool, !(has_const_iterator<unmodified_type_t<T>>::value && has_begin_end<unmodified_type_t<T>>::beg_value && has_begin_end<unmodified_type_t<T>>::end_value)>{};

//C++11 doesn't have self deducing type function objects, but C++14 does.
//These function objects in C++14 don't require any additional language features that C++11 lacks.
//Therefore, they can be added in C++11 as well.  Since I'm trying to make this library work for C++11,
//as well as C++14, I will re-implement this portion of the C++14 std library.
//equal_to
template <typename T = void> struct equal_to;
template<typename T> struct equal_to{ bool operator()(const T& a, const T& b) const { return a == b; }};
template<>
struct equal_to<void>{
    template <typename T, typename _Up>
    auto operator()(T&& __t, _Up&& __u) const
  noexcept(noexcept(std::forward<T>(__t) == std::forward<_Up>(__u))) -> decltype(std::forward<T>(__t) == std::forward<_Up>(__u))
  { return std::forward<T>(__t) == std::forward<_Up>(__u); }
};

//not_equal_to
template <typename T = void> struct not_equal_to;
template<typename T> struct not_equal_to{bool operator()(const T& a, const T& b) const { return a != b; }};
template<>
struct not_equal_to<void>{
    template <typename T, typename _Up>
    auto operator()(T&& __t, _Up&& __u) const
  noexcept(noexcept(std::forward<T>(__t) != std::forward<_Up>(__u))) -> decltype(std::forward<T>(__t) != std::forward<_Up>(__u))
  { return std::forward<T>(__t) != std::forward<_Up>(__u); }
};

//less
template <typename T = void> struct less;
template<typename T> struct less{bool operator()(const T& a, const T& b) const { return a < b; }};
template<>
struct less<void>{
    template <typename T, typename _Up>
    auto operator()(T&& __t, _Up&& __u) const
  noexcept(noexcept(std::forward<T>(__t) < std::forward<_Up>(__u))) -> decltype(std::forward<T>(__t) < std::forward<_Up>(__u))
  { return std::forward<T>(__t) < std::forward<_Up>(__u); }
};

//greater
template <typename T = void> struct greater;
template<typename T> struct greater{bool operator()(const T& a, const T& b) const { return a > b; }};
template<>
struct greater<void>{
    template <typename T, typename _Up>
    auto operator()(T&& __t, _Up&& __u) const
  noexcept(noexcept(std::forward<T>(__t) > std::forward<_Up>(__u))) -> decltype(std::forward<T>(__t) > std::forward<_Up>(__u))
  { return std::forward<T>(__t) > std::forward<_Up>(__u); }
};

//greater_equal
template <typename T = void> struct greater_equal;
template<typename T> struct greater_equal{bool operator()(const T& a, const T& b) const { return a >= b; }};
template<>
struct greater_equal<void>{
    template <typename T, typename _Up>
    auto operator()(T&& __t, _Up&& __u) const
  noexcept(noexcept(std::forward<T>(__t) >= std::forward<_Up>(__u))) -> decltype(std::forward<T>(__t) >= std::forward<_Up>(__u))
  { return std::forward<T>(__t) >= std::forward<_Up>(__u); }
};

//less_equal
template <typename T = void> struct less_equal;
template<typename T> struct less_equal{bool operator()(const T& a, const T& b) const { return a <= b; }};
template<>
struct less_equal<void>{
    template <typename T, typename _Up>
    auto operator()(T&& __t, _Up&& __u) const
  noexcept(noexcept(std::forward<T>(__t) <= std::forward<_Up>(__u))) -> decltype(std::forward<T>(__t) <= std::forward<_Up>(__u))
  { return std::forward<T>(__t) <= std::forward<_Up>(__u); }
};
//logical_and
template <typename T = void> struct logical_and;
template<typename T> struct logical_and{ bool operator()(const T& a, const T& b) const { return a && b; }};
template<>
struct logical_and<void>{
    template <typename T, typename _Up>
    auto operator()(T&& __t, _Up&& __u) const
  noexcept(noexcept(std::forward<T>(__t) && std::forward<_Up>(__u))) -> decltype(std::forward<T>(__t) && std::forward<_Up>(__u))
  { return std::forward<T>(__t) && std::forward<_Up>(__u); }
};
//logical_or
template <typename T = void> struct logical_or;
template<typename T> struct logical_or{ bool operator()(const T& a, const T& b) const { return a || b; }};
template<>
struct logical_or<void>{
    template <typename T, typename _Up>
    auto operator()(T&& __t, _Up&& __u) const
  noexcept(noexcept(std::forward<T>(__t) || std::forward<_Up>(__u))) -> decltype(std::forward<T>(__t) || std::forward<_Up>(__u))
  { return std::forward<T>(__t) || std::forward<_Up>(__u); }
};
//logical_nand
template <typename T = void> struct logical_nand;
template<typename T> struct logical_nand{ bool operator()(const T& a, const T& b) const { return !(a && b); }};
template<>
struct logical_nand<void>{
    template <typename T, typename _Up>
    auto operator()(T&& __t, _Up&& __u) const
  noexcept(noexcept(!(std::forward<T>(__t) && std::forward<_Up>(__u)))) -> decltype(!(std::forward<T>(__t) && std::forward<_Up>(__u)))
  { return !(std::forward<T>(__t) && std::forward<_Up>(__u)); }
};

//a struct to evaluate Tuples and Ts
template <class Compare_Operation, class X, class Tuple, size_t Index, size_t ReverseIndex>
struct Tuple_And_T_Comparer
{

  //T VS TUPLE
  static bool  compare (const X& x, const Tuple& tuple, OR_DISPATCH const& bo, T_VS_TUPLE_DISPATCH const& order){
      return Compare_Operation()(
      dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x),
      dispatch_pair<OR_DISPATCH,decltype(std::get<Index>(tuple))>(OR_DISPATCH(),std::get<Index>(tuple)))
  || Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order);
  }
  static bool compare (const X& x, const Tuple& tuple, AND_DISPATCH const& bo, T_VS_TUPLE_DISPATCH const& order){
      return Compare_Operation()(
      dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x),
      dispatch_pair<AND_DISPATCH,decltype(std::get<Index>(tuple))>(AND_DISPATCH(),std::get<Index>(tuple)))
  && Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order);
  }
  static bool compare (const X& x, const Tuple& tuple, NAND_DISPATCH const& bo, T_VS_TUPLE_DISPATCH const& order){
      return Compare_Operation()(
      dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x),
      dispatch_pair<NAND_DISPATCH,decltype(std::get<Index>(tuple))>(NAND_DISPATCH(),std::get<Index>(tuple)))
  && Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order);
  }

  //TUPLE VS T
  static bool compare (const X& x, const Tuple& tuple, OR_DISPATCH const& bo, TUPLE_VS_T_DISPATCH const& order){
      return Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order)
  || Compare_Operation()(
  dispatch_pair<OR_DISPATCH,decltype(std::get<Index>(tuple))>(OR_DISPATCH(),std::get<Index>(tuple)),
  dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x)
  );
  }
  static bool compare (const X& x, const Tuple& tuple, AND_DISPATCH const& bo, TUPLE_VS_T_DISPATCH const& order){
      return Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order)
  && Compare_Operation()(
  dispatch_pair<AND_DISPATCH,decltype(std::get<Index>(tuple))>(AND_DISPATCH(),std::get<Index>(tuple)),
  dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x)
  );
  }
  static bool compare (const X& x, const Tuple& tuple, NAND_DISPATCH const& bo, TUPLE_VS_T_DISPATCH const& order){
      return Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order)
  && Compare_Operation()(
  dispatch_pair<NAND_DISPATCH,decltype(std::get<Index>(tuple))>(NAND_DISPATCH(),std::get<Index>(tuple)),
  dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x)
  );
  }

};

//base case when we hit zero elements in the tuple
template <class Compare_Operation, class X, class Tuple, size_t Index>
struct Tuple_And_T_Comparer <Compare_Operation, X, Tuple, Index, 0>
{

  template <typename ORDER>
  static bool compare (const X& x, const Tuple& tuple, AND_DISPATCH const& BO, ORDER const& order){
    return true;
  }
  template <typename ORDER>
  static bool compare (const X& x, const Tuple& tuple, NAND_DISPATCH const& BO, ORDER const& order){
    return true;
  }
  template <typename ORDER>
  static bool compare (const X& x, const Tuple& tuple, OR_DISPATCH const& BO, ORDER const& order){
    return false;
  }

};
//a struct to evaluate Tuples and Tuples
template <class Compare_Operation, class Left, size_t Left_Index, size_t Left_ReverseIndex, class Right, size_t Right_Index, size_t RightReverseIndex>
struct Tuple_And_Tuple_Comparer{

  static bool compare (Left const& left, Right const& right, OR_DISPATCH const& bo_left, OR_DISPATCH const& bo_right){
    auto result = Compare_Operation()
    (
    dispatch_pair<OR_DISPATCH,decltype(std::get<Left_Index>(left))>(OR_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<OR_DISPATCH,decltype(std::get<Right_Index>(right))>(OR_DISPATCH(),std::get<Right_Index>(right))
    ) || Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result || Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, OR_DISPATCH const& bo_left, AND_DISPATCH const& bo_right){
    auto result = Compare_Operation()
    (
    dispatch_pair<OR_DISPATCH,decltype(std::get<Left_Index>(left))>(OR_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<AND_DISPATCH,decltype(std::get<Right_Index>(right))>(AND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result || Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, OR_DISPATCH const& bo_left, NAND_DISPATCH const& bo_right){
    auto result = (Compare_Operation()
    (
    dispatch_pair<OR_DISPATCH,decltype(std::get<Left_Index>(left))>(OR_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Right_Index>(right))>(NAND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH()));
    return result || Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }
  static bool compare (Left const& left, Right const& right, AND_DISPATCH const& bo_left, OR_DISPATCH const& bo_right){
    auto result = Compare_Operation()
    (
    dispatch_pair<AND_DISPATCH,decltype(std::get<Left_Index>(left))>(AND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<OR_DISPATCH,decltype(std::get<Right_Index>(right))>(OR_DISPATCH(),std::get<Right_Index>(right))
    ) || Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, AND_DISPATCH const& bo_left, AND_DISPATCH const& bo_right){
    auto result = Compare_Operation()
    (
    dispatch_pair<AND_DISPATCH,decltype(std::get<Left_Index>(left))>(AND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<AND_DISPATCH,decltype(std::get<Right_Index>(right))>(AND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, AND_DISPATCH const& bo_left, NAND_DISPATCH const& bo_right){
    auto result = (Compare_Operation()
    (
    dispatch_pair<AND_DISPATCH,decltype(std::get<Left_Index>(left))>(AND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Right_Index>(right))>(NAND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH()));
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, NAND_DISPATCH const& bo_left, OR_DISPATCH const& bo_right){
    auto result = Compare_Operation()
    (
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Left_Index>(left))>(NAND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<OR_DISPATCH,decltype(std::get<Right_Index>(right))>(OR_DISPATCH(),std::get<Right_Index>(right))
    ) || Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, NAND_DISPATCH const& bo_left, AND_DISPATCH const& bo_right){
    auto result = Compare_Operation()
    (
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Left_Index>(left))>(NAND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<AND_DISPATCH,decltype(std::get<Right_Index>(right))>(AND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, NAND_DISPATCH const& bo_left, NAND_DISPATCH const& bo_right){
    auto result = Compare_Operation()
    (
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Left_Index>(left))>(NAND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Right_Index>(right))>(NAND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

};

//base case
template <class Compare_Operation, class Left, size_t Left_Index, class Right, size_t Right_Index, size_t Right_ReverseIndex>
struct Tuple_And_Tuple_Comparer <Compare_Operation, Left, Left_Index, 0, Right, Right_Index, Right_ReverseIndex>{

  template <typename BO_RIGHT>
  static bool compare (Left const& left, Right const& right, OR_DISPATCH const& bo_left, BO_RIGHT const& bo_right){
    return false;
  }
  template <typename BO_RIGHT>
  static bool compare (Left const& left, Right const& right, AND_DISPATCH const& bo_left, BO_RIGHT const& bo_right){
    return true;
  }
  template <typename BO_RIGHT>
  static bool compare (Left const& left, Right const& right, NAND_DISPATCH const& bo_left, BO_RIGHT const& bo_right){
    return true;
  }
};
//TUPLE VS T
template <typename X, typename OP, typename... Args>
bool operator == (std::tuple<OP, Args...> const& any, X const& x){
 typedef std::tuple <OP, Args...> tuple;
 return Tuple_And_T_Comparer
 <equal_to<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator != (std::tuple<OP, Args...> const& any, X const& x){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <not_equal_to<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator > (std::tuple<OP, Args...> const& any, X const& x){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <greater<>, X, tuple,1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator < (std::tuple<OP, Args...> const& any, X const& x){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <less<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator >= (std::tuple<OP, Args...> const& any, X const& x){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <greater_equal<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator <= (std::tuple<OP, Args...> const& any, X const& x){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <less_equal<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}

//T VS TUPLE
template <typename X, typename OP, typename... Args>
bool operator == (X const& x, std::tuple<OP, Args...> const& any){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <equal_to<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator != (X const& x, std::tuple<OP, Args...> const& any){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <not_equal_to<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator > (X const& x, std::tuple<OP, Args...> const& any){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <greater<>, X, tuple,1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator < (X const& x, std::tuple<OP, Args...> const& any){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <less<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator >= (X const& x, std::tuple<OP, Args...> const& any){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <greater_equal<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator <= (X const& x, std::tuple<OP, Args...> const& any){
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <less_equal<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}

//TUPLE VS TUPLE
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator == (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <equal_to<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator != (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <not_equal_to<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator > (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <greater<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator < (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <less<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator >= (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <greater_equal<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator <= (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <less_equal<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) == y;
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) == y;
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) == y);
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) == y;
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) == y;
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) == y);
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) == y;
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) == y;
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) == y);
  });
}


//+---------------+
//|   ITERABLE    |
//+---------------+
//|  NO   |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
 return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x == dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x == dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x == dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x == dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x == dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x == dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x == dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x == dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x == dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i));
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
   return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) == dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
  });
 });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) == dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) == dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) == dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) == dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) == dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) == dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) == dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) == dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+ this is the base case out of pair comparisons
//|  NO   |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second == y.second;
}
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second == y.second;
}
template <typename X, typename Y>
auto operator == (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second == y.second);
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second == y.second;
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second == y.second;
}
template <typename X, typename Y>
auto operator == (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second == y.second);
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second == y.second);
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second == y.second);
}
template <typename X, typename Y>
auto operator == (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second == y.second;
}
//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= y);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= y);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= y);
  });
}


//+---------------+
//|   ITERABLE    |
//+---------------+
//|  NO   |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
 return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x >= dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x >= dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x >= dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i));
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
   return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
  });
 });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+ this is the base case out of pair comparisons
//|  NO   |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second >= y.second;
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second >= y.second;
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second >= y.second);
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second >= y.second;
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second >= y.second;
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second >= y.second);
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second >= y.second);
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second >= y.second);
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second >= y.second;
}
//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) > y;
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) > y;
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) > y);
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) > y;
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) > y;
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) > y);
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) > y;
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) > y;
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) > y);
  });
}


//+---------------+
//|   ITERABLE    |
//+---------------+
//|  NO   |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
 return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x > dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x > dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x > dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x > dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x > dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x > dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x > dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x > dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x > dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i));
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
   return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) > dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
  });
 });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) > dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) > dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) > dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) > dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) > dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) > dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) > dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) > dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+ this is the base case out of pair comparisons
//|  NO   |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second > y.second;
}
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second > y.second;
}
template <typename X, typename Y>
auto operator > (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second > y.second);
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second > y.second;
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second > y.second;
}
template <typename X, typename Y>
auto operator > (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second > y.second);
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second > y.second);
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second > y.second);
}
template <typename X, typename Y>
auto operator > (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second > y.second;
}
//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) <= y;
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) <= y;
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) <= y);
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) <= y;
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) <= y;
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) <= y);
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) <= y;
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) <= y;
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) <= y);
  });
}


//+---------------+
//|   ITERABLE    |
//+---------------+
//|  NO   |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
 return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x <= dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x <= dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x <= dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x <= dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x <= dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x <= dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x <= dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x <= dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x <= dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i));
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
   return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) <= dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
  });
 });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) <= dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) <= dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) <= dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) <= dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) <= dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) <= dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) <= dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) <= dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+ this is the base case out of pair comparisons
//|  NO   |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second <= y.second;
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second <= y.second;
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second <= y.second);
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second <= y.second;
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second <= y.second;
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second <= y.second);
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second <= y.second);
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second <= y.second);
}
template <typename X, typename Y>
auto operator <= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second <= y.second;
}
//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) < y;
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) < y;
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) < y);
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) < y;
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) < y;
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) < y);
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) < y;
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) < y;
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) < y);
  });
}


//+---------------+
//|   ITERABLE    |
//+---------------+
//|  NO   |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
 return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x < dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x < dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x < dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x < dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x < dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x < dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x < dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x < dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x < dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i));
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
   return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) < dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
  });
 });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) < dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) < dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) < dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) < dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) < dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) < dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) < dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) < dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+ this is the base case out of pair comparisons
//|  NO   |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second < y.second;
}
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second < y.second;
}
template <typename X, typename Y>
auto operator < (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second < y.second);
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second < y.second;
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second < y.second;
}
template <typename X, typename Y>
auto operator < (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second < y.second);
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second < y.second);
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second < y.second);
}
template <typename X, typename Y>
auto operator < (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second < y.second;
}
//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) != y;
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) != y;
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) != y);
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) != y;
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) != y;
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) != y);
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) != y;
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) != y;
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) != y);
  });
}


//+---------------+
//|   ITERABLE    |
//+---------------+
//|  NO   |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
 return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x != dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x != dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x != dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x != dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x != dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x != dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x != dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x != dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x != dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i));
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  YES  |
//+-------+-------+
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
   return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) != dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
  });
 });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) != dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) != dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) != dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) != dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) != dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) != dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) != dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) != dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}

//+---------------+
//|   ITERABLE    |
//+---------------+ this is the base case out of pair comparisons
//|  NO   |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second != y.second;
}
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second != y.second;
}
template <typename X, typename Y>
auto operator != (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second != y.second);
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second != y.second;
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second != y.second;
}
template <typename X, typename Y>
auto operator != (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second != y.second);
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second != y.second);
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return !(x.second != y.second);
}
template <typename X, typename Y>
auto operator != (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  return x.second != y.second;
}

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
