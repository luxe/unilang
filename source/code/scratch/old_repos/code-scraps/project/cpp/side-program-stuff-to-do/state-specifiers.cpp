#include <iostream>

class Foo{

int bar;


public:

  //observable
  int Bar() const{return bar;}
  
  //injectable
  void Bar(int const& b){bar = b;}
  
  //retrievable (obtainable?) (refferable?)
  int& BarRef(){ return bar;}
  int const& BarRef() const{ return bar;}
  
  //impentrable (unaccessable?) (hidden?) (implied without any of the others)
  //part of internal state and is unreachable from the client
  //it can not be directly observed,injected,or retrieved

};


int main(){


  Foo f;
  int& hi = f.BarRef();
  //...
  hi = 7;
  
  std::cout << f.Bar() << std::endl;

}
