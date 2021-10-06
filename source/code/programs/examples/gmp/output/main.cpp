#include <gmpxx.h>
#include <iostream>
#include <sstream>

int main (void)
{
  mpz_class a{"123123213"};
  std::cout << a << std::endl;

}