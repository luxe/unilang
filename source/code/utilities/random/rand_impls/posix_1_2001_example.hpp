#pragma once

/* RAND_MAX assumed to be 32767 */
namespace posix_1_2001_example{
    int rand(void);
    void srand(unsigned seed);
}