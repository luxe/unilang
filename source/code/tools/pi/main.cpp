#include <iostream>
#include "code/utilities/math/pi_calculator.hpp"

int main(){
    mp_exp_t ex = 0;
    std::cout << Pi_Calculator::Bailey_Borwein_Plouffe_Pi_To_N_Digits(400).get_prec() << std::endl;
    std::cout << Pi_Calculator::Bailey_Borwein_Plouffe_Pi_To_N_Digits(400).get_str(ex) << std::endl;
}