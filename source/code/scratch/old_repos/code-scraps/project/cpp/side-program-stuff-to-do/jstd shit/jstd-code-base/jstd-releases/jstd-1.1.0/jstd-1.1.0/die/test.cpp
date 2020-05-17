#include <iostream>
#include <string>

#include "die.h"
#include "../jstd.h"


using namespace std;


int main()

{
  Die d6;
  d6.SeeRolls();
  d6.Roll();
  d6.SetFile("die.out");
  d6.Roll();
  d6.PrintOdds(cout);
  d6.SetDie(15);
  d6.Roll();
  
  d6.ResetFile();
  
  
  
  d6.Roll();
  
  Die* d8 = new Die(8);
  d8->Roll();
  delete d8;
 
  return 0;
}