
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;


int main (){
    //hold the amount of pins knocked down for each roll
    int roll1,roll2,roll3,
    
    //keeps track of how many pins are remaining on the alley
    pinsRemaining = 10,
    
    score = 0;
    
    //roll one
    do{
        cout << "How many pins did you knock down on your first roll? (0 - 10)";
        cin >> roll1;
    } 
    while ((roll1 > pinsRemaining) || (roll1 < 0 ));
    
    //calculate the amount of pins remaining
    pinsRemaining = pinsRemaining - roll1;
    
    //claculate the score so far
    score = roll1;
    
    //reset the pins if they are all knocked down
    if (pinsRemaining == 0){
      pinsRemaining = 10;
    }
    
    //roll two
    do{
        cout << "How many pins did you knock down on your second roll? (0 - " << pinsRemaining << ")";
        cin >> roll2;
    }
    while ((roll2 > pinsRemaining) || (roll2 < 0 ));
    
    //calculate the amount of pins remaining
    pinsRemaining = pinsRemaining - roll2;
    
    //claculate the score so far
    score += roll2;
    
    //reset the pins if they are all knocked down
    if (pinsRemaining == 0){
        pinsRemaining = 10;
    }
    
    //roll three
    do{
    if (score <= 10){pinsRemaining = 10;}
        cout << "How many pins did you knock down on your third roll? (0 - " << pinsRemaining << ")";
        cin >> roll3;
    }
    while ((roll3 > pinsRemaining) || (roll3 < 0 ));
    
    //calculate the amount of pins remaining
    pinsRemaining = pinsRemaining - roll3;
    
    //claculate the score so far
    score += roll3;
    
    //output the score the user
    cout << endl << "Your score is: " << score << endl << endl;
    
    return 0;
}
