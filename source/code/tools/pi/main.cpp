#include <iostream>
#include "code/utilities/math/pi_calculator.hpp"

int main(){
    mp_exp_t ex = 0;
    //std::cout << Pi_Calculator::Bailey_Borwein_Plouffe_Pi_To_N_Digits(400).get_prec() << std::endl;
    std::cout << Pi_Calculator::Bailey_Borwein_Plouffe_Pi_To_N_Digits(1).get_str(ex)[0] << std::endl;
    std::cout << Pi_Calculator::Bailey_Borwein_Plouffe_Pi_To_N_Digits(2).get_str(ex)[1] << std::endl;
    std::cout << Pi_Calculator::Bailey_Borwein_Plouffe_Pi_To_N_Digits(3).get_str(ex)[2] << std::endl;
    std::cout << Pi_Calculator::Bailey_Borwein_Plouffe_Pi_To_N_Digits(4).get_str(ex)[3] << std::endl;
    std::cout << Pi_Calculator::Bailey_Borwein_Plouffe_Pi_To_N_Digits(5).get_str(ex)[4] << std::endl;
    std::cout << Pi_Calculator::Bailey_Borwein_Plouffe_Pi_To_N_Digits(6).get_str(ex)[5] << std::endl;
}