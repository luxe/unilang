#pragma once
#include <cstdlib>
#include <cstdint>


void xorshift128plus_srand (unsigned long seed);

uint64_t xorshift128plus (void);
