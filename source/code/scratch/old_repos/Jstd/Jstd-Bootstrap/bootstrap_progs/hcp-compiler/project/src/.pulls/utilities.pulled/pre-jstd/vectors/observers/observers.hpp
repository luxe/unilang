template<typename T>
const T& Get_Nth_Element(std::vector<T> const& container, size_t n) {
  return container[n];
}

template <typename T>
bool In_Vector(std::vector<T> const& vec, T const& item){
    return std::find(vec.begin(), vec.end(), item) != vec.end();
}

template <typename T>
bool Vector_Contains_Any_Elements_In_Vector(std::vector<T> const& vec, std::vector<T> const& elements){
    for (auto const& it: elements){
        if (In_Vector(vec,it)){
            return true;
        }
    }
    return false;
}

bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str);
size_t Get_Longest_String_Length_In_Vector(std::vector<std::string> const& v);