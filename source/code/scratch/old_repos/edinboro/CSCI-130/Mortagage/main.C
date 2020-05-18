// Trevor Hickey
// Dan Bennett
// Program 3 (Mortgage)
// 10-13-10
/* This program will compute the monthly payment, and output the first few lines of the amortization table for a mortgage.*/

/*
Updates: 
10-14-10- added 'cout statments' to echo back what the user entered when displaying results
10-16-10- added option to see more of the amortization table
	  added option to calculate a new mortgage
	  added a function that adds commas into the output of float-like numbers
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//called on when the output of float-like numbers should include commas.
//*concept and coding by Ken Loomis
string Commas(long double num)
{
  string str;
  stringstream sin;
  int dot=0;
  
  sin << fixed;
  sin << num;
  sin >> str;

  dot = str.find('.');
  if (dot<=0) dot = str.length();
  else if (dot < str.length()-2)
  {
    str = str.substr(0, dot+3);
  }
  
  for (int i = dot-3; i > 0; i-=3)
  {
    str.insert(i, ",");
  }
  
  return str;
}

int main() {
  
  //program jumps to here when the user decides they want to calculate a new mortgage
  start:
  
  //declares all the variables to be used in the mortgage formula
   const float PAYMENTS_PER_YEAR = 12.0;
   float purchasePrice,
	 percentDown,
	 interestRate,
	 downPayment,
	 amountFinanced,
	 monthlyPayment,
	 annual_interest_rate,
	 number_of_years;
	 
   //declares variables that will be used in the output of the amortization table
   int monthNumber = 0;
   float interestPaid,
         principalPaid;

    //declares a character to determine what the user wants to do after calculating the results
    char option = 'a';
    
    //clears the console of any text
    cout << string(50, '\n');
    
    //stores input values for purchasePrice, percentDown, interestRate, and number_of_years
    cout << "What is the Purchase Price? ";
    cin  >> purchasePrice;
    cout << "What is the Percent Down?(%) ";
    cin  >> percentDown;
    cout << "What is the Inerest Rate?(%) ";
    cin  >> interestRate;
    cout << "How many years will this mortgage last? ";
    cin  >> number_of_years;
    
    //manipulates the inputed percent values into decimal form for operations
    interestRate = interestRate / 100.0;
    percentDown = percentDown / 100.0;
    
    //calculates and stores values for floats not given input values
    downPayment = purchasePrice * percentDown;
    amountFinanced = purchasePrice - downPayment;
    annual_interest_rate = interestRate / PAYMENTS_PER_YEAR;
    
    //mortgage formula
    monthlyPayment = (amountFinanced * annual_interest_rate) / (1.0 - (pow(1.0 + annual_interest_rate,-PAYMENTS_PER_YEAR * number_of_years)));
    
    //clears the console of any text
    cout << string(50, '\n');
    
    //echos back all of the information the user has inputted
    cout << "Purchase Price: $" << Commas(purchasePrice) << endl;
    cout << "Percent Down: " << percentDown * 100 << "%" << endl;
    cout << "Inerest Rate: " << interestRate* 100 << "%" << endl;
    cout << "Duration: " << number_of_years;
    
    //decides wether the user should see "year" or "years"
    if (number_of_years != 1){
      cout << " years";
    }
    else{
      cout << "year";
    }
    
    //outputs the monthly payment
    cout << endl << endl << "Your monthly payment is $" << setprecision(2) << monthlyPayment << "." << endl << endl;
    
    //outputs the titles used in the amortization table
    cout << "Amortization Table:" << endl
         << "Month" 
         << setw(20) << "Current Balance" 
         << setw(20) << "Interest Paid" 
         << setw(20) << "Principal Paid" 
         << endl;
    
    //each loop will calculate and produce one line of the amortization table
    while (monthNumber < 3) {
      
      //increments to the next month
      monthNumber++;
      
      //calculates and stores values for interestPaid and principalPaid
      interestPaid = amountFinanced * interestRate * (1.0 / 12.0);
      principalPaid = monthlyPayment - interestPaid;
     
      //outputs one line of the amortization table
      cout << fixed;
      cout << setw(5) << monthNumber
           << setw(20) << setprecision(2) << Commas(amountFinanced)
           << setw(20) << interestPaid
           << setw(20) << principalPaid
           << endl;
      
      //recalculates and stores the new value for the Current Balance
      amountFinanced = amountFinanced - principalPaid;
    }

    //asks the user if they would like to see more of the table or calculate a new mortgage and stores their decision
    cout << endl << "*Type 'm' to see more of the table" << endl;
    cout << "*Type 'c' to calculate another mortgage" << endl;
    cin >> option;
    
    //displays more of the amortization table
    if (option == 'm'){
      while (amountFinanced > 0) {
      
        //increments to the next month
        monthNumber++;
      
        //calculates and stores values for interestPaid and principalPaid
        interestPaid = amountFinanced * interestRate * (1.0 / 12.0);
        principalPaid = monthlyPayment - interestPaid;
     
        //outputs one line of the amortization table
        cout << fixed;
        cout << setw(5) << monthNumber
             << setw(20) << setprecision(2) << Commas(amountFinanced)
             << setw(20) << interestPaid
             << setw(20) << principalPaid
             << endl;
      
        //recalculates and stores the new value for the Current Balance
        amountFinanced = amountFinanced - principalPaid;
      }
    
    //asks the user if they would like to calculate a new mortgage and stores their decision
    cout << endl << "*Type 'c' to calculate another mortgage" << endl;
    cin >> option;
    }
    
    //start the algorithm over again so that the user can calculate a new mortgage
    if (option == 'c'){
      goto start;
    }
      
return 0;
}