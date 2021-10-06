#include <iostream>
#include <cstdint>

enum byte : std::uint8_t {};
using byte2 = std::uint8_t;

void function(std::uint8_t i);

int main(){

  byte b = byte(5);
  std::uint8_t c = 5;
  byte2 d = 5;
  function(d);
}


void function(std::uint8_t i){
}
