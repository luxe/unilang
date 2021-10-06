#include <random>
#include <iostream>

int Random_Number_Between_Range(int low, int high){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(low, high);
    return dist(mt);
}
std::vector<int> Vector_Of_N_Random_Numbers_Between_Range(int amount, int low, int high){
  std::vector<int> random_numbers;
  
  for (int i = 0; i < amount; ++i){
    random_numbers.push_back(Random_Number_Between_Range(low,high));
  }
  
  return random_numbers;
}

int main() {

    for (num: Vector_Of_N_Random_Numbers_Between_Range(150,1,8)){
    switch (num){
    case 1: std::cout << ":salt:"; break;
    case 2: std::cout << ":salt-left:"; break;
    case 3:  std::cout << ":salt-right:"; break;
    case 4:  std::cout << ":salt-down:"; break;
    case 5:  std::cout << ":pepper:"; break;
    case 6: std::cout << ":pepper-left:"; break;
    case 7: std::cout << ":pepper-right:"; break;
    case 8: std::cout << ":pepper-down:"; break;
    }
    std::cout << " ";
    }
    std::cout << std::endl;
}
