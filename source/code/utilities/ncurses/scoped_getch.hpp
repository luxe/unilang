#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "getch/getch/include/getch.h"

class ScopedGetch
{
public:
  ScopedGetch()
  {
    ch_init();
  }

  ~ScopedGetch()
  {
    ch_end();
  }

};