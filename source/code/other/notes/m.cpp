#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <map>
#include <algorithm>


std::map<std::string,int> m{
{"A", 5},
{"B", 2},
{"C", 8},
{"D", 4}
};


template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

// flips an associative container of A,B pairs to B,A pairs
template<typename A, typename B, template<class,class,class...> class M, class... Args>
std::multimap<B,A> flip_map(const M<A,B,Args...> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(),
                   std::inserter(dst, dst.begin()),
                   flip_pair<A,B>);
    return dst;
}

template <typename... T>
auto make_vector(T&&... args)
{
    using first_type = typename std::tuple_element<0, std::tuple<T...>>::type;
    return std::vector<first_type>{std::forward<T>(args)...};
}

struct Object{};


void function(unsigned int i){
  std::cout << i << std::endl;
}

int main(){
 
  auto v1 = make_vector(1,2,3);
  
  //std::vector<int>    v1{1,2,3};
  //std::vector<double>  v2{1.1,2.2,3.3};
  //std::vector<Object> v3{Object{},Object{},Object{}};
  
  //auto v1 = make_vector(1,2,3);
  //auto v2 = make_vector(1.1,2.2,3.3);
  //auto v3 = make_vector(Object{},Object{},Object{});
  
  
  function(-1);
  
  
  auto i = flip_map(m);
  for (auto it: i){
    std::cout << it.first << " " << it.second << "\n";
  }
  
  
  //std::sort(std::begin(m),std::end(m),[](auto x, auto y){return true;});
  
}




