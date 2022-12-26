#include <thread>
#include <memory>
#include <iostream>
int main(){
    // prints number of cores detected by C++
    int threadNumbers = std::thread::hardware_concurrency();
    std::cout << "observed cores: " << threadNumbers << std::endl;
}