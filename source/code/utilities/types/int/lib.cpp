#include "code/utilities/types/int/lib.hpp"

unsigned long reverse_bits(unsigned long num) {
  unsigned long s = 8 * sizeof(num); // bit size; must be power of 2
  unsigned long mask = ~0;
  while ((s >>= 1) > 0) {
    mask ^= (mask << s);
    num = ((num >> s) & mask) | ((num << s) & ~mask);
  }
  return num;
}

