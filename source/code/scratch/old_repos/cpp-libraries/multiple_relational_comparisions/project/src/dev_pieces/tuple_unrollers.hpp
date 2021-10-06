//a struct to evaluate Tuples and Ts
template <class Compare_Operation, class X, class Tuple, size_t Index, size_t ReverseIndex>
struct Tuple_And_T_Comparer
{

  //T VS TUPLE
  static bool  compare (const X& x, const Tuple& tuple, OR_DISPATCH const& bo, T_VS_TUPLE_DISPATCH const& order){
      #ifdef DEBUG_TRACE
      std::cout << "[Tuple and T Class] T vs Or-able tuple\n";
      #endif
      return Compare_Operation()(
      dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x),
      dispatch_pair<OR_DISPATCH,decltype(std::get<Index>(tuple))>(OR_DISPATCH(),std::get<Index>(tuple)))
  || Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order);
  }
  static bool compare (const X& x, const Tuple& tuple, AND_DISPATCH const& bo, T_VS_TUPLE_DISPATCH const& order){
      #ifdef DEBUG_TRACE
      std::cout << "[Tuple and T Class] T vs And-able tuple\n";
      #endif
      return Compare_Operation()(
      dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x),
      dispatch_pair<AND_DISPATCH,decltype(std::get<Index>(tuple))>(AND_DISPATCH(),std::get<Index>(tuple)))
  && Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order);
  }
  static bool compare (const X& x, const Tuple& tuple, NAND_DISPATCH const& bo, T_VS_TUPLE_DISPATCH const& order){
      #ifdef DEBUG_TRACE
      std::cout << "[Tuple and T Class] T vs Nand-able tuple\n";
      #endif
      return Compare_Operation()(
      dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x),
      dispatch_pair<NAND_DISPATCH,decltype(std::get<Index>(tuple))>(NAND_DISPATCH(),std::get<Index>(tuple)))
  && Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order);
  }

  //TUPLE VS T
  static bool compare (const X& x, const Tuple& tuple, OR_DISPATCH const& bo, TUPLE_VS_T_DISPATCH const& order){
  #ifdef DEBUG_TRACE
  std::cout << "[Tuple and T Class] Or-able tuple vs T\n";
  #endif
      return Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order)
  || Compare_Operation()(
  dispatch_pair<OR_DISPATCH,decltype(std::get<Index>(tuple))>(OR_DISPATCH(),std::get<Index>(tuple)),
  dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x)
  );
  }
  static bool compare (const X& x, const Tuple& tuple, AND_DISPATCH const& bo, TUPLE_VS_T_DISPATCH const& order){
      #ifdef DEBUG_TRACE
      std::cout << "[Tuple and T Class] And-able tuple vs T\n";
      #endif
      return Tuple_And_T_Comparer<Compare_Operation, X, Tuple, Index+1, ReverseIndex-1>::compare(x,tuple,bo,order)
  && Compare_Operation()(
  dispatch_pair<AND_DISPATCH,decltype(std::get<Index>(tuple))>(AND_DISPATCH(),std::get<Index>(tuple)),
  dispatch_pair<OR_DISPATCH,decltype(x)>(OR_DISPATCH(),x)
  );
  }
  static bool compare (const X& x, const Tuple& tuple, NAND_DISPATCH const& bo, TUPLE_VS_T_DISPATCH const& order){
  #ifdef DEBUG_TRACE
  std::cout << "[Tuple and T Class] Nand-able tuple vs T\n";
  #endif
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
  #ifdef DEBUG_TRACE
  std::cout << "[Tuple and T Class] base case with And-Tuple\n";
  #endif
    return true;
  }
  template <typename ORDER>
  static bool compare (const X& x, const Tuple& tuple, NAND_DISPATCH const& BO, ORDER const& order){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and T Class] base case with Nand-Tuple\n";
    #endif
    return true;
  }
  template <typename ORDER>
  static bool compare (const X& x, const Tuple& tuple, OR_DISPATCH const& BO, ORDER const& order){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and T Class] base case with Or-Tuple\n";
    #endif
    return false;
  }

};
//a struct to evaluate Tuples and Tuples
template <class Compare_Operation, class Left, size_t Left_Index, size_t Left_ReverseIndex, class Right, size_t Right_Index, size_t RightReverseIndex>
struct Tuple_And_Tuple_Comparer{

  static bool compare (Left const& left, Right const& right, OR_DISPATCH const& bo_left, OR_DISPATCH const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] OR-able tuple with OR-able tuple\n";
    #endif
    auto result = Compare_Operation()
    (
    dispatch_pair<OR_DISPATCH,decltype(std::get<Left_Index>(left))>(OR_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<OR_DISPATCH,decltype(std::get<Right_Index>(right))>(OR_DISPATCH(),std::get<Right_Index>(right))
    ) || Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result || Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, OR_DISPATCH const& bo_left, AND_DISPATCH const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] OR-able tuple with AND-able tuple\n";
    #endif
    auto result = Compare_Operation()
    (
    dispatch_pair<OR_DISPATCH,decltype(std::get<Left_Index>(left))>(OR_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<AND_DISPATCH,decltype(std::get<Right_Index>(right))>(AND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result || Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, OR_DISPATCH const& bo_left, NAND_DISPATCH const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] OR-able tuple with NAND-able tuple\n";
    #endif
    auto result = (Compare_Operation()
    (
    dispatch_pair<OR_DISPATCH,decltype(std::get<Left_Index>(left))>(OR_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Right_Index>(right))>(NAND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH()));
    return result || Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }
  static bool compare (Left const& left, Right const& right, AND_DISPATCH const& bo_left, OR_DISPATCH const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] AND-able tuple with OR-able tuple\n";
    #endif
    auto result = Compare_Operation()
    (
    dispatch_pair<AND_DISPATCH,decltype(std::get<Left_Index>(left))>(AND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<OR_DISPATCH,decltype(std::get<Right_Index>(right))>(OR_DISPATCH(),std::get<Right_Index>(right))
    ) || Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, AND_DISPATCH const& bo_left, AND_DISPATCH const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] AND-able tuple with AND-able tuple\n";
    #endif
    auto result = Compare_Operation()
    (
    dispatch_pair<AND_DISPATCH,decltype(std::get<Left_Index>(left))>(AND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<AND_DISPATCH,decltype(std::get<Right_Index>(right))>(AND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, AND_DISPATCH const& bo_left, NAND_DISPATCH const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] AND-able tuple with NAND-able tuple\n";
    #endif
    auto result = (Compare_Operation()
    (
    dispatch_pair<AND_DISPATCH,decltype(std::get<Left_Index>(left))>(AND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Right_Index>(right))>(NAND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH()));
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, NAND_DISPATCH const& bo_left, OR_DISPATCH const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] NAND-able tuple with OR-able tuple\n";
    #endif
    auto result = Compare_Operation()
    (
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Left_Index>(left))>(NAND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<OR_DISPATCH,decltype(std::get<Right_Index>(right))>(OR_DISPATCH(),std::get<Right_Index>(right))
    ) || Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, NAND_DISPATCH const& bo_left, AND_DISPATCH const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] NAND-able tuple with AND-able tuple\n";
    #endif
    auto result = Compare_Operation()
    (
    dispatch_pair<NAND_DISPATCH,decltype(std::get<Left_Index>(left))>(NAND_DISPATCH(),std::get<Left_Index>(left)),
    dispatch_pair<AND_DISPATCH,decltype(std::get<Right_Index>(right))>(AND_DISPATCH(),std::get<Right_Index>(right))
    ) && Tuple_And_T_Comparer<Compare_Operation, decltype(std::get<Left_Index>(left)), Right, Right_Index+1, RightReverseIndex-1>
    ::compare(std::get<Left_Index>(left),right,bo_right,T_VS_TUPLE_DISPATCH());
    return result && Tuple_And_Tuple_Comparer<Compare_Operation, Left, Left_Index+1, Left_ReverseIndex-1, Right, Right_Index, RightReverseIndex>::compare(left,right,bo_left,bo_right);
  }

  static bool compare (Left const& left, Right const& right, NAND_DISPATCH const& bo_left, NAND_DISPATCH const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] NAND-able tuple with NAND-able tuple\n";
    #endif
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
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] base case when left tuple is OR-able\n";
    #endif
    return false;
  }
  template <typename BO_RIGHT>
  static bool compare (Left const& left, Right const& right, AND_DISPATCH const& bo_left, BO_RIGHT const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] base case when left tuple is AND-able\n";
    #endif
    return true;
  }
  template <typename BO_RIGHT>
  static bool compare (Left const& left, Right const& right, NAND_DISPATCH const& bo_left, BO_RIGHT const& bo_right){
    #ifdef DEBUG_TRACE
    std::cout << "[Tuple and Tuple Class] base case when left tuple is NAND-able\n";
    #endif
    return true;
  }
};
