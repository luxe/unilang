#include <vector>
#include <set>
#include <iostream>
#include <iterator>
#include <utility>

struct Item{
    std::string name;
    int value;
};


//unique based on type its self
template<class InputIt>
bool all_unique(InputIt first, InputIt last){
  std::set<typename std::iterator_traits<InputIt>::value_type> s(first,last);
  return s.size() == std::distance(first,last);
}

//unique based on data member
template<class InputIt, class MemberType>
bool all_unique(InputIt first, InputIt last, MemberType std::iterator_traits<InputIt>::value_type::* member_name){
  
  auto total_length = std::distance(first,last);
  
  //not ideal, but works
  auto i = *first.*member_name;
  std::set<decltype(i)> s;
  
  while(first != last){
    s.insert(*first.*member_name);
    ++first;
  }
  
  return s.size() == total_length;
}


template<typename MemberType>
void Print(Item foo, MemberType Item::* member_name){
  std::cout << foo.*member_name << '\n';  
}

/*
template<typename T, typename DataMember>
void Print_Particular_Data_Member(std::vector<T> v){
  for (auto it: v){
  }
}*/

int main(){

  std::vector<Item> items
  {{"foo",1}
  ,{"bar",2}
  ,{"baz",3}
  ,{"zig",2}
  };
  

  Item foo{"name",100}; //create instance

  Print(foo, &Item::name);  //prints name
  Print(foo, &Item::value); //prints 100
  
  
  /*std::vector<int> i{1,2,3,4,3};
    std::cout << all_unique(i.begin(),i.end(),[](){
    return true;
  });*/
  
  
  std::cout << all_unique(items.begin(),items.end(),&Item::name);
  
  
  
  //Print_Data_Member(Item);
  
}
