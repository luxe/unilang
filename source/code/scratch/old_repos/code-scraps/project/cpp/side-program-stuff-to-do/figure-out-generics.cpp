#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

//split_by_data_member_uniqueness.cpp


enum class Test{A,B,C};

struct Bar{
  int i;
  Bar(int i): i(i) {}
};

struct Foo{
  Bar b;
  Foo(int i): b(i) {}
};

template <typename T>
bool Exists_In_Set(std::set<T> const& s, T const& item){
  return s.count(item);
}
template <typename T>
void Add_To_Set(std::set<T> & s, T const& item_to_add){
  s.insert(item_to_add);
}

template<class InputIt, class MemberType>
auto Split_By_Data_Member_Uniqueness(InputIt first, InputIt last, MemberType std::iterator_traits<InputIt>::value_type::* member_name){

  //would like to no need to instantiate i here
  auto i = (*first.*member_name).i;
  std::vector<std::vector<decltype(i)>> all;
  std::vector<decltype(i)> some;
  
  std::set<decltype(i)> s;
  
  while(first != last){
    if (Exists_In_Set(s,(*first.*member_name).i)){
      all.push_back(some);
      some.clear();
      s.clear();
      
      //then add the one we just found
      some.push_back((*first.*member_name).i);
      Add_To_Set(s,(*first.*member_name).i);
    }
    else{
      some.push_back((*first.*member_name).i);
      Add_To_Set(s,(*first.*member_name).i);
    }
    ++first;
  }
  
  if (!some.empty()){
    all.push_back(some);
  }
  
  return all;
}


int main(){

std::vector<Foo> v{1,2,3,1,2,3,1,1,1,2,2,3};

std::set<Test> s;

s.insert(Test::A);



//std::vector<Foo> v{1,2,3,1,2,3,1,1,1,2,2,3};
//1 2 3 
//1 2 3 
//1 
//1 
//1 2 
//2 3

  auto x = Split_By_Data_Member_Uniqueness(v.begin(),v.end(),&Foo::b);
  /*for (auto it: x){
    for (auto it2: it){
      std::cout << it2 << " ";
    }
    std::cout << '\n';
  }
  */
  
}
