//Trevor Hickey
//Dan Bennett
//230 Night
//04/11/11
//The Interface of a LargeIntegerT

#ifndef LARGE_NUMBER_H
#define LARGE_NUMBER_H

#include <ostream>
#include <string>

using std::string;

enum SignT{POSITIVE, NEGATIVE};
static const int MAX_DIGITS = 200;

class LargeIntegerT{

	public:
		//╔══════════════════════╗
		//║     Constructors     ║
		//╚══════════════════════╝
		LargeIntegerT(void);
		//Default Constructor
		//Post: The number is set to zero.
		//      It is represented as being positive
		//      The length of the number is considered 1 digit long
		
		LargeIntegerT(const long & number);
		//Parameterized Constructor
		//Post: The number is set to the value passed in.
		
		LargeIntegerT(const LargeIntegerT & number);
		//Parameterized constructor
		//Post: The number is set to the value passed in.

		LargeIntegerT(string number);
		//Parameterized constructor
		//Post: The number is set to the value passed in.
		//      Numbers must be entered correctly using only
		//      digit characters.
		
		//╔══════════════════════╗
		//║      Observers       ║
		//╚══════════════════════╝
		friend std::ostream & operator<<(std::ostream & stream, const LargeIntegerT & largeInteger);
		//outputs the number as a string(if the number is negative, a "-" will show up in front)
		
		short GetDigit(const long & number);
		//returns the value of a particular digit
		//the parameter must be >= 1 and <= MAX_DIGITS
		
		//╔══════════════════════╗
		//║     Transformers     ║
		//╚══════════════════════╝

		//absolute value
		LargeIntegerT abs(LargeIntegerT number);
		
		//overloaded binary operators
		const LargeIntegerT operator +(const LargeIntegerT & addedNumber) const;
		//Adds a largeNumberT to a LargeNumberT and returns a LargeNumberT
		//Programmer Note: the addedNumber parameter is passed by value because
		//if the number is negative, the elements of the array are changed for computation
		
		const LargeIntegerT operator -(const LargeIntegerT & subtractedNumber) const;
		//Subtracts a largeNumberT to a LargeNumberT and returns a LargeNumberT
		
		const LargeIntegerT operator *(const LargeIntegerT & multipliedNumber) const;
		//Multiplies a largeNumberT to a LargeNumberT and returns a LargeNumberT
		
		const LargeIntegerT operator /(const LargeIntegerT & dividedNumber) const;
		//Divides a largeNumberT to a LargeNumberT and returns a LargeNumberT
		
		LargeIntegerT & operator =(const LargeIntegerT & number);
		LargeIntegerT & operator +=(const LargeIntegerT & number);
		LargeIntegerT & operator -=(const LargeIntegerT & number);
		LargeIntegerT & operator *=(const LargeIntegerT & number);
		LargeIntegerT & operator /=(const LargeIntegerT & number);
		
		bool operator == (const LargeIntegerT & comparedNumber) const;
		//compares a largeNumberT with a largeNumberT and returns true if they are equal and false if they are not equal
		
		bool operator != (const LargeIntegerT & comparedNumber) const;
		//compares a largeNumberT with a largeNumberT and returns true if they are not equal and false if they are equal
		
		bool operator <  (const LargeIntegerT & comparedNumber) const;
		//compares a largeNumberT with a largeNumberT and returns true if
		//the left hand side is less than the right hand side. returns false if it is not
		
		bool operator >  (const LargeIntegerT & comparedNumber) const;
		//compares a largeNumberT with a largeNumberT and returns true if
		//the left hand side is greater than the right hand side. returns false if it is not
		
		bool operator <= (const LargeIntegerT & comparedNumber) const;
		//compares a largeNumberT with a largeNumberT and returns true if
		//the left hand side is less than or equal to the right hand side.
		//returns false if it is not
		
		bool operator >= (const LargeIntegerT & comparedNumber) const;
		//compares a largeNumberT with a largeNumberT and returns true if
		//the left hand side is greater than or equal to the right hand side.
		//returns false if it is not
		
		//╔══════════════════════╗
		//║      Destructor      ║
		//╚══════════════════════╝

		~LargeIntegerT(){};

		//╔══════════════════════╗
		//║   Debugging Tools    ║
		//╚══════════════════════╝
		void ShowMeEverything(void);
		
	private:

		SignT sign;
		int length;
		short digits[MAX_DIGITS];

		void FillUnusedArraySpaces(void);
		//looks at the length and fills in
		//zeros for every part of the array
		//which is not part of the number.

		void FormatArray(void);
		//adjusts the array contents so that
		//each element holds one digit.

		void FindNewLength(void);
		//loops through the array backwards
		//finding the new length of the number.

		void MakeEachIndexValueNegative(void);
		//loops through the array making every
		//element negative. (used in computation of a negative number)

		void FormatMultiplication(void);
		//formats the array after multiplication has been performed
};

#endif
