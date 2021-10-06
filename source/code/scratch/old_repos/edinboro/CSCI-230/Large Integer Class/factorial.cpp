//Trevor Hickey
//Dan Bennett
//230 Night
//04/11/11
//this program will compute the factorial of a large number
//by implementing a large integer class

#include <iostream>
#include "LargeInteger.h"

using namespace std;

LargeIntegerT ComputeFactorial (LargeIntegerT largeInteger);

int main(){
	
	const int MAX_COMPUTATIONAL_NUMBER = 120;
	long number;
	LargeIntegerT largeInteger;

	cout << "please enter a number to find the factorial of: ";

	cin >> number;
	
	//test to see if the input value is out of range
	while ((number > MAX_COMPUTATIONAL_NUMBER) || (number < MAX_COMPUTATIONAL_NUMBER*-1)){
		cout << "The number you have entered is out of range." << endl;
		cout << "please enter another number to find the factorial of: ";
		cin >> number;
	}
	
	largeInteger = number;
	cout << largeInteger << "! = " << ComputeFactorial(largeInteger);

	return 0;
}


LargeIntegerT ComputeFactorial (LargeIntegerT largeInteger){

	if (largeInteger > 1)
		return (largeInteger * ComputeFactorial (largeInteger-1));
	else
		return (1);
}

