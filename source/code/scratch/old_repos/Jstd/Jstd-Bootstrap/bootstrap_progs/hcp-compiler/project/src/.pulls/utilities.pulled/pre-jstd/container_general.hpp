template<typename Container>
const typename Container::value_type& getNthElement(const Container& container, size_t n) {
  auto itr = cbegin(container);
  for (auto i = 0u; i < n; ++i) {
    ++itr;
  }
  return *itr;
}
