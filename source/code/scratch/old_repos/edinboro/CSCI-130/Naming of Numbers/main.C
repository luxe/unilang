/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PROGRAM INFO
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Trevor Hickey
// Dan Bennett
// Program 6 (The Naming of Numbers)
// Program Due: 11-22-10

/*
	Purpose:
	-This program will take in a value between -999,999,999 and 999,999,999 and output the value in english.
	-To exit, the user must type and send in a '0' twice.

	Error Checking:
	-program will check to see if the number entered is within bounds

	Updates:
		12-01-10: Moved Code into a separate function called 'SplitNumber'
				  Moved Code into a separate function called 'ComputeStringPart'
				  Moved Code into a separate function called 'ClearScreen'
		12-02-10: One string is created to hold the english output of the number instead of three
				  The loop now exits due to a change in a Boolean expression
				  Broke down code into more functions
				  Reformatted comments(data dictionary)
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//INCLUDE FILES
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCTION DECLARATIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClearScreen();//clears the console of any text
void Directions(); //displays purpose and directions for the program
long GetNumber(string numberStatement, string englishStatement);
void CheckRange(long &inputNumber); //makes sure the user typed in a valid number
void CheckNegative(long &inputNumber, bool &negative);//checks and handles negative numbers
string ConvertNumberToString(long &inputNumber, bool &negative);//converts the users input number into a string with commas
int SplitNumber(int outputNumber, long &inputNumber, int & modAndDivideVariable);//splits an integer where commas of the number would be
string ComputeStringPart(int &numberPart, string statement);//computes an integer into a string
string SpecialCase (int inputNumber); //converts 1 - 19
string Tens (int inputNumber);//converts the tens place
string FormatEnglishString(bool &negative, string &numberStatement, string &englishStatement);//adds title and "negative" if needed
string Commas(long inputNumber);//turns an integer into a string with commas(concept and coding by Ken Loomis)
bool CheckZero(long &inputNumber, string &englishStatement, short &zeroCounter);//determines end of program

int main()
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN FUNCTION VARIABLES
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	short zeroCounter = 0;  //holds the amount of times '0' is typed in a row
	
	long inputNumber = 0;       //holds the numeric representation of the input number
	int hundredNumber = 0;      //holds the value of the hundreds, tens, and ones place
	int thousandNumber = 0;     //holds the value of the hundred thousands, ten thousands, and thousands place
	int millionNumber = 0;      //holds the value of the hundred millions, ten millions, and millions place
	
	int modAndDivideVariable = 100000000; //this variable appears in the function 'SplitNumber' and is used to mod and divide

	string englishStatement = ""; //holds the english representation of the entire number entered
	string numberStatement = "";  //holds the numeric representation of the entire number with commas added

	bool negative = false;        //holds true/false in regards to the inputted number being negative
	bool exitProgram = false;     //holds true/false in regards to exiting the loop and ending the program
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//continue to repeat the algorithm until 'exitProgram' equals true
	while (!exitProgram)
	{

		ClearScreen(); //clears the console of any text
		Directions();  //displays purpose and directions for the program
		inputNumber = GetNumber(numberStatement, englishStatement); //gets a number from the user and makes sure it is in range
		CheckNegative(inputNumber, negative); //checks to see if the number is positive or negative
		

		//clears/resets variables that may already contain data
		englishStatement = "";
		numberStatement = "";
		millionNumber = 0;
		thousandNumber = 0;
		hundredNumber = 0;
		modAndDivideVariable = 100000000;

		//converts the number into a string with commas
		numberStatement = ConvertNumberToString(inputNumber, negative);


		//calculates and holds the value of the hundred millions, ten millions, and millions place
		millionNumber = SplitNumber(millionNumber, inputNumber, modAndDivideVariable);
		//calculates and holds the english representation of the hundred thousands, ten thousands, and thousands place
		thousandNumber = SplitNumber(thousandNumber, inputNumber, modAndDivideVariable);
		//calculates and holds the value of the hundreds, tens, and ones place
		hundredNumber = inputNumber;
		
		//computes and adds the english representation of the hundred millions, ten millions, and millions place
		if (millionNumber != 0)
		{
			englishStatement += ComputeStringPart(millionNumber, englishStatement);
			englishStatement += " million";
		}

		//computes and adds the english representation of the hundred thousands, ten thousands, and thousands place
		if (thousandNumber != 0)
		{
			englishStatement += ComputeStringPart(thousandNumber, englishStatement);
			englishStatement += " thousand";
		}

		//computes and adds the value of the hundreds, tens, and ones place
		if (hundredNumber != 0)
		{
			englishStatement += ComputeStringPart(hundredNumber, englishStatement);
		}
		
		//adds title in front and negative if needed
		englishStatement = FormatEnglishString(negative, numberStatement, englishStatement);
		//determines end of program
		exitProgram = CheckZero(inputNumber, englishStatement, zeroCounter);
		
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//displays purpose and directions for the program
void Directions(){
	cout << " /|========================================|\\"  << endl;
	cout << " || This program takes in a number between ||"   << endl;
	cout << " ||     -999,999,999 and 999,999,999       ||"   << endl;
	cout << " ||    and outputs the value in english.   ||"   << endl;
	cout << " \\|========================================||"  << endl;
	cout << "                || To exit: Type '0' twice.||"   << endl;
	cout << "                ||_________________________|/"   << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//clears the console of any text
void ClearScreen(){
	
	//creates 80 line breaks
	cout << string(80, '\n');
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// converts numbers 1 - 19
string SpecialCase (int inputNumber){
	string outputNumber;

	switch (inputNumber){
		case 1:
			outputNumber = " one";
			break;
		case 2:
			
			outputNumber = " two";
			break;
		case 3:
			
			outputNumber = " three";
			break;
		case 4:
			
			outputNumber = " four";
			break;
		case 5:
			
			outputNumber = " five";
			break;
		case 6:
			
			outputNumber = " six";
			break;
		case 7:
			
			outputNumber = " seven";
			break;
		case 8:
			
			outputNumber = " eight";
			break;
		case 9:
			
			outputNumber = " nine";
			break;

		case 10:

			outputNumber = " ten";
			break;
			
		case 11:

			outputNumber = " eleven";
			break;
		case 12:

			outputNumber = " twelve";
			break;
		case 13:

			outputNumber = " thirteen";
			break;
		case 14:

			outputNumber = " fourteen";
			break;
		case 15:

			outputNumber = " fifteen";
			break;
		case 16:

			outputNumber = " sixteen";
			break;
		case 17:

			outputNumber = " seventeen";
			break;
		case 18:
			
			outputNumber = " eighteen";
			break;
		case 19:
			
			outputNumber = " nineteen";
			break;
	}

	return outputNumber;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//converts the tens place of a number if it's not a special case ( 20 - 90)
string Tens (int inputNumber){
	string outputNumber;
	
	switch (inputNumber){
		case 2:
			
			outputNumber = " twenty";
			break;
		case 3:
			
			outputNumber = " thirty";
			break;
		case 4:
			
			outputNumber = " forty";
			break;
		case 5:
			
			outputNumber = " fifty";
			break;
		case 6:
			
			outputNumber = " sixty";
			break;
		case 7:
			
			outputNumber = " seventy";
			break;
		case 8:
			
			outputNumber = " eighty";
			break;
		case 9:
			
			outputNumber = " ninety";
			break;
	}
	
	return outputNumber;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//called on when the output of integer-like numbers should include commas.
//*concept and coding by Ken Loomis
string Commas(long inputNumber){
	string str;
	stringstream sin;
	
	sin << inputNumber;
	sin >> str;
	
	for (int i = str.length()-3; i > 0; i-=3)
	{
		str.insert(i, ",");
	}
	
	return str;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//calculates and holds the value of a particular numerical place
int SplitNumber(int outputNumber, long &inputNumber, int & modAndDivideVariable){

	outputNumber += inputNumber/modAndDivideVariable * 100;
	inputNumber = inputNumber % modAndDivideVariable;
	modAndDivideVariable *= .1;
	outputNumber += inputNumber / modAndDivideVariable * 10;
	inputNumber = inputNumber % modAndDivideVariable;
	modAndDivideVariable *= .1;
	outputNumber += inputNumber / modAndDivideVariable;
	inputNumber = inputNumber % modAndDivideVariable;
	modAndDivideVariable *= .1;

	return outputNumber;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//computes and stores the english representation of a particular numerical place
string ComputeStringPart(int &numberPart, string statement){
	if (numberPart / 100 != 0)
	{
		statement = SpecialCase (numberPart / 100);
		statement = statement + " hundred";
	}
	numberPart = numberPart % 100;
	
	if (numberPart <= 19)
	{
		statement += SpecialCase (numberPart);
	}
	else
	{
		statement += Tens (numberPart / 10);
		numberPart = numberPart % 10;
		
		statement += SpecialCase (numberPart);
	}

	return statement;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//asks and stores the users number input
long GetNumber(string numberStatement, string englishStatement){

	long inputNumber;
	
	//prompts user and stores an integer
	cout << endl << numberStatement << endl << englishStatement << endl << " Please enter a value => ";
	cin >> inputNumber;

	//check the range to make sure the value is in range
	CheckRange(inputNumber);
	
	return inputNumber;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//makes sure the number entered is in range
void CheckRange(long &inputNumber){

	//if the number entered is out of range keep re-prompting the user for a number
	while ((inputNumber > 999999999) || (inputNumber < -999999999))
	{
		ClearScreen(); //clears the console of any text
		Directions();  //displays purpose and directions for the program
		
		cout << endl << endl << " That number is out of computing range!";
		
		//re-prompts the user and stores an integer
		cout << endl << " Please enter a re-enter a value => ";
		cin >> inputNumber;
	}
	return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//checks and handles negative numbers
void CheckNegative(long &inputNumber, bool &negative){
	
	//if the number entered is negative..
	if (inputNumber < 0)
	{
		//sets inputNumber to a positive
		inputNumber *= -1;
		
		//notes that it was negative
		negative = true;
		
	}
	return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//decides if the program should exit by checking for a user input of "0"
bool CheckZero(long &inputNumber, string &englishStatement, short &zeroCounter){
	
	bool exitProgram = false;

	//increments a counter when the user input is zero and decides if the program should end
	if (englishStatement == " English Representation:")
	{
		englishStatement = " English Representation: zero";
		zeroCounter += 1;
		
		//if the user has entered zero twice, exit the program
		if (zeroCounter == 2)
		{	
			ClearScreen(); //clears the console of any text and closes the program
		
			cout << " Program Closed" << endl;
			
			//this will exit out of the loop and end the program
			exitProgram = true; 
		}
	}
	else
	{
		//reset the counter if the user did not enter a zero
		zeroCounter = 0;
	}

	return exitProgram;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ConvertNumberToString(long &inputNumber, bool &negative){

	string numberStatement;

	//store the input number as a string for later output
	numberStatement = " Numeric representation: ";
	if (negative == true)
	{
		numberStatement += "-";
	}
	//convert number to string and add commas
	numberStatement += Commas(inputNumber);

	return numberStatement;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//add a title in front of the string and decide if it should include the word "negative"
string FormatEnglishString(bool &negative, string &numberStatement, string &englishStatement){
	
	string finalEnglishString;

	//formats the output of the number in english
	finalEnglishString = " English Representation:";
	if ((negative == true) && (numberStatement !=  "Numeric Representation: 0"))
	{
		finalEnglishString += " negative";
		
		
		//reset the boolean 'negative' back to false
		negative = false;
		
	}
	finalEnglishString += englishStatement;
	
	return finalEnglishString;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	
