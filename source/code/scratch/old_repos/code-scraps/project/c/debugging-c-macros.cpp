#include <stdlib.h>
#include <iostream>

/* Debugger */

#define note(S, ...) fprintf(stderr,                                     \
  "\x1b[1m(%s:%d, %s)\x1b[0m\n  \x1b[1m\x1b[90mnote:\x1b[0m " S "\n",    \
  __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define warn(S, ...) fprintf(stderr,                                     \
  "\x1b[1m(%s:%d, %s)\x1b[0m\n  \x1b[1m\x1b[33mwarning:\x1b[0m " S "\n", \
  __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define errn(S, ...) do { fprintf(stderr,                                \
  "\x1b[1m(%s:%d, %s)\x1b[0m\n  \x1b[1m\x1b[31merror:\x1b[0m " S "\n",   \
  __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); exit(1); } while (0) \
  

int main(int argc, char const *argv[])
{
  note("this will be a hard error in the future");
  warn("function '%s' redefined as non-inline", "my_function");
  errn("no such file or directory");

  return 0;
}
