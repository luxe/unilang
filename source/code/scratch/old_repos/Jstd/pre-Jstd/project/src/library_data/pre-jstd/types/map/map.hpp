#include <utility>

//overloading on map type
template <typename X, typename Y>
bool Exists_In_Map(std::map<X,Y> const& m, X const& item);

template <typename X, typename Y>
bool Exists_In_Unordered_Map(std::unordered_map<X,Y> const& m, X const& item);


//overloading on map types
template <typename X, typename Y>
bool Exists_In_Map(std::map<X,Y> const& m, X const& item){
  return m.count(item);
}
template <typename X, typename Y>
bool Exists_In_Unordered_Map(std::unordered_map<X,Y> const& m, X const& item){
  return m.count(item);
}

//some maps don't allow duplicates
//throw if we've attempted to add a duplicate
template <typename Container, typename First, typename Second, typename Exception>
void Throw_On_Failure_To_Insert_Item(Container & c, First f, Second s, Exception e){
  auto build = std::make_pair(f,s);
  auto result = c.insert(build);
  if (!result.second){
    throw e;
  }
}
