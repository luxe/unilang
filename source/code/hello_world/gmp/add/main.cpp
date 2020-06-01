#include <gmpxx.h>
#include <iostream>

int main (void)
{
  mpz_class a, b, c;

  a = 1234;
  b = "-5678";
  c = a+b;
  std::cout << "sum is " << c << "\n";

  return 0;
}