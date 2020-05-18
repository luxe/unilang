template<typename T>
auto Get_Random_Element(T const& container) -> const typename T::value_type&{
	std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(0, container.size() - 1);
	return container[dist(engine)];
}

template <typename T>
T RandomRealFromRange(T low, T high){
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_real_distribution<T> dist(low, high);
    return dist(engine);
}

template <typename T>
T RandomIntFromRange(T low, T high){
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<T> dist(low, high);
    return dist(engine);
}

template <typename T>
std::string Get_Random_String(T const& password_chars, unsigned int const& length){
  std::string password;
  
  //for loop mentioned in question
  for (unsigned int i = 0; i < length; ++i){
    password += Get_Random_Element(password_chars);
  }
  
  return password;
}
