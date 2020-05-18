
//one way
template <typename T, typename U>
bool Equivalent(T t, U u){
  return t == u;
}

template <typename T, typename U>
bool Not_Equivalent(T t, U u){
  return t != u;
}

//both ways
template <typename T, typename U>
bool Equivalent_Both_Ways(T t, U u){
  return t == u && u == t;
}
template <typename T, typename U>
bool Not_Equivalent_Both_Ways(T t, U u){
  return t != u && u != t;
}
