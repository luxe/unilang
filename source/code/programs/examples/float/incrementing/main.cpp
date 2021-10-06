#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>

int main(){
    
    std::cout << std::numeric_limits<float>::max_digits10 << std::endl;
    std::cout << std::numeric_limits<float>::max_exponent10 << std::endl;
    
std::cout.setf(std::ios::fixed, std::ios::floatfield);
std::cout.setf(std::ios::showpoint);
  

    //exit(0);
    
    float from = 0.0;
    float to = 1.0;
    while (from < 1){
        std::cout << std::setprecision(std::numeric_limits<float>::max_exponent10+150) << from << std::endl;
        from = nextafter (from,to);
    }
}