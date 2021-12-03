#pragma once
#include <string>
#include "code/utilities/math/gmp/lib.hpp"

class Every_N_Times
{
public:
    Every_N_Times(std::string amount){
        every_n_times = amount;
        current_step = "0";
    }
    
    bool Trigger(){
        ++current_step;
        if (current_step >= every_n_times){
            current_step = 0;
            return true;
        }
        return false;
    }
    
    
    private:
    mpz_class every_n_times;
    mpz_class current_step;
};
