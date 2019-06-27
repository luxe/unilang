#include "code/utilities/signals/lib.hpp"
#include <cstdlib>
#include <signal.h>

void signal_SIGINT_to_exit()
{
    signal(SIGINT,[](int signum){
        exit(signum);
    });
}