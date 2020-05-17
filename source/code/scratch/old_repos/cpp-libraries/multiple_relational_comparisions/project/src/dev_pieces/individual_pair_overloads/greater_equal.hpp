//+---------------+
//|   ITERABLE    |
//+---------------+
//|  YES  |  NO   |
//+-------+-------+
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Iterable][Pair] >= Tuple[OR][Not-Iterable][Pair]\n";
  #endif
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Iterable][Pair] >= Tuple[AND][Not-Iterable][Pair]\n";
  #endif
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Iterable][Pair] >= Tuple[NAND][Not-Iterable][Pair]\n";
  #endif
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= y);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Iterable][Pair] >= Tuple[OR][Not-Iterable][Pair]\n";
  #endif
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Iterable][Pair] >= Tuple[AND][Not-Iterable][Pair]\n";
  #endif
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Iterable][Pair] >= Tuple[NAND][Not-Iterable][Pair]\n";
  #endif
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return !(dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= y);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Iterable][Pair] >= Tuple[OR][Not-Iterable][Pair]\n";
  #endif
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Iterable][Pair] >= Tuple[AND][Not-Iterable][Pair]\n";
  #endif
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= y;
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<X>::value && is_not_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Iterable][Pair] >= Tuple[NAND][Not-Iterable][Pair]\n";
  #endif
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
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Not-Iterable][Pair] >= Tuple[OR][Iterable][Pair]\n";
  #endif
 return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Not-Iterable][Pair] >= Tuple[OR][Iterable][Pair]\n";
  #endif
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Not-Iterable][Pair] >= Tuple[OR][Iterable][Pair]\n";
  #endif
  return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x >= dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Not-Iterable][Pair] >= Tuple[AND][Iterable][Pair]\n";
  #endif
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Not-Iterable][Pair] >= Tuple[AND][Iterable][Pair]\n";
  #endif
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Not-Iterable][Pair] >= Tuple[AND][Iterable][Pair]\n";
  #endif
  return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return !(x >= dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i));
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Not-Iterable][Pair] >= Tuple[NAND][Iterable][Pair]\n";
  #endif
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Not-Iterable][Pair] >= Tuple[NAND][Iterable][Pair]\n";
  #endif
  return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) i){
    return x >= dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i);
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<X>::value && is_iterable<Y>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Not-Iterable][Pair] >= Tuple[NAND][Iterable][Pair]\n";
  #endif
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
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Iterable][Pair] >= Tuple[OR][Iterable][Pair]\n";
  #endif
 return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
   return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
    return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
  });
 });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Iterable][Pair] >= Tuple[AND][Iterable][Pair]\n";
  #endif
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Iterable][Pair] >= Tuple[NAND][Iterable][Pair]\n";
  #endif
  return std::any_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<OR_DISPATCH,decltype(i)>(OR_DISPATCH(),i) >= dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Iterable][Pair] >= Tuple[OR][Iterable][Pair]\n";
  #endif
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Iterable][Pair] >= Tuple[AND][Iterable][Pair]\n";
  #endif
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Iterable][Pair] >= Tuple[NAND][Iterable][Pair]\n";
  #endif
  return std::all_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::none_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<AND_DISPATCH,decltype(i)>(AND_DISPATCH(),i) >= dispatch_pair<NAND_DISPATCH,decltype(j)>(NAND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Iterable][Pair] >= Tuple[OR][Iterable][Pair]\n";
  #endif
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::any_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= dispatch_pair<OR_DISPATCH,decltype(j)>(OR_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Iterable][Pair] >= Tuple[AND][Iterable][Pair]\n";
  #endif
  return std::none_of(x.second.begin(),x.second.end(),[&](decltype(*x.second.begin()) i){
    return std::all_of(y.second.begin(),y.second.end(),[&](decltype(*y.second.begin()) j){
      return dispatch_pair<NAND_DISPATCH,decltype(i)>(NAND_DISPATCH(),i) >= dispatch_pair<AND_DISPATCH,decltype(j)>(AND_DISPATCH(),j);
    });
  });
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_iterable<Y>::value && is_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Iterable][Pair] >= Tuple[NAND][Iterable][Pair]\n";
  #endif
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
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Not-Iterable][Pair] >= Tuple[OR][Not-Iterable][Pair]\n";
  #endif
  return x.second >= y.second;
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Not-Iterable][Pair] >= Tuple[AND][Not-Iterable][Pair]\n";
  #endif
  return x.second >= y.second;
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<OR_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [OR][Not-Iterable][Pair] >= Tuple[NAND][Not-Iterable][Pair]\n";
  #endif
  return !(x.second >= y.second);
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Not-Iterable][Pair] >= Tuple[OR][Not-Iterable][Pair]\n";
  #endif
  return x.second >= y.second;
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Not-Iterable][Pair] >= Tuple[AND][Not-Iterable][Pair]\n";
  #endif
  return x.second >= y.second;
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<AND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [AND][Not-Iterable][Pair] >= Tuple[NAND][Not-Iterable][Pair]\n";
  #endif
  return !(x.second >= y.second);
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<OR_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Not-Iterable][Pair] >= Tuple[OR][Not-Iterable][Pair]\n";
  #endif
  return !(x.second >= y.second);
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<AND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Not-Iterable][Pair] >= Tuple[AND][Not-Iterable][Pair]\n";
  #endif
  return !(x.second >= y.second);
}
template <typename X, typename Y>
auto operator >= (dispatch_pair<NAND_DISPATCH,X> const& x, dispatch_pair<NAND_DISPATCH,Y> const& y) ->
typename std::enable_if<is_not_iterable<Y>::value && is_not_iterable<X>::value, bool>::type{
  #ifdef DEBUG_TRACE
  std::cout << "Operator overload of [NAND][Not-Iterable][Pair] >= Tuple[NAND][Not-Iterable][Pair]\n";
  #endif
  return x.second >= y.second;
}
