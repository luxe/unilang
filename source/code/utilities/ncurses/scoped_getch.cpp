#include "scoped_getch.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "getch/include/ch.hpp"


ScopedGetch::ScopedGetch()
{
    ch_init();
}

ScopedGetch::~ScopedGetch()
{
    ch_end();
}