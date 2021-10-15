#include <iostream>
#include <bitset>
#include <random>
#include <iomanip>
#include "code/utilities/random/rand_impls/posix_1_2001_example.hpp"
#include "code/utilities/random/lib.hpp"
#include "code/utilities/deps/external/php_src/lib.hpp"

int main(){
    
    //posix_1_2001_example::srand(1);
    //std::cout << posix_1_2001_example::rand() << ", "<< posix_1_2001_example::rand() << ", "<< posix_1_2001_example::rand() << std::endl;
    
    //std::cout << "RAND_MAX: " << RAND_MAX << std::endl;
    //std::cout << "INT32_MAX: " << INT32_MAX << std::endl;
    //std::cout << "UINT32_MAX: " << UINT32_MAX << std::endl;
    
    // std::cout << Zero_Or_One_Via_Rand_Mod_2() << std::endl;
    // std::cout << Zero_Or_One_Via_Rand_Mod_2() << std::endl;
    // std::cout << Zero_Or_One_Via_Rand_Mod_2() << std::endl;
    // std::cout << Zero_Or_One_Via_Rand_Mod_2() << std::endl;
    // std::cout << Zero_Or_One_Via_Rand_Mod_2() << std::endl;
    // std::cout << Zero_Or_One_Via_Rand_Mod_2() << std::endl;
    // std::cout << Zero_Or_One_Via_Rand_Mod_2() << std::endl;
    // std::cout << Zero_Or_One_Via_Rand_Mod_2() << std::endl;
    // std::cout << Zero_Or_One_Via_Rand_Mod_2() << std::endl;
    // exit(0);
    //auto x = Random_256Bits_Via_Rand_Mod_2();
    //while (true){
    //    std::cout << x << std::endl;
    //    Shift_On_Another_Bit_Via_Rand_Mod_2(x);
    //    exit(0);
    //}


   int ROWS = 6;
   int COLS = 10;
   int low_inclusive = 0;
   int high_inclusive = 13;
   std::mt19937 gen;
   std::uniform_int_distribution<> distrib(low_inclusive, high_inclusive);
   gen.seed(0);
   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;

   std::cout << "dist: " << std::endl;
   for (size_t i = 0; i < ROWS; ++i){
          for (size_t j = 0; j < COLS; ++j){
                 std::cout << std::setw(2) << distrib(gen) << " ";
          }
       std::cout << std::endl;
   }
   std::cout << std::endl;

   gen.seed(0);
   
   std::cout << "mod: " << std::endl;
   for (size_t i = 0; i < ROWS; ++i){
          for (size_t j = 0; j < COLS; ++j){
                 std::cout << std::setw(2) << gen() % (high_inclusive+1) << " ";
          }
       std::cout << std::endl;
   }

/*
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << std::endl;
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << std::endl;
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << std::endl;
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << " ";
   std::cout << distrib(gen) << std::endl;
*/

   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;
   //std::cout << gen() << std::endl;

   //std::cout << "max: " << gen.max() << std::endl << std::endl;

/*

auto gen2 = std::mersenne_twister_engine<std::uint_fast16_t, 32, 624, 397, 31,
                             0x9908b0df, 11,
                             0xffffffff, 7,
                             0x9d2c5680, 15,
                             0xefc60000, 18, 1812433253>();

   gen2.seed(0);
   std::cout << gen2() << std::endl;
   std::cout << gen2() << std::endl;
   std::cout << gen2() << std::endl;
   std::cout << "max: " << gen2.max() << std::endl;

*/

/*
int php_mod_amount = 16;
php_mt_srand(0);
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << std::endl;
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << std::endl;
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << " ";
std::cout << php_mt_rand() % php_mod_amount << std::endl;
*/


/*
std::cout << php_mt_rand_range(0,15) << std::endl;
std::cout << php_mt_rand_range(0,15) << std::endl;
std::cout << php_mt_rand_range(0,15) << std::endl;
std::cout << php_mt_rand_range(0,15) << std::endl;
std::cout << php_mt_rand_range(0,15) << std::endl;
std::cout << php_mt_rand_range(0,15) << std::endl;
*/
    
}