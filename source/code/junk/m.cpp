//encryption
int XorCheckSum(std::string const& s){
  int x = 0;
  for (auto const& it: s){
    x ^= it;
  }
  return x;
}

//string convert
std::string AsHexString(int c){
  std::ostringstream s;
  s << std::hex << std::uppercase << c;
  return s.str();
}




//types/pair
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


//vectors/creators
template <typename... T>
auto make_vector(T&&... args)
{
    using first_type = typename std::tuple_element<0, std::tuple<T...>>::type;
    return std::vector<first_type>{std::forward<T>(args)...};
}

