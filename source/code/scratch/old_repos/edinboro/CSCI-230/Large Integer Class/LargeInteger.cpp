//Trevor Hickey
//Dan Bennett
//230 Night
//04/11/11
//The implementation of a LargeIntegerT

#include <iostream>
#include <string>
#include "LargeInteger.h"

using namespace std;

//╔══════════════════════╗
//║     Constructors     ║
//╚══════════════════════╝
LargeIntegerT::LargeIntegerT(){

	sign = POSITIVE;
	length = 1;
	digits[0] = 0;
	FillUnusedArraySpaces();
	
	return;
}
LargeIntegerT::LargeIntegerT(const long & number){

	long tempNumber = number;
	short digit = 0;
	length = 0;

	//decide if the number is negative, positive, or a zero
	if (number < 0){
		sign = NEGATIVE;
		tempNumber*=-1;
	}
	else if (number > 0){
		sign = POSITIVE;
	}
	else{
		sign = POSITIVE;
		length = 1;
		digits[0] = 0;
	}

	//get each digit and store it into the array while incrementing the length
	for (int i = 0; tempNumber > 0; i++){

		digit = tempNumber % 10;
		tempNumber/=10;

		digits[i] = digit;
		length++;
	}

	FillUnusedArraySpaces();

	return;
}
LargeIntegerT::LargeIntegerT(const LargeIntegerT & number){

	sign = number.sign;
	length = number.length;

	for (int i = 0; i < MAX_DIGITS; i++){
		digits[i] = number.digits[i];
	}

	return;
}
LargeIntegerT::LargeIntegerT(string number){

	short stringToNumber; //gets assigned a number based on a character value
	short stringPos = -1;
	
	//account for a negative symbol or an
	//instance of a zero number before proceeding
	if (number[0] == '-'){
		sign = NEGATIVE;
		number.erase(0,1);
	}
	else{
		sign = POSITIVE;
	}

	//removes any zeros that are in the string before the number
	while ((number.length() != 1) && (number[0] == '0')){
		number.erase(0,1);
	}

	//checks to see if the only character left in the array is a zero
	if (number[0] == '0'){
		sign = POSITIVE;
	}
	
	length = number.length();

	//loop through the array backwards starting at the strings length
	for (int i = number.length(); i >= 0; i--){
		
		//converting character a value into the integer value they represent
		switch (number[stringPos]){
			case '0': stringToNumber = 0;
			break;
			case '1': stringToNumber = 1;
			break;
			case '2': stringToNumber = 2;
			break;
			case '3': stringToNumber = 3;
			break;
			case '4': stringToNumber = 4;
			break;
			case '5': stringToNumber = 5;
			break;
			case '6': stringToNumber = 6;
			break;
			case '7': stringToNumber = 7;
			break;
			case '8': stringToNumber = 8;
			break;
			case '9': stringToNumber = 9;
			break;
		}
		digits[i] = stringToNumber;
		stringPos++;
	}

	FillUnusedArraySpaces();

	return;
}
//╔══════════════════════╗
//║      Observers       ║
//╚══════════════════════╝
ostream & operator<<(ostream & stream, const LargeIntegerT & largeInteger){

	//output a negative symbol if the number is negative
	if (largeInteger.sign == NEGATIVE){
		stream << "-";
	}

	//loop through the array backwards starting
	//at the length in order to output the number properly
	for (int i = largeInteger.length-1; i >= 0; i--){
		stream << largeInteger.digits[i];
	}
	
	return stream;
}
short LargeIntegerT::GetDigit(const long & number){
	short returnNumber = 0;

	if ((number >=0) && (number < MAX_DIGITS)){
		returnNumber =  digits[number-1];
	}

	return returnNumber;
}
//╔══════════════════════╗
//║     Transformers     ║
//╚══════════════════════╝
LargeIntegerT LargeIntegerT::abs(LargeIntegerT number){

	LargeIntegerT returnNumber(number);
	returnNumber.sign = POSITIVE;

	return returnNumber;
}

const LargeIntegerT LargeIntegerT::operator +(const LargeIntegerT & addedNumber) const{

	//  topNumber
	//+ bottomNumber
	//  ------------
	//  returnNumber
	LargeIntegerT topNumber(*this);
	LargeIntegerT bottomNumber(addedNumber);
	LargeIntegerT returnNumber;
	SignT endingSign = POSITIVE;
	bool flipped = false;
	
	//rearange the numbers so that the smallest magnitude gets added to the largest magnitude
	//*this is important when dealing with negative numbers and negative answers
	if (bottomNumber.abs(bottomNumber) > topNumber.abs(topNumber)){
		topNumber = addedNumber;
		bottomNumber = *this;
		flipped = true;
	}

	//decide what the sign is going to be after the operation
	if (topNumber.sign == NEGATIVE && bottomNumber.sign == POSITIVE && flipped == false){
		endingSign = NEGATIVE;
	}
	//if (topNumber.sign == POSITIVE && bottomNumber.sign == NEGATIVE && flipped == true){
	//	endingSign = NEGATIVE;
	//}
	if (topNumber.sign == NEGATIVE && bottomNumber.sign == NEGATIVE){
		endingSign = NEGATIVE;
	}
	
	//if a ONE negative number is involved, make that negative number a positive and subtract them
	//if they are both negatives or both positives, add them together
	if (topNumber.sign == NEGATIVE && bottomNumber.sign == POSITIVE){
		returnNumber = topNumber.abs(topNumber) - bottomNumber;
	}
	else if (topNumber.sign == POSITIVE && bottomNumber.sign == NEGATIVE){
		returnNumber = topNumber - bottomNumber.abs(bottomNumber);
	}
	else{
		//add together each element
		for (int i = 0; i < topNumber.length; i++){
			returnNumber.digits[i] = topNumber.digits[i] + bottomNumber.digits[i];
		}

		//format the answer and find new length(if the length changed at all)
		returnNumber.FormatArray();
		returnNumber.FindNewLength();
	}
	
	//decide what the sign of the number should be
	returnNumber.sign = endingSign;
	
	return returnNumber;
}
const LargeIntegerT LargeIntegerT::operator -(const LargeIntegerT & subtractedNumber) const{

	//  topNumber
	//- bottomNumber
	//  ------------
	//  returnNumber
	LargeIntegerT topNumber(*this);
	LargeIntegerT bottomNumber(subtractedNumber);
	LargeIntegerT returnNumber;
	SignT endingSign = POSITIVE;
	bool flipped = false;

	//rearange the numbers so that the smallest magnitude gets added to the largest magnitude
	//*this is important when dealing with negative numbers and negative answers
	if (bottomNumber.abs(bottomNumber) > topNumber.abs(topNumber)){
		topNumber = subtractedNumber;
		bottomNumber = *this;
		flipped = true;
	}
	
	//decide what the sign is going to be after the operation
	if (bottomNumber.sign == NEGATIVE && flipped == true){
		endingSign = NEGATIVE;
	}
	if (topNumber.sign == NEGATIVE && bottomNumber.sign == NEGATIVE && flipped == false){
		endingSign = NEGATIVE;
	}

	if (topNumber.sign == POSITIVE && bottomNumber.sign == POSITIVE && flipped == true){
		endingSign = NEGATIVE;
	}

	//if a ONE negative number is involved, make that negative number a positive and add them
	//if they are both negatives or both positives, subtract them
	if (topNumber.sign == NEGATIVE && bottomNumber.sign == POSITIVE){
		returnNumber = topNumber.abs(topNumber) + bottomNumber;
	}
	else if (topNumber.sign == POSITIVE && bottomNumber.sign == NEGATIVE){
		returnNumber = topNumber + bottomNumber.abs(bottomNumber);
	}
	else{

		//subtract each element from each other
		for (int i = 0; i < topNumber.length; i++){
			returnNumber.digits[i] = topNumber.digits[i] - bottomNumber.digits[i];
		}

		//format the answer and find new length(if the length changed at all)
		returnNumber.FormatArray();
		returnNumber.FindNewLength();

	}

	//decide what the sign of the number should be
	returnNumber.sign = endingSign;

	return returnNumber;
}
const LargeIntegerT LargeIntegerT::operator *(const LargeIntegerT & multipliedNumber) const{

	//  topNumber
	//* bottomNumber
	//  ------------
	//  returnNumber
	LargeIntegerT topNumber(*this);
	LargeIntegerT bottomNumber(multipliedNumber);
	LargeIntegerT returnNumber;
	SignT endingSign = POSITIVE;

	LargeIntegerT temp;
	int zeroAddOnCounter = 0;

	//decide what the sign is going to be after the operation
	if (topNumber.sign == NEGATIVE && bottomNumber.sign == POSITIVE){
		endingSign = NEGATIVE;
	}
	if (topNumber.sign == POSITIVE && bottomNumber.sign == NEGATIVE){
		endingSign = NEGATIVE;
	}

	for (int i = 0; i < bottomNumber.length; i++){  //loop through each element of the bottom number
		for (int j = 0; j < topNumber.length; j++){ //loop through each element of the top number

			//build the temp array
			temp.digits[j+zeroAddOnCounter] = bottomNumber.digits[i]*topNumber.digits[j];
		}
		
		temp.FormatMultiplication();
		temp.FindNewLength();
		returnNumber += temp; //begin building the final answer
		temp = 0;             //reset the temp value
		zeroAddOnCounter++;  //increment this variable so the next number will have the added numbers needed for proper calculation
	}

	returnNumber.sign = endingSign;
	
	return returnNumber;
}
const LargeIntegerT LargeIntegerT::operator /(const LargeIntegerT & dividedNumber) const{
	//   topNumber
	// / bottomNumber
	//   ------------
	//   returnNumber
	LargeIntegerT topNumber(*this);
	LargeIntegerT bottomNumber(dividedNumber);
	LargeIntegerT returnNumber;
	SignT endingSign = POSITIVE;
	int counter = 0;

	//decide what the sign is going to be after the operation
	if (topNumber.sign == NEGATIVE && bottomNumber.sign == POSITIVE){
		endingSign = NEGATIVE;
	}
	if (topNumber.sign == POSITIVE && bottomNumber.sign == NEGATIVE){
		endingSign = NEGATIVE;
	}

	//take away any signs on the values that may exist
	topNumber = topNumber.abs(topNumber);
	bottomNumber = bottomNumber.abs(bottomNumber);

	//if the user divides by a larger number, then the answer will be zero
	//else perform division algorithm
	if (bottomNumber.abs(bottomNumber) > topNumber.abs(topNumber)){
		returnNumber = 0;
		returnNumber.sign = POSITIVE;
		returnNumber.length = 1;
	}
	else{

		//speeds up the subtraction process of the division algorithm
		int times10counter = 0;
		int addCounter = 1;
		LargeIntegerT bottomGrow(bottomNumber);

		bottomGrow *= 10;
		if (bottomGrow < topNumber){
			while (bottomGrow < topNumber){
				times10counter++;
				bottomGrow*= 10;
			}
			bottomGrow/=10;

			for (int i = 0; i < times10counter; i++){
					addCounter *= 10;
				}

			counter+=addCounter;
			topNumber-=bottomGrow;
		}
			

		
		//keep subtracting the divsor from the divident while counting how many times it takes
		//for the number to reach zero or negative territory
		topNumber -= bottomNumber;
		while (topNumber >= 0){
			counter++;
			topNumber -= bottomNumber;
		}
		
		returnNumber = counter;
		returnNumber.sign = endingSign;
	}

	return returnNumber;
}
	

LargeIntegerT & LargeIntegerT::operator =(const LargeIntegerT & number){

	//completely copies the array by assigning each element
	//and copying over the length and sign of the number
	for (int i = 0; i < MAX_DIGITS; i++){
		digits[i] = number.digits[i];
	}
	
	length = number.length;
	sign = number.sign;

	return *this;
}
LargeIntegerT & LargeIntegerT::operator +=(const LargeIntegerT & number){

	*this = *this + number;

	return *this;
}
LargeIntegerT & LargeIntegerT::operator -=(const LargeIntegerT & number){

	*this = *this - number;
	
	return *this;
}
LargeIntegerT & LargeIntegerT::operator *=(const LargeIntegerT & number){

	*this = *this * number;
	
	return *this;
}
LargeIntegerT & LargeIntegerT::operator /=(const LargeIntegerT & number){

	*this = *this / number;

	return *this;
}

bool LargeIntegerT::operator == (const LargeIntegerT & comparedNumber) const{

	bool match = true;

	//compare the sign of the two numbers
	if (comparedNumber.sign!= sign){
		match = false;
	}

	//compare each element in the array to make sure they are the same
	for (int i = 0; i < MAX_DIGITS; i++){

		if (comparedNumber.digits[i]!= digits[i]){
			match = false;
		}
	}

	return match;
}
bool LargeIntegerT::operator != (const LargeIntegerT & comparedNumber) const{

	bool Nomatch = false;

	//compare the sign of the two numbers
	if (comparedNumber.sign!= sign){
		Nomatch = true;
	}

	//compare each element in the array to make sure they are the same
	for (int i = 0; i < MAX_DIGITS; i++){

		if (comparedNumber.digits[i]!= digits[i]){
			Nomatch = true;
		}
	}

	return Nomatch;
}
bool LargeIntegerT::operator <  (const LargeIntegerT & comparedNumber) const{

	bool isLessThan = true;
	
	//determine answer by looking at the signs
	if (sign == POSITIVE && comparedNumber.sign == NEGATIVE){
		isLessThan = false;
	}

	//if they are both negative, determine the answer by looking at number lengths
	if (comparedNumber.sign == NEGATIVE && sign == NEGATIVE){
		if (comparedNumber.length > length){
			isLessThan = false;
		}
	}

	//if they are both positive, determine the answer by looking at number lengths
	if (comparedNumber.sign == POSITIVE && sign == POSITIVE){
		if (comparedNumber.length < length){
			isLessThan = false;
		}
	}

	//if nothing has caused it to be false yet..
	//they must have the same sign and length.
	//this chunk of code inspects each index to make a decision
	//as to whether or not the first is greater than the second
	bool done = false;
	if (isLessThan == true){
		if (comparedNumber.sign == NEGATIVE && sign == NEGATIVE){
			for (int i = length-1; i >= 0 && done == false; i--){
				if (comparedNumber.digits[i] != digits[i]){
					done = true;
					if (comparedNumber.digits[i] > digits[i]){
						isLessThan = false;
					}
				}
			}

		}
		if (comparedNumber.sign == POSITIVE && sign == POSITIVE){
			for (int i = length-1; i >= 0 && done == false; i--){
				if (comparedNumber.digits[i] != digits[i]){
					done = true;
					if (comparedNumber.digits[i] < digits[i]){
						isLessThan = false;
					}
				}
			}

		}
	}

	//if they are equal to eachother than one can not be less than another
	if (*this == comparedNumber){
		isLessThan = false;
	}


	return isLessThan;
}
bool LargeIntegerT::operator >  (const LargeIntegerT & comparedNumber) const{
	bool isGreaterThan = true;

	//determine answer by looking at the signs
	if (comparedNumber.sign == POSITIVE && sign == NEGATIVE){
		isGreaterThan = false;
	}

	//if they are both negative, determine the answer by looking at number lengths
	if (comparedNumber.sign == NEGATIVE && sign == NEGATIVE){
		if (comparedNumber.length < length){
			isGreaterThan = false;
		}
	}

	//if they are both positive, determine the answer by looking at number lengths
	if (comparedNumber.sign == POSITIVE && sign == POSITIVE){
		if (comparedNumber.length > length){
			isGreaterThan = false;
		}
	}
	//if nothing has caused it to be false yet..
	//they must have the same sign and length.
	//this chunk of code inspects each index to make a decision
	//as to whether or not the first is greater than the second
	bool done = false;
	if (isGreaterThan == true){
		if (comparedNumber.sign == NEGATIVE && sign == NEGATIVE){
			for (int i = length-1; i >= 0 && done == false; i--){
				if (comparedNumber.digits[i] != digits[i]){
					done = true;
					if (comparedNumber.digits[i] < digits[i]){
						isGreaterThan = false;
					}
				}
			}

		}
		
		if (comparedNumber.sign == POSITIVE && sign == POSITIVE){
			for (int i = length-1; i >= 0 && done == false; i--){
				if (comparedNumber.digits[i] != digits[i]){
					done = true;
					if (comparedNumber.digits[i] > digits[i]){
						isGreaterThan = false;
					}
				}
			}

		}
	}

	//if they are equal to eachother than one can not be less than another
	if (*this == comparedNumber){
		isGreaterThan = false;
	}


	return isGreaterThan;
}
bool LargeIntegerT::operator >= (const LargeIntegerT & comparedNumber) const{

	bool greaterOrEqual = true;

	//determine answer by looking at the signs
	if (comparedNumber.sign == POSITIVE && sign == NEGATIVE){
		greaterOrEqual = false;
	}

	//if they are both negative, determine the answer by looking at number lengths
	if (comparedNumber.sign == NEGATIVE && sign == NEGATIVE){
		if (comparedNumber.length < length){
			greaterOrEqual = false;
		}
	}

	//if they are both positive, determine the answer by looking at number lengths
	if (comparedNumber.sign == POSITIVE && sign == POSITIVE){
		if (comparedNumber.length > length){
			greaterOrEqual = false;
		}
	}

	//if nothing has caused it to be false yet..
	//they must have the same sign and length.
	//this chunk of code inspects each index to make a decision
	//as to whether or not the first is greater than the second
	bool done = false;
	if (greaterOrEqual == true){
		if (comparedNumber.sign == NEGATIVE && sign == NEGATIVE){
			for (int i = length-1; i >= 0 && done == false; i--){
				if (comparedNumber.digits[i] != digits[i]){
					done = true;
					if (comparedNumber.digits[i] < digits[i]){
						greaterOrEqual = false;
					}
				}
			}

		}
		if (comparedNumber.sign == POSITIVE && sign == POSITIVE){
			for (int i = length-1; i >= 0 && done == false; i--){
				if (comparedNumber.digits[i] != digits[i]){
					done = true;
					if (comparedNumber.digits[i] > digits[i]){
						greaterOrEqual = false;
					}
				}
			}

		}
	}

	return greaterOrEqual;
}
bool LargeIntegerT::operator <= (const LargeIntegerT & comparedNumber) const{

	bool isLessOrEqual = true;

	//determine answer by looking at the signs
	if (sign == POSITIVE && comparedNumber.sign == NEGATIVE){
		isLessOrEqual = false;
	}

	//if they are both negative, determine the answer by looking at number lengths
	if (comparedNumber.sign == NEGATIVE && sign == NEGATIVE){
		if (comparedNumber.length > length){
			isLessOrEqual = false;
		}
	}

	//if they are both positive, determine the answer by looking at number lengths
	if (comparedNumber.sign == POSITIVE && sign == POSITIVE){
		if (comparedNumber.length < length){
			isLessOrEqual = false;
		}
	}

	//if nothing has caused it to be false yet..
	//they must have the same sign and length.
	//this chunk of code inspects each index to make a decision
	//as to whether or not the first is greater than the second
	bool done = false;
	if (isLessOrEqual == true){
		if (comparedNumber.sign == NEGATIVE && sign == NEGATIVE){
			for (int i = length-1; i >= 0 && done == false; i--){
				if (comparedNumber.digits[i] != digits[i]){
					done = true;
					if (comparedNumber.digits[i] > digits[i]){
						isLessOrEqual = false;
					}
				}
			}

		}
		if (comparedNumber.sign == POSITIVE && sign == POSITIVE){
			for (int i = length-1; i >= 0 && done == false; i--){
				if (comparedNumber.digits[i] != digits[i]){
					done = true;
					if (comparedNumber.digits[i] < digits[i]){
						isLessOrEqual = false;
					}
				}
			}

		}
	}

	return isLessOrEqual;
}


//╔══════════════════════╗
//║   Debugging Tools    ║
//╚══════════════════════╝
void LargeIntegerT::ShowMeEverything(void){
	
	cout << "array: ";
	for (int i = 0; i < MAX_DIGITS; i++){
		cout << digits[i];
	}
	cout << endl;

	cout << "output: ";
	for (int i = length-1; i>= 0; i--){
		cout << "[" << digits[i] << "]";
	}
		
	cout << endl << "sign: ";
	switch (sign){
		case POSITIVE: cout << "positive";
		break;
		case NEGATIVE: cout << "negative";
		break;
	}

	cout << endl << "length: " << length << endl;

	return;
}
//╔══════════════════════╗
//║   Private Functions  ║
//╚══════════════════════╝
void LargeIntegerT::FillUnusedArraySpaces(void){

	//fills the array with zeros but does not write over the number stored
	for (int i = length; i < MAX_DIGITS; i++){
		digits[i] = 0;
	}

	return;
}

void LargeIntegerT::FormatArray(void){

	//make adjustments after addition
	for (int i = 0; i < MAX_DIGITS; i++){
		if (digits[i] > 9){
			digits[i] %= 10;
			digits[i+1]+=1;
		}
	}

	//make adjustments after subtraction
	for (int i = 0; i < MAX_DIGITS; i++){
		if (digits[i] < 0){
			digits[i]+= 10;
			digits[i+1]-= 1;
		}
	}

	return;
}

void LargeIntegerT::FindNewLength(void){

	//counts how many spaces in the array are not part of the number
	int counter = 0;
	for (int i = MAX_DIGITS; ((digits[i-1] == 0) && (i > 1)); i-- ){

		counter++;
	}
	//sets the new length
	length = MAX_DIGITS - counter;

	return;
}

void LargeIntegerT::MakeEachIndexValueNegative(void){

	for (int i = 0; i < MAX_DIGITS; i++){
		digits[i]*=-1;
	}

	return;
}

void LargeIntegerT::FormatMultiplication(void){

	short carryNumber;

		for (int i = 0; i < MAX_DIGITS; i++){
			if (digits[i] > 9){
				carryNumber = digits[i] / 10;
				digits[i] %= 10;
				digits[i+1] += carryNumber;
			}
		}

	return;
}







