/*
	Program 1: Calculator
	Programmer: Trevor Hickey
	Class CSCI 230 (Mondays and Tuesdays (4:30 - 5:45)), Spring 2011
	Short Description: A simple integer calculator that will perform operations on various number systems

	Narrative:
	This integer calculator has an accumulator, four memory locations and supports the operations in the tables below:
	 _______________________________________________________________________________
	| Operation | # Operands |                       Comment                        |
	|    + 	    |      2     | Addition                                             |
	|    - 	    |      2     | Subtraction                                          |
	|    - 	    |      1     | Negation                                             |
	|    * 	    |      2     | Multiplication                                       |
	|    / 	    |      2     | Integer Division                                     |
	|    % 	    |      2     | Remainder                                            |
	|    ^ 	    |      2     | Power                                                |
	|  load     |      1     | Load the accumulator from a memory location          |
	|  store    |      1     | Store the accumulator to a memory location           |
	|  print    |      0     | Print the value in the accumulator                   |
	|  system   |      1     | Set the output system                                |
	|   += 	    |      1     | Add operand to accumulator                           |
	|   -= 	    |      1     | Subtract operand from accumulator                    |
	|   *= 	    |      1     | Multiply accumulator by operand                      |
	|   /= 	    |      1     | Divide accumulator by operand                        |
	|   %=      |      1     | Remainder of accumulator divided by operand          |
	|   ^= 	    |      1     | Raise accumulator to operand                         |
	|  dump     |      0     | Print the value of the accumulator and all registers |
	\___________|____________|______________________________________________________/
	 ______________________________
	|   Number System  | Subscript | Memory Location 1: A
	|Decimal           |    dcml   | Memory Location 2: B
	|Binary            |    biny   | Memory Location 3: C
	|Hexadecimal       |    hexa   | Memory Location 4: D
	|Trinary           |    trin   |
	|Modified Urnfield |    murn   |
	|Modified Mayan    |    mmay   |
	|Positionless      |    posi   |
	\______________________________/

		Error Checking: checks to see if the operand is of valid length and includes a colon.
						checks the number system at the end of operands and decides if they are valid.
						when encountered by a negative symbol, the program decides the best course of action.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath> //pow()

using namespace std;

enum OperationTypeT {ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, MODULATION, POWER, ADD, SUBTRACT,
             MULTIPLY, DIVIDE, REMAINDER, RAISE, NEGATION, STORE, LOAD, SYSTEM, PRINT, DUMP, INVALID};
enum OperandNumberSystemT {DCML, BINY, HEXA, TRIN, MURN, MMAY, POSI, EMPTY};

//The CPU represents a memory unit.  It has an four memory locations and data about the accumulator
struct CPU{
	int memoryLocationA,
		memoryLocationB,
		memoryLocationC,
		memoryLocationD,
		
		accumulator;
		OperandNumberSystemT accumulatorOutputSystem;
		bool accumulatorIsNegative;

	CPU()
	{
		memoryLocationA = 0;
		memoryLocationB = 0;
		memoryLocationC = 0;
		memoryLocationD = 0;
		accumulator = 0;
		accumulatorOutputSystem = DCML;
		accumulatorIsNegative = false;
	}
};

//the command represents a line from the computations file.  It holds information neccesary to make calculations
struct command{
	
	OperationTypeT operation;
	
	string operand1Representation;
	int operand1Value;
	OperandNumberSystemT firstOperands_NumberSystem;
	bool operand1Negative;
	
	string operand2Representation;
	int operand2Value;
	OperandNumberSystemT secondOperands_NumberSystem;
	bool operand2Negative;
	
	int numberOfOperands;

	command()
	{
		OperationTypeT operation = INVALID;
		
		string operand1Representation = "empty";
		int operand1Value = 0;
		OperandNumberSystemT firstOperands_NumberSystem = DCML;
		bool operand1Negative = false;
		
		string operand2Representation = "empty";
		int operand2Value = 0;
		OperandNumberSystemT secondOperands_NumberSystem = DCML;
		bool operand2Negative = false;
	}
};
	

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void OpenComputations (ifstream & computationsFile, bool & computationsSuccess, string COMPUTATIONS);
OperationTypeT GetOperation(ifstream & computationsFile,command & commandFromFile);
OperationTypeT NegateOrSubtract(ifstream & computationsFile,command & commandFromFile, OperationTypeT operation);
	string TakeInRestOfCommand(ifstream & computationsFile);
	bool CheckForValidOperand(string str, bool valid);

void GetArguments(CPU & integerCalculator, ifstream & computationsFile, command & commandFromFile);
	int GetNumberOfOperands(command & commandFromFile);
	void StoreOperands(ifstream & computationsFile, command & commandFromFile);
	void CheckIfNegative(command & commandFromFile);
	
void ProcessCommand(CPU & integerCalculator, command & commandFromFile);
	void PerformCalculation(CPU & integerCalculator, command & commandFromFile);
		OperandNumberSystemT DetermineNumberSystem(string & str);
	OperandNumberSystemT StringToNumberSystem(string str);
		int ConvertToDecimal(OperandNumberSystemT NumberSystem, string operandString, CPU integerCalculator);
			int BinaryToDecimal(string operandString);
			int BaseToDecimal(string operandString, int base);
			int UrnfieldToDecimal(string operandString);
			int MayanToDecimal(string operandString);
				int CountMayanSections(CPU integerCalculator, int numberOfSections);
				int FindMayanPart(CPU integerCalculator, int numberOfSections);
				string BuildMayanString (CPU & integerCalculator, int & numberOfSections, int mayanPart);
			int PositionlessToDecimal(string operandString);
			int RegisterValue(string operandString, CPU integerCalculator);
		void ConvertToNegative (command & commandFromFile);
		void Calculate(CPU & integerCalculator, command commandFromFile);
	void Load(CPU & integerCalculator, command commandFromFile);
	void Store(CPU & integerCalculator, command commandFromFile);
	void Print(CPU integerCalculator);
	void Dump(CPU integerCalculator);
	
void Output(CPU integerCalculator, command commandFromFile);
	void ShowResults(CPU integerCalculator);
		void CheckAcummulatorNegative(CPU & integerCalculator);
		void OutputFinalResult(CPU integerCalculator);
			string ConvertToNumberSystem(CPU integerCalculator);
				string DecimalToBinary(CPU integerCalculator,string answer);
				string DecimalToBase(CPU integerCalculator,string answer, int base);
				string DecimalToUrnfield(CPU integerCalculator,string answer);
				string DecimalToMayan(CPU integerCalculator,string answer);
				string DecimalToPositionless(CPU integerCalculator,string answer);
			string stringOnSystem(CPU integerCalculator);


int main()
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN FUNCTION VARIABLES
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	const string COMPUTATIONS = "computations.cmds";    //outside file this program will interact with
	ifstream computationsFile;                          //declares a filestream to open a file of computation commands



	CPU integerCalculator;   //Declares the four memory locations and information about the accumulator
	command commandFromFile; //Declares a command struct containing values and properties of the current command

	bool computationsSuccess = true;   //tests whether the computations file was opened successfully
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN FUNCTION ROUTINE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	OpenComputations (computationsFile,computationsSuccess,COMPUTATIONS);           //opens the file holding the computations
	if (computationsSuccess){                                                        //continues if the file opened successfully
		commandFromFile.operation = GetOperation(computationsFile,commandFromFile);   //takes in the first operation
		while(!computationsFile.eof()) {                                               //start loop until end reached of computations file..
			if (commandFromFile.operation != INVALID){                                  //continues if the last operation read was valid
				GetArguments(integerCalculator, computationsFile, commandFromFile);     //stores the arguments
				ProcessCommand(integerCalculator, commandFromFile);                    //performs command
				Output(integerCalculator, commandFromFile);                           // outputs the results of the command
			}                                                                        //repeat loop
		commandFromFile.operation = GetOperation(computationsFile,commandFromFile); //takes in the next operation
		}
	}
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: OpenComputations
//Input: COMPUTATIONS: constant string of the filename
//Input/Output: computationsFile: filestream
//				computationsSuccess: a bool that determines if the filestream succesfuly opened the file
//This function will open the computations file and report if it was succesful
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OpenComputations (ifstream & computationsFile, bool & computationsSuccess, string COMPUTATIONS){
	
	//opens file which contains a list of computations
	//*files must be in the program's directory
	computationsFile.open(COMPUTATIONS.c_str());
	
	//tests to make sure the file was opened
	if(!computationsFile) {
		cout << endl << "ERROR: Failed to open " << "'"<< COMPUTATIONS <<"'." << endl
		<< "*please make sure you have the file '" << COMPUTATIONS <<"' " << "in the same directory as this program." <<endl << endl;
		
		computationsSuccess = false;
	}
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: GetOperation
//Input/Output:  computationsFile: filestream
//Output: operation: an enumerated type
//This function takes in and stores the operation as an enumerated data type
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OperationTypeT GetOperation(ifstream & computationsFile,command & commandFromFile){

	string stringOperation;
	OperationTypeT operation;
	
	computationsFile >> stringOperation; //takes in the first string from a particular computation line

	//examines the string and decides what type of operation is being performed
	if ( stringOperation == "+" )
	{
		operation = ADDITION;
	}
	else if ( stringOperation == "-" )
	{
		operation = NegateOrSubtract(computationsFile,commandFromFile, operation);
	}
	else if ( stringOperation == "*" )
	{
		operation = MULTIPLICATION;
	}
	else if ( stringOperation == "/" )
	{
		operation = DIVISION;
	}
	else if ( stringOperation == "%" )
	{
		operation = MODULATION;
	}
	else if ( stringOperation == "^" )
	{
		operation = POWER;
	}
	else if ( stringOperation == "load" )
	{
		operation = LOAD;
	}
	else if ( stringOperation == "store" )
	{
		operation = STORE;
	}
	else if ( stringOperation == "print" )
	{
		operation = PRINT;
	}
	else if ( stringOperation == "system" )
	{
		operation = SYSTEM;
	}
	else if ( stringOperation == "+=" )
	{
		operation = ADD;
	}
	else if ( stringOperation == "-=" )
	{
		operation = SUBTRACT;
	}
	else if ( stringOperation == "*=" )
	{
		operation = MULTIPLY;
	}
	else if ( stringOperation == "/=" )
	{
		operation = DIVIDE;
	}
	else if ( stringOperation == "%=" )
	{
		operation = REMAINDER;
	}
	else if ( stringOperation == "^=" )
	{
		operation = RAISE;
	}
	else if ( stringOperation == "dump" )
	{
		operation = DUMP;
	}
	else
	{
		if (!computationsFile.eof()){
			cout << endl << "ERROR: The operation: " << "'"<< stringOperation <<"' is not valid." << endl;
			operation = INVALID;
		}
	}
	return operation;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: NegateOrSubtract
//Input/Output: computationsFile: filestream
//				struct: commandFromFile
//Output: operation: an enumerated type
//This function decides whether the operation is subtraction or negation and returns the appropiate enum type
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OperationTypeT NegateOrSubtract(ifstream & computationsFile,command & commandFromFile, OperationTypeT operation){

	bool valid = false;

	//take in the rest of the command storing it's parts where necessary
	computationsFile >> commandFromFile.operand1Representation;
	commandFromFile.operand2Representation = TakeInRestOfCommand(computationsFile);

	//check to see if the operands are valid
	valid = CheckForValidOperand(commandFromFile.operand2Representation, valid);
	
	if (valid == true){
		operation = SUBTRACTION;
	}
	else{
		operation = NEGATION;
		commandFromFile.operand2Representation = "empty";
		commandFromFile.firstOperands_NumberSystem = EMPTY;
	}

	return operation;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: TakeInRestOfCommand
//Input: operation: the operation of the computation
//Input/Output: computationsFile: filestream
//				struct: commandFromFile
//Output: the type of operation the computation will be
//This function takes in the rest of a computation line
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string TakeInRestOfCommand(ifstream & computationsFile){

	string str;
	int spacePos;

	getline (computationsFile,str);

	if (str == ""){
		//removes the additional white space in front of the string if theres is any
		if (str.length() != 0){
			str.erase(0,1);

			//gets rid of the comment if there is one
			spacePos = str.find(' ');
			if (spacePos != string::npos){
				str.erase(spacePos,str.length());
			}
		}
	}
	
	return str;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: CheckForValidOperand
//Input/Output: computationsFile: filestream
//Output: str: a string containing the rest of a computation after the first operand
//This function checks for a valid operation and returns a boolean flag
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool CheckForValidOperand(string str, bool valid){

	//if it is a register, then it is a valid operand
	if  ((str == "A")  ||
		 (str == "B")  ||
		 (str == "C")  ||
		 (str == "D")){
		valid = true;
	}

	//if it has a colon and is at least 6 characters then it will be assumed as valid entry
	if ((str.find(':')!=string::npos) &&
		(str.length() >= 6)){
		valid = true;
	}

	return valid;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: GetArguments
//Input: str: the computation string
//       valid: a bool to determine if the operand is valid
//Input/Output: struct: commandFromFile
//Output: the bool
//This function determines the number of arguments
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GetArguments(CPU & integerCalculator, ifstream & computationsFile, command & commandFromFile){

	commandFromFile.numberOfOperands = GetNumberOfOperands(commandFromFile); //Find and store number of operands
	StoreOperands(computationsFile, commandFromFile);                        //store the operands based on how many there should be
	CheckIfNegative(commandFromFile);                                        //check and account for it being negative

	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: GetNumberOfOperands
//Input:
//Input/Output: computationsFile: filestream
//				integerCalculator: the accumulator and memory units
//Output:
//This function determines the number of operands
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GetNumberOfOperands(command & commandFromFile){

	//look at the operation and decide how many operands this command has
	switch (commandFromFile.operation)
	{
		case ADDITION:
		case SUBTRACTION:
		case MULTIPLICATION:
		case DIVISION:
		case MODULATION:
		case POWER:
			commandFromFile.numberOfOperands = 2;
			break;
		case ADD:
		case SUBTRACT:
		case MULTIPLY:
		case DIVIDE:
		case REMAINDER:
		case RAISE:
		case NEGATION:
		case STORE:
		case LOAD:
		case SYSTEM:
			commandFromFile.numberOfOperands = 1;
		break;
		case PRINT:
		case DUMP:
			commandFromFile.numberOfOperands = 0;
			break;
	}
	return commandFromFile.numberOfOperands;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: StoreOperands
//Input:
//Input/Output: commandFromFile: the command from the computation file
//Output: the number of operands
//This function stores the operands
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void StoreOperands(ifstream & computationsFile, command & commandFromFile){

	string comment;
	//do not perform if the oepration is negation or subtraction because if it was, those values have already been stored
	if ((commandFromFile.operation != NEGATION) && (commandFromFile.operation != SUBTRACTION)){
		//take in operands based on how many operands there should be
		//*applying empty is not necessary. It will not appear anywhere in output, but will remain for testing/expansion
		switch (commandFromFile.numberOfOperands)
		{
			case 2:
				computationsFile >> commandFromFile.operand1Representation >> commandFromFile.operand2Representation;
				getline (computationsFile,comment);
				break;
			case 1:
				computationsFile >> commandFromFile.operand1Representation;
				commandFromFile.operand2Representation = "empty";
				getline (computationsFile,comment);
				break;
			case 0:
				commandFromFile.operand1Representation = "empty";
				commandFromFile.operand2Representation = "empty";
				getline (computationsFile,comment);
			break;
		}
	}
	
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: CheckIfNegative
//Input/Output: computationsFile: filestream
//              commandFromFile: the command from the computation file
//This function checks if the operand is negative and accounts for it
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CheckIfNegative(command & commandFromFile){

	//check both operands for a negative sign.  If it's found, erase it and account for it
	if (commandFromFile.operand1Representation[0] == '-'){
		commandFromFile.operand1Negative = true;
		commandFromFile.operand1Representation.erase(0,1);
	}
	else
	{
		commandFromFile.operand1Negative = false;
	}

		
	if (commandFromFile.operand2Representation[0] == '-'){
		commandFromFile.operand2Negative = true;
		commandFromFile.operand2Representation.erase(0,1);
	}
	else
	{
	commandFromFile.operand2Negative = false;
	}

	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: ProcessCommand
//Input/Output: commandFromFile: the command from the computation file
//This function decides where to branch off in order to process the command
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ProcessCommand(CPU & integerCalculator, command & commandFromFile){

	//based on the operand, decide what function should be performed to process the command
	switch(commandFromFile.operation)
	{
		case ADDITION:
		case SUBTRACTION:
		case MULTIPLICATION:
		case DIVISION:
		case MODULATION:
		case POWER:
		case ADD:
		case SUBTRACT:
		case MULTIPLY:
		case DIVIDE:
		case REMAINDER:
		case RAISE:
		case NEGATION:
			PerformCalculation(integerCalculator, commandFromFile);
		break;
		case LOAD:
			Load(integerCalculator, commandFromFile);
		break;
		case STORE:
			Store(integerCalculator, commandFromFile);
		break;
		case PRINT:
			Print(integerCalculator);
		break;
		case SYSTEM:
			integerCalculator.accumulatorOutputSystem = StringToNumberSystem(commandFromFile.operand1Representation);
			cout << "Output System changed to " << commandFromFile.operand1Representation << endl;
		break;
		case DUMP:
			Dump(integerCalculator);
	}
	
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: Load
//Input:
//Input/Output: commandFromFile: the command from the computation file
//				integerCalculator: the accumulator and memory units
//Output:
//This function performs the load function and assigns the accumulator one of the register values
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Load(CPU & integerCalculator, command commandFromFile){

	//loads a specific register into the accumulator
	if (commandFromFile.operand1Representation == "A"){
		integerCalculator.accumulator = integerCalculator.memoryLocationA;
	}
	else if (commandFromFile.operand1Representation == "B"){
		integerCalculator.accumulator = integerCalculator.memoryLocationB;
	}
	else if (commandFromFile.operand1Representation == "C"){
		integerCalculator.accumulator = integerCalculator.memoryLocationC;
	}
	else if (commandFromFile.operand1Representation == "D"){
		integerCalculator.accumulator = integerCalculator.memoryLocationD;
	}

	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: Store
//Input: commandFromFile: the command from the computation file
//Input/Output: integerCalculator: the accumulator and memory units
//This function stores the accumulator into one of the registers
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Store(CPU & integerCalculator, command commandFromFile){

	//stores the accumulator value into a specific register
	if (commandFromFile.operand1Representation == "A"){
		integerCalculator.memoryLocationA = integerCalculator.accumulator;
	}
	else if (commandFromFile.operand1Representation == "B"){
		integerCalculator.memoryLocationB = integerCalculator.accumulator;
	}
	else if (commandFromFile.operand1Representation == "C"){
		integerCalculator.memoryLocationC = integerCalculator.accumulator;
	}
	else if (commandFromFile.operand1Representation == "D"){
		integerCalculator.memoryLocationD = integerCalculator.accumulator;
	}

	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: Print
//Input: integerCalculator: the accumulator and memory units
//This function prints out the accumulator to the user
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Print(CPU integerCalculator){
	
	cout << "Accumulator: "; OutputFinalResult(integerCalculator);
	
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: Dump
//Input: integerCalculator: the accumulator and memory units
//This function dumps all the registers and the accumulator back to the user
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Dump(CPU integerCalculator){
	
	cout << "Accumulator: " << integerCalculator.accumulator << endl;
	cout << "Register A: " << integerCalculator.memoryLocationA << endl;
	cout << "Register B: " << integerCalculator.memoryLocationB << endl;
	cout << "Register C: " << integerCalculator.memoryLocationC << endl;
	cout << "Register D: " << integerCalculator.memoryLocationD << endl;
	
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: PerformCalculation
//Input:
//Input/Output: integerCalculator: the accumulator and memory units
//This function decides what steps it needs to take in order to perform the calculation
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PerformCalculation(CPU & integerCalculator, command & commandFromFile){

	//determines the number system and then converts the operand into decimal
	switch (commandFromFile.numberOfOperands){
		case 2: commandFromFile.secondOperands_NumberSystem = DetermineNumberSystem(commandFromFile.operand2Representation);
				commandFromFile.operand2Value = ConvertToDecimal(commandFromFile.secondOperands_NumberSystem,commandFromFile.operand2Representation, integerCalculator);
		case 1: commandFromFile.firstOperands_NumberSystem = DetermineNumberSystem(commandFromFile.operand1Representation);
				commandFromFile.operand1Value = ConvertToDecimal(commandFromFile.firstOperands_NumberSystem, commandFromFile.operand1Representation, integerCalculator);
	}

	//converts to negative if needed, and calulates the answer
	ConvertToNegative (commandFromFile);
	Calculate(integerCalculator, commandFromFile);

	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: DetermineNumberSystem
//Input/Output: commandFromFile: the command from the computation file
//Output: the Number System
//This function find the number system of each operand value
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OperandNumberSystemT DetermineNumberSystem(string & str){

	
	OperandNumberSystemT NumberSystem;
	int colonPosition;
	string strNumberSystem;
	strNumberSystem = str;

	//search for a colon
	colonPosition = str.find(":");

	//erase the colon and store the following as the number system. If colon does not exist, it is assumed to be a register
	if (colonPosition != string::npos){
		strNumberSystem = str.substr (colonPosition + 1);
		str.erase (colonPosition);
	}
	//convert the string into an enumerated data type
	NumberSystem = StringToNumberSystem(strNumberSystem);



	return NumberSystem;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: ConvertToDecimal
//Input/Output: the string of the command
//Output: the integer value of the operand
//This function converts a string number into a decimal number
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ConvertToDecimal(OperandNumberSystemT NumberSystem, string operandString, CPU integerCalculator){
	int operandValue;
	//based on the number system, decide what function should be called to make the conversion into integer
	switch (NumberSystem){
		case DCML:
			operandValue = atoi(operandString.c_str());
			break;
		case BINY:
			operandValue = BinaryToDecimal(operandString);
			break;
		case HEXA:
			operandValue = BaseToDecimal(operandString, 16);
			break;
		case TRIN:
			operandValue = BaseToDecimal(operandString, 3);
			break;
		case MURN:
			operandValue = UrnfieldToDecimal(operandString);
			break;
		case MMAY:
			operandValue = MayanToDecimal(operandString);
			break;
		case POSI:
			operandValue = PositionlessToDecimal(operandString);
			break;
		case EMPTY:
			operandValue = RegisterValue(operandString, integerCalculator);
			break;
	}

	return operandValue;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: BinaryToDecimal
//Input: numbersystem, operand string, integercalculator
//Output: the integer value of the operand
//This function converts from binary to decimal
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int BinaryToDecimal(string operandString){

	int operandValue = 0;
	int operandLength;
	string character;

	operandLength = operandString.length();

	//loop through the string searching for 'T's and apply the base formula based on the position of 'T' within the string
	for(int i = 0; i != operandLength; i++){
		character = operandString[i];
		if (character == "T"){
			operandValue+= pow(2,(operandLength - (i+1)));
		}
	}
	return operandValue;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: BaseToDecimal
//Input: the string operand
//Output: the integer value of the operand
//This function converts from a specific base into a decimal
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int BaseToDecimal(string operandString, int base){
	
	int operandValue = 0;
	int operandLength;
	int power;
	string character;

	power = operandString.length();
	operandLength = operandString.length();

	//loop through the string and apply the base formula for the string values that are encountered
	for(int i = 0; i!=operandLength; power--, i++){
		character = operandString[i];
		
		if (character == "1"){
			operandValue += 1 * (pow(base,power - 1));
		}
		else if (character == "2"){
			operandValue += 2 * (pow(base,power - 1));
		}
		else if (character == "3"){
			operandValue += 3 * (pow(base,power - 1));
		}
		else if (character == "4"){
			operandValue += 4 * (pow(base,power - 1));
		}
		else if (character == "5"){
			operandValue += 5 * (pow(base,power - 1));
		}
		else if (character == "6"){
			operandValue += 6 * (pow(base,power - 1));
		}
		else if (character == "7"){
			operandValue += 7 * (pow(base,power - 1));
		}
		else if (character == "8"){
			operandValue += 8 * (pow(base,power - 1));
		}
		else if (character == "9"){
			operandValue += 9 * (pow(base,power - 1));
		}
		else if (character == "A"){
			operandValue += 10 * (pow(base,power - 1));
		}
		else if (character == "B"){
			operandValue += 11 * (pow(base,power - 1));
		}
		else if (character == "C"){
			operandValue += 12 * (pow(base,power - 1));
		}
		else if (character == "D"){
			operandValue += 13 * (pow(base,power - 1));
		}
		else if (character == "E"){
			operandValue += 14 * (pow(base,power - 1));
		}
		else if (character == "F"){
			operandValue += 15 * (pow(base,power - 1));
		}
	}

	return operandValue;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: UrnfieldToDecimal
//Input: the base to be used in the formula, and the operand string
//Output: the integer value of the operand
//This function converts from utnfield to decimal
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int UrnfieldToDecimal(string operandString){

	int operandValue = 0;
	int operandLength;
	string character;
	
	operandLength = operandString.length();

	//loop through the string and accumulate values into a total as each symbol is examined
	for(int i = 0; i != operandLength; i++){
		character = operandString[i];
		
		if (character == "/"){
			operandValue+= 1;
		}
		else if (character == "\\"){
			operandValue+= 5;
		}
		else if (character == "("){
			operandValue+= 25;
		}
		else if (character == ")"){
			operandValue+= 125;
		}
		else if (character == "["){
			operandValue+= 625;
		}
		else if (character == "]"){
			operandValue+= 3125;
		}
	}

	
	return operandValue;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: MayanToDecimal
//Input: the string operand
//Output: the integer value of the operand
//This function converts from mayan to decimal
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MayanToDecimal(string operandString){
	
	int operandValue = 0;
	int numberOfCommas = 0;
	int pos = 0;
	int numberPart = 0;
	int operandLength;
	string character;
	int power;
	
	
	operandLength = operandString.length();
	//cycle through finding commas in the mayan expression
	pos = operandString.find(",", pos);
	while (pos != string::npos){
		numberOfCommas+=1;
		pos = operandString.find(",", pos+1);
	}

	power = numberOfCommas;

	//based on the postion of the comma, continue to cycle through the string and accumulate
	//a total by converting each symbol and applying the base formula
	for(int i = 0; i != operandLength; i++){
		character = operandString[i];
		
		if (character == "."){
			numberPart+= 1;
		}
		else if (character == "|"){
			numberPart+= 5;
		}
		else if (character == ","){
			operandValue += numberPart * (pow(20,power));
			numberPart = 0;
			power--;
		}
	}
	
	operandValue += numberPart;

	return operandValue;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: PositionlessToDecimal
//Input: the string operand
//Output: the integer value of the operand
//This function converts from positionless to decimal
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int PositionlessToDecimal(string operandString){
	
	int operandValue = 0;
	int operandLength;
	string character;
	
	operandLength = operandString.length();

	//cycle through each string character translating the symbol and adding it to the total
	for(int i = 0; i != operandLength; i++){
		character = operandString[i];
		
		if (character == "I"){
			operandValue+= 1;
		}
		else if (character == "X"){
			operandValue+= 10;
		}
		else if (character == "M"){
			operandValue+= 100;
		}
		else if (character == "C"){
			operandValue+= 1000;
		}
		else if (character == "K"){
			operandValue+= 10000;
		}
		else if (character == "G"){
			operandValue+= 100000;
		}
		else if (character == "T"){
			operandValue+= 1000000;
		}
		else if (character == "P"){
			operandValue+= 10000000;
		}
	}
	
	return operandValue;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: RegisterValue
//Input: the string operand
//Output: the integer value of the operand
//This function stores the register values into the correct operand interger holders
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int RegisterValue(string operandString, CPU integerCalculator){
	int operandValue;

	//if one of the operands is a register, store that register value into the operand so it can be used for calculation
	if (operandString == "A"){
		operandValue = integerCalculator.memoryLocationA;
	}
	else if (operandString == "B"){
		operandValue = integerCalculator.memoryLocationB;
	}
	else if (operandString == "C"){
		operandValue = integerCalculator.memoryLocationC;
	}
	else if (operandString == "D"){
		operandValue = integerCalculator.memoryLocationD;
	}

	return operandValue;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: ConvertToNegative
//Input: integerCalculator: the accumulator and memory units, and the string operand
//Output: the integer value of the operand
//This function converts the operand to a negative and accounts for it
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ConvertToNegative (command & commandFromFile){

	//convert back to negative, so the calculation can be done properly in integer format
	if (commandFromFile.operand1Negative == true){
		commandFromFile.operand1Value *= -1;
	}
	
	if (commandFromFile.operand2Negative == true){
		commandFromFile.operand2Value *= -1;
	}

	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: Calculate
//Input/Output: commandFromFile: the command from the computation file
//This function performs the interger calculation on the two operands
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Calculate(CPU & integerCalculator, command commandFromFile){

	//based on the operation type perform the bastic integer calculation
	switch (commandFromFile.operation){
		case ADDITION:
			integerCalculator.accumulator = commandFromFile.operand1Value + commandFromFile.operand2Value;
			break;
		case SUBTRACTION:
			integerCalculator.accumulator = commandFromFile.operand1Value - commandFromFile.operand2Value;
			break;
		case MULTIPLICATION:
			integerCalculator.accumulator = commandFromFile.operand1Value * commandFromFile.operand2Value;
			break;
		case DIVISION:
			integerCalculator.accumulator = commandFromFile.operand1Value / commandFromFile.operand2Value;
			break;
		case MODULATION:
			integerCalculator.accumulator = commandFromFile.operand1Value % commandFromFile.operand2Value;
			break;
		case POWER:
			integerCalculator.accumulator = pow(commandFromFile.operand1Value,commandFromFile.operand2Value);
			break;
		case ADD:
			integerCalculator.accumulator += commandFromFile.operand1Value;
			break;
		case SUBTRACT:
			integerCalculator.accumulator -= commandFromFile.operand1Value;
			break;
		case MULTIPLY:
			integerCalculator.accumulator *= commandFromFile.operand1Value;
			break;
		case DIVIDE:
			integerCalculator.accumulator /= commandFromFile.operand1Value;
			break;
		case REMAINDER:
			integerCalculator.accumulator %= commandFromFile.operand1Value;
			break;
		case RAISE:
			integerCalculator.accumulator = pow(integerCalculator.accumulator,commandFromFile.operand1Value);
			break;
		case NEGATION:
			integerCalculator.accumulator = commandFromFile.operand1Value *-1;
			break;
	}
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: StringToNumberSystem
//Input: commandFromFile: the command from the computation file
//Input/Output: integerCalculator: the accumulator and memory units
//Output: The operand of the number system
//This function examines a string and assigns an appropiate value to an enumerated data type
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OperandNumberSystemT StringToNumberSystem(string str){
	OperandNumberSystemT NumberSystem;

	//examines strings and stores a value into an enumerated type
	if (str == "dcml"){
		NumberSystem = DCML;
	}
	else if (str == "biny"){
		NumberSystem = BINY;
	}
	else if (str == "hexa"){
		NumberSystem = HEXA;
	}
	else if (str == "trin"){
		NumberSystem = TRIN;
	}
	else if (str == "murn"){
		NumberSystem = MURN;
	}
	else if (str == "mmay"){
		NumberSystem = MMAY;
	}
	else if (str == "posi"){
		NumberSystem = POSI;
	}
	else{
		NumberSystem = EMPTY;
	}

	return NumberSystem;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: Output
//Input: the integer calculator and the computation struct
//This function  decides how to output the results
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Output(CPU integerCalculator, command commandFromFile){

	//output the result unless it's one of the following commands because they had already outputed a result
	if ((commandFromFile.operation != LOAD)  &&
		(commandFromFile.operation != STORE) &&
		(commandFromFile.operation != SYSTEM)&&
		(commandFromFile.operation != PRINT) &&
	    (commandFromFile.operation != DUMP)){
		ShowResults(integerCalculator);
	   }
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: ShowResults
//Input: integerCalculator: the accumulator and memory units
//       commandFromFile: the command from the computation file
//This function decides how to show the results
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ShowResults(CPU integerCalculator){

	//if it's decimal output, there is no need to convert back to string
	if (integerCalculator.accumulatorOutputSystem == DCML){
		cout << integerCalculator.accumulator << ":dcml" << endl;
	}
	else{
		//remove the negative if there is one inorder to make the conversion
		CheckAcummulatorNegative(integerCalculator);
		OutputFinalResult(integerCalculator);
	}
	
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: ConvertToNumberSystem
//Input: integerCalculator: the accumulator and memory units
//Output: the string of the number system
//This function converts an integer back into a number system
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ConvertToNumberSystem(CPU integerCalculator){

	string answer = "";
	
	//based on the system output, decide what type of number system to convert the int back into
	switch (integerCalculator.accumulatorOutputSystem){
		case BINY:
			answer = DecimalToBinary(integerCalculator,answer);
			break;
		case HEXA:
			answer = DecimalToBase(integerCalculator,answer, 16);
			break;
		case TRIN:
			answer = DecimalToBase(integerCalculator,answer, 3);
			break;
		case MURN:
			answer = DecimalToUrnfield(integerCalculator,answer);
			break;
		case MMAY:
			answer = DecimalToMayan(integerCalculator,answer);
			break;
		case POSI:
			answer = DecimalToPositionless(integerCalculator,answer);
		case EMPTY:
			break;
	}

	return answer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: DecimalToBinary
//Input: integerCalculator: the accumulator and memory units, the string of the accumulator
//Input/Output:
//Output: the string representation of the integer in a specific number system
//This function converts from decimal to binary
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string DecimalToBinary(CPU integerCalculator,string answer){
	
	int remainder;
	string temp;

	//divide and mod the int by base 2 and use the result to decide whether the characte is a T or an F
	while (integerCalculator.accumulator != 0) {
		remainder = integerCalculator.accumulator%2;
		integerCalculator.accumulator = integerCalculator.accumulator/2;

		if (remainder == 0){
			temp = "F";
		}
		else
		{
			temp = "T";
		}
		
		temp += answer;
		answer = temp;
	}

	return answer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: DecimalToBase
//Input: integerCalculator: the accumulator and memory units, the string of the operand and it's base
//Output: the string representation of the integer in a specific number system
//This function converts from a specific base into a decimal
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string DecimalToBase(CPU integerCalculator,string answer, int base){

	float remainderFloat;
	int remainder;
	string temp;

	//divide and mod by the base and use the result to determine the next character in the based number system
	while (integerCalculator.accumulator != 0) {
		remainder = integerCalculator.accumulator%base;
		integerCalculator.accumulator = integerCalculator.accumulator/base;

		//remainder = remainderFloat*base;

		switch (remainder){
			case 0:
				temp = "0";
				break;
			case 1:
				temp = "1";
				break;
			case 2:
				temp = "2";
				break;
			case 3:
				temp = "3";
				break;
			case 4:
				temp = "4";
				break;
			case 5:
				temp = "5";
				break;
			case 6:
				temp = "6";
				break;
			case 7:
				temp = "7";
				break;
			case 8:
				temp = "8";
				break;
			case 9:
				temp = "9";
				break;
			case 10:
				temp = "A";
				break;
			case 11:
				temp = "B";
				break;
			case 12:
				temp = "C";
				break;
			case 13:
				temp = "D";
				break;
			case 14:
				temp = "E";
				break;
			case 15:
				temp = "F";
				break;
		}

		temp += answer;
		answer = temp;
	}
	

	return answer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: DecimalToUrnfield
//Input: integerCalculator: the accumulator and memory units, the string of the operand
//Output: the string representation of the integer in a specific number system
//This function converts from decimal to urnfield
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string DecimalToUrnfield(CPU integerCalculator,string answer){

	
	int remainder;
	string temp;

	//check the remaining value of the integer form and decide what symbols of urnfield can continue to fit in the string
	while (integerCalculator.accumulator != 0) {
		if (integerCalculator.accumulator >= 5){
			
			remainder = integerCalculator.accumulator%5;
			integerCalculator.accumulator = integerCalculator.accumulator/5;
			temp = "\\";
		}
		else if (integerCalculator.accumulator >= 25){

			remainder = integerCalculator.accumulator%25;
			integerCalculator.accumulator = integerCalculator.accumulator/25;
			temp = "(";

		}
		else if (integerCalculator.accumulator >= 125){

			remainder = integerCalculator.accumulator%125;
			integerCalculator.accumulator = integerCalculator.accumulator/125;
			temp = ")";

		}
		else if (integerCalculator.accumulator >= 625){

			remainder = integerCalculator.accumulator%625;
			integerCalculator.accumulator = integerCalculator.accumulator/625;
			temp = "[";

		}
		else if (integerCalculator.accumulator >= 3125){

			remainder = integerCalculator.accumulator%3125;
			integerCalculator.accumulator = integerCalculator.accumulator/3125;
			temp = "]";

		}
		else
		{
			integerCalculator.accumulator-=1;
			temp = "/";
		}
		
		temp += answer;
		answer = temp;
	}

	return answer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: DecimalToMayan
//Input: integerCalculator: the accumulator and memory units, the string of the operand
//Output: the string representation of the integer in a specific number system
//This function converts from decimal to mayan
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string DecimalToMayan(CPU integerCalculator,string answer){

	int numberOfSections = 0;
	int mayanPart = 0;

	//aply algorithm to find the number of sections
	numberOfSections = CountMayanSections(integerCalculator, numberOfSections);

	//sycle through the number of sections while building the string
	for (;numberOfSections != 0; numberOfSections--){
		mayanPart = FindMayanPart(integerCalculator, numberOfSections);
		answer += BuildMayanString (integerCalculator, numberOfSections, mayanPart);
		
		if (numberOfSections != 1){
			answer += ",";
		}
	}

return answer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: CountMayanSections
//Input: integerCalculator: the accumulator and memory units, the number of mayan sections found
//Output: number of myan sections
//This function counts the number of sections that are in the mayan representation of the int
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CountMayanSections(CPU integerCalculator, int numberOfSections){

	int testNumber = 0;
	int power = 0;

		//decide how many sections there are based on what numbers can fit into the base formula
		while ((pow(20,power)) < integerCalculator.accumulator){
			power++;
			numberOfSections++;
		}
		
	return numberOfSections;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: FindMayanPart
//Input: integerCalculator: the accumulator and memory units, the number of mayan sections found
//Output: the integer value of the mayan part
//This function calculates the integer value of a specific mayan part
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int FindMayanPart(CPU integerCalculator, int numberOfSections){

	int power = (numberOfSections - 1);
	int mayanPart = 0;

	//apply and increment a value in the base formula to discover the integer of the mayan part
	while ((mayanPart * (pow(20,power))) <= integerCalculator.accumulator){
		mayanPart++;
	}

	return mayanPart -1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: BuildMayanString
//Input: integerCalculator: the accumulator and memory units, the interger value of the mayan part
//Input/Output: the integer calculator and the number of mayan sections
//Output:  the string representation of the integer in a specific number system
//This function completes the myan string
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string BuildMayanString (CPU & integerCalculator, int & numberOfSections, int mayanPart){
	string answer = "";
	string temp = "";
	int orginalMayanPart = mayanPart;

	//use the integer value of the mayan part to see what symbol values will be able to fit in
	while (mayanPart >= 5){
		mayanPart -= 5;
		temp = "|";
		answer+= temp;
	}
	
	while(mayanPart > 0){
		mayanPart -= 1;
		temp = ".";
		temp += answer;
		answer = temp;
	}

	integerCalculator.accumulator-= (orginalMayanPart * (pow(20,numberOfSections - 1)));

	return answer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: DecimalToPositionless
//Input: the integer calculator and the string of the accumulator
//Input/Output: integerCalculator: the accumulator and memory units
//Output: the string representation of the integer in a specific number system
//This function converts from decimal to positionless
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string DecimalToPositionless(CPU integerCalculator,string answer){

	int remainder;
	string temp;

	//check the remaining value of the integer form and decide what symbols of positionless can continue to fit in the string
	while (integerCalculator.accumulator != 0) {
		if (integerCalculator.accumulator >= 10){
			
			remainder = integerCalculator.accumulator%10;
			integerCalculator.accumulator = integerCalculator.accumulator/10;
			temp = "X";
		}
		else if (integerCalculator.accumulator >= 100){
			
			remainder = integerCalculator.accumulator%100;
			integerCalculator.accumulator = integerCalculator.accumulator/100;
			temp = "M";
			
		}
		else if (integerCalculator.accumulator >= 1000){
			
			remainder = integerCalculator.accumulator%1000;
			integerCalculator.accumulator = integerCalculator.accumulator/1000;
			temp = "C";
			
		}
		else if (integerCalculator.accumulator >= 10000){
			
			remainder = integerCalculator.accumulator%10000;
			integerCalculator.accumulator = integerCalculator.accumulator/10000;
			temp = "K";
			
		}
		else if (integerCalculator.accumulator >= 100000){
			
			remainder = integerCalculator.accumulator%100000;
			integerCalculator.accumulator = integerCalculator.accumulator/100000;
			temp = "G";
			
		}
		else if (integerCalculator.accumulator >= 1000000){
			
			remainder = integerCalculator.accumulator%1000000;
			integerCalculator.accumulator = integerCalculator.accumulator/1000000;
			temp = "T";
			
		}
		else if (integerCalculator.accumulator >= 10000000){
			
			remainder = integerCalculator.accumulator%10000000;
			integerCalculator.accumulator = integerCalculator.accumulator/10000000;
			temp = "P";
			
		}
		else
		{
			integerCalculator.accumulator-=1;
			temp = "I";
		}
		
		temp += answer;
		answer = temp;
	}
	

	return answer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: CheckAcummulatorNegative
//Input/Output: integerCalculator: the accumulator and memory units
//This function handles the acumulator conversation if the number is perhaps negative
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CheckAcummulatorNegative(CPU & integerCalculator){

	//set the accumulator to positive if it's negative so that conversions can be performed
	if (integerCalculator.accumulator < 0){
		integerCalculator.accumulatorIsNegative = true;
		integerCalculator.accumulator *= -1;
	}

	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: OutputFinalResult
//Input: integerCalculator: the accumulator and memory units
//This function will output the final result
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputFinalResult(CPU integerCalculator){

	
	string str = "";

	//add the minus if the answer was originally negative
	if (integerCalculator.accumulatorIsNegative == true){
		str+= "-";
	}

	//if the answer is 0, show a zero for every number system
	if (integerCalculator.accumulator == 0){
	str += "0";
	}
	else{
	str += ConvertToNumberSystem(integerCalculator);
	}

	//if the number is not out of range, then output the final answer
	if ((integerCalculator.accumulator > 78124) && (integerCalculator.accumulatorOutputSystem == MURN)){
		cout << "The Modified Urnfield System can not express numbers higher than 78,124!" << endl;
	}
	else
	{
		str += stringOnSystem(integerCalculator);
		cout << str << endl;
	}

	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Module: stringOnSystem
//Input: integerCalculator: the accumulator and memory units
//Output: the string of the number system to add onto the end of the output
//This function adds on the number system to the end of the output
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string stringOnSystem(CPU integerCalculator){

	string str;

	//add on the system type to the end of the answer so it is more clear to the user what number system they are currently in
	switch (integerCalculator.accumulatorOutputSystem)
	{
		case BINY:
			str = ":biny";
			break;
		case HEXA:
			str = ":hexa";
			break;
		case TRIN:
			str = ":trin";
			break;
		case MURN:
			str = ":murn";
			break;
		case MMAY:
			str = ":mmay";
			break;
		case POSI:
			str = ":posi";
			break;
	}

	return str;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








