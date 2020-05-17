//TUPLE VS T
template <typename X, typename OP, typename... Args>
bool operator == (std::tuple<OP, Args...> const& any, X const& x){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple == T\n";
  #endif
 typedef std::tuple <OP, Args...> tuple;
 return Tuple_And_T_Comparer
 <equal_to<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator != (std::tuple<OP, Args...> const& any, X const& x){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple != T\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <not_equal_to<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator > (std::tuple<OP, Args...> const& any, X const& x){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple > T\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <greater<>, X, tuple,1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator < (std::tuple<OP, Args...> const& any, X const& x){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple < T\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <less<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator >= (std::tuple<OP, Args...> const& any, X const& x){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple >= T\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <greater_equal<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator <= (std::tuple<OP, Args...> const& any, X const& x){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple <= T\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <less_equal<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),TUPLE_VS_T_DISPATCH());
}

//T VS TUPLE
template <typename X, typename OP, typename... Args>
bool operator == (X const& x, std::tuple<OP, Args...> const& any){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of T == Tuple\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <equal_to<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator != (X const& x, std::tuple<OP, Args...> const& any){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of T != Tuple\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <not_equal_to<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator > (X const& x, std::tuple<OP, Args...> const& any){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of T > Tuple\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <greater<>, X, tuple,1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator < (X const& x, std::tuple<OP, Args...> const& any){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of T < Tuple\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <less<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator >= (X const& x, std::tuple<OP, Args...> const& any){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of T >= Tuple\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <greater_equal<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}
template <typename X, typename OP, typename... Args>
bool operator <= (X const& x, std::tuple<OP, Args...> const& any){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of T <= Tuple\n";
  #endif
  typedef std::tuple <OP, Args...> tuple;
  return Tuple_And_T_Comparer
  <less_equal<>, X, tuple, 1, std::tuple_size<tuple>::value-1>::compare(x, any,std::get<0>(any),T_VS_TUPLE_DISPATCH());
}

//TUPLE VS TUPLE
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator == (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple == Tuple\n";
  #endif
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <equal_to<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator != (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple != Tuple\n";
  #endif
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <not_equal_to<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator > (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple > Tuple\n";
  #endif
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <greater<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator < (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple < Tuple\n";
  #endif
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <less<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator >= (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple >= Tuple\n";
  #endif
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <greater_equal<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
template <typename Left_OP, typename Right_OP, typename... Left, typename... Right>
bool operator <= (const std::tuple<Left_OP, Left...>& left, const std::tuple<Right_OP, Right...>& right){
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of Tuple <= Tuple\n";
  #endif
  typedef std::tuple <Right_OP, Right...> right_tuple;
  typedef std::tuple <Left_OP, Left...> left_tuple;
  return Tuple_And_Tuple_Comparer
  <less_equal<>, left_tuple, 1, std::tuple_size<left_tuple>::value-1, right_tuple, 1, std::tuple_size<right_tuple>::value-1>::compare(left,right,std::get<0>(left),std::get<0>(right));
}
