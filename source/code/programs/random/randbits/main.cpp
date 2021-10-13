#include <iostream>
#include <bitset>
#include <random>

int main()
{
    const size_t nrOfBits = 256;
    std::bitset<nrOfBits> randomBits;

    std::mt19937 generator;
    generator.seed(0);
    std::uniform_real_distribution<float> distribution(0.0,1.0);

    float randNum;
    for(size_t i = 0; i < nrOfBits; i++)
    {
        randNum = distribution(generator);
        if(randNum < 0.5) {
            randNum = 0;
        } else {
            randNum = 1;
        }
        randomBits.set(i, randNum);
    }

    std::cout <<  "randomBits = " << randomBits << std::endl;
    
    
    generator.seed(0);
    std::uniform_int_distribution<int> distribution2(0,1);
    std::cout <<  "randomBits = ";
    for(size_t i = 0; i < nrOfBits; i++)
    {
        std::cout << distribution2(generator);
    }
    std::cout << std::endl;
    
    return 0;
}