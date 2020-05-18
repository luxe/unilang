std::vector<std::string> Get_Comma_Seperated_Values_From_File(std::string const& path_to_file);

template<typename T>
std::vector<std::vector<T>> Create_N_By_N_Vector(int x, int y, T value){
  std::vector<std::vector<T>> result;
  std::vector<T> row;
  for (int i = 0; i < y; ++i){
      for (int j = 0; j < x; ++j){
        row.push_back(value);
      }
    result.push_back(row);
    row.clear();
  }
  return result;
}

template<typename T>
std::vector<std::vector<T>> Create_A_Square_Vector(int size, T value){
  return Create_N_By_N_Vector(size,size,value);
}
