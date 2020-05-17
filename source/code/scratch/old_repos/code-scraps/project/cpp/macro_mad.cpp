#include <stdio.h>

#define myfunc(a, b) (myfunc)(do_a(a), do_b(b))
/* if you have a preprocessor that may be non-standard
 * and enter a loop for the previous definition, define
 * myfunc with an extra set of parenthesis:
#define myfunc(a, b) (myfunc)(do_a(a), do_b(b))
 ******** */

int (myfunc)(int a, int b) /* myfunc does not get expanded here */
{
    printf("a=%d; b=%d\n", a, b);
    return 0;
}


int main(void)
{
  ::myfunc(4, 0);
    return 0;
}
