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
