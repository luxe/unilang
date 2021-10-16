#include "code/utilities/random/rand_impls/xorshift128plus.hpp"

static uint64_t xo_state0 = 1;
static uint64_t xo_state1 = 2;

void
xorshift128plus_srand (unsigned long seed)
{
  xo_state0 = seed | 1;
  xo_state1 = seed | 2;
}

uint64_t
xorshift128plus (void)
{
  uint64_t s1 = xo_state0;
  uint64_t s0 = xo_state1;
  xo_state0 = s0;
  s1 ^= s1 << 23;
  s1 ^= s1 >> 17;
  s1 ^= s0;
  s1 ^= s0 >> 26;
  xo_state1 = s1;
  return s1;
}