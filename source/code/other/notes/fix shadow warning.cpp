#include <iostream>
#include <string>

struct Foo{

  int bar1, bar2;

 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wshadow"
  Foo(int bar1, int bar2)
  :bar1{bar1}
  ,bar2{bar2}
  {}
  #pragma GCC diagnostic pop
  
};

int main(){
  Foo f(1,2);
}


