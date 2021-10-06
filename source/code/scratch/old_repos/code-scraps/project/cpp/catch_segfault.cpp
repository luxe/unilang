#include <stdio.h>      /* printf, tmpnam, L_tmpnam, remove */
#include <stdlib.h>     /* exit */
#include <signal.h>
#include <setjmp.h>

int bad = 1;
jmp_buf env;

void no_seg(int p)
{
    printf("AAA ");
    printf("Not gona do it\n");
    bad = 0;          //Set value so we do not reenter hazard
    longjmp(env,1);   //Jump back
    return;
}

int main()
{
    int* ptr = NULL;
    int i = 0;
    //signal(SIGSEGV, no_seg);
    signal(SIGSEGV, no_seg);
    
    setjmp(env);    //Call before hazard code
   
    while(1)
    {
        i = i + 1; 
        if(bad) delete ptr; //Hazard code in if
        if(i % 100000000 == 0) printf("N\n");
        if(i % 10000000 == 0) printf("NN\n");
        ptr++;
    }
    
    printf("HI\n");
}
