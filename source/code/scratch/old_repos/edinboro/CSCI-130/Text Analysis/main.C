/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PROGRAM INFO
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Trevor Hickey
// Dan Bennett
// Program 7 (Text Analysis)
// Program Due: 12-15-10

/*
Purpose:
-This program will analyze text files by reading in commands from another file.

Features:
-calculates the recurrences of a particular letter in a file
-calculates the number of spaces in a file
-calculates the number of tabs in a file
-calculates the number of letters in a file
-calculates the number of characters in a file
-calculates the number of words in a file
-calculates the number of lines in a file
-calculates the recurrences of a particular word in a file
-calculates the recurrences of a particular substring in a file

Error Checking:
-program will check the success of opening all files
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//INCLUDE FILES
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCTION DECLARATIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ClearScreen(); //clears the console of any text
string Commas(long inputNumber);//turns an integer into a string with commas(concept and coding by Ken Loomis)

void OpenTrials (ifstream & trials, bool & trialsSuccess);
void CheckExtraArgument (ifstream&trials, string&command, char&searchLetter, string&searchString, string&searchSubstring);
void OpenFilename(ifstream&document, string filename, bool&filenameSuccess);

int Letters (ifstream & document, char searchLetter);     //counts the number of occurrences of a non-white space letter in the file
int Spaces (ifstream & document);                         //counts the number of spaces in the file
int Tabs (ifstream & document);                           //counts the number of tabs in the file
int Alpha (ifstream & document);                          //counts the number of letters in the file
int Chars (ifstream & document);                          //counts the number of characters in the file
int Strings (ifstream & document);                        //counts the number of words in the file
int Lines (ifstream & document);                          //counts the number of lines in the file
int Words (ifstream & document, string searchString);     //counts the number of occurrences of a given word in the file
int Substr (ifstream & document, string searchSubstring); //counts the number of occurrences of a substring an the file

void OutputLetters(string&filename,int recurrenceOfLetter, char searchLetter);        //outputs the number of occurrences of a non-white space letter in the file
void OutputSpaces(string&filename,int numberOfSpaces);                                //outputs the number of spaces in the file
void OutputTabs(string&filename,int numberOfTabs);                                    //outputs the number of tabs in the file
void OutputAlpha(string&filename,int numberOfLetters);                                //outputs the number of letters in the file
void OutputChars(string&filename,int numberOfChars);                                  //outputs the number of characters in the file
void OutputStrings(string&filename,int numberOfWords);                                //outputs the number of words in the file
void OutputLines(string&filename,int numberOfLines);                                  //outputs the number of lines in the file
void OutputWords(string&filename,int recurrenceOfWord, string searchString);          //outputs the number of occurrences of a given word in the file
void OutputSubstr(string&filename,int recurrenceOfSubstring, string searchSubstring); //outputs the number of occurrences of a substring an the file

void OutputTotalResults(int totalRecurrenceOfLetter, int totalNumberOfSpaces, int totalNumberOfTabs, int totalNumberOfLetters, int totalNumberOfChars, int totalNumberOfWords, int totalNumberOfLines, int totalRecurrenceOfWord, int totalRecurrenceOfSubstring);

//outside files this program will interact with
const string TRIALS = "trials.inf";  //BRETT RHODES TOLD ME I COULD MAKE A CONSTANT GLOBAL
									 //SO I DIDN'T HAVE TO WORRY ABOUT PASSING IT THROUGH
									 //FUNCTIONS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int main()
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN FUNCTION VARIABLES
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//declares filestreams to open files
	ifstream trials;
	ifstream document;

	//holds the name of the file to perform actions on
	string filename;

	//holds the command that determines what actions should be performed on the file
	//*can hold: "letters", "spaces", "tabs", "alpha", "chars", "strings", "lines", "word", or "substr"
	string command;
	

	//holds numerical attributes about of a particular file
	int recurrenceOfLetter = 0,      //value determined by function Letters()
		numberOfSpaces = 0,          //value determined by function Spaces()
		numberOfTabs = 0,            //value determined by function Tabs()
		numberOfLetters = 0,         //value determined by function Alpha()
		numberOfChars = 0,           //value determined by function Chars()
		numberOfWords = 0,           //value determined by function Strings()
		numberOfLines = 0,           //value determined by function Lines()
		recurrenceOfWord = 0,        //value determined by function Words()
		recurrenceOfSubstring = 0;   //value determined by function Substr()

	//holds Total numerical attributes about of the file(s)
	int totalRecurrenceOfLetter = 0,      //value determined by function Letters()
		totalNumberOfSpaces = 0,          //value determined by function Spaces()
		totalNumberOfTabs = 0,            //value determined by function Tabs()
		totalNumberOfLetters = 0,         //value determined by function Alpha()
		totalNumberOfChars = 0,           //value determined by function Chars()
		totalNumberOfWords = 0,           //value determined by function Strings()
		totalNumberOfLines = 0,           //value determined by function Lines()
		totalRecurrenceOfWord = 0,        //value determined by function Words()
		totalRecurrenceOfSubstring = 0;   //value determined by function Substr()
		
	
	//holds the arguments for the different functions
	char searchLetter;            //used in function Letters()
	string searchString;          //used in function String()
	string searchSubstring;       //used in function Substr();

	bool trialsSuccess = true;   //tests whether the trials file was opened successfully
	bool filenameSuccess = true; //tests whether the requested filename was opened successfully
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	ClearScreen();
	OpenTrials (trials,trialsSuccess);  //opens the file holding the trials
	
	if (trialsSuccess){
		trials >> filename >> command;      //stores the filename and command from a line of the trials file
		while(!trials.eof()) {              //while not at the end of the trials file..
			CheckExtraArgument (trials,command,searchLetter,searchString,searchSubstring); //checks and stores any extra arguments
			OpenFilename(document,filename,filenameSuccess); //opens the requested filename and tests whether it was successful
			if (filenameSuccess){

				if (command == "letters"){
					recurrenceOfLetter = Letters (document, searchLetter);   //counts the number of occurrences of a non-white space letter in the file
					OutputLetters(filename,recurrenceOfLetter,searchLetter); //outputs a statement about how many occurrences of a non-white space letter in the file were found
					totalRecurrenceOfLetter += recurrenceOfLetter;           //adds this instance a recurring letter total to the total amount of letters that reoccurred
				}

				else if (command == "spaces"){
					numberOfSpaces = Spaces (document);    //counts the number of spaces in the file
					OutputSpaces(filename,numberOfSpaces); //outputs a statement about how many number of spaces in the file were found
					totalNumberOfSpaces += numberOfSpaces; //adds this instance a space total to the total amount of spaces found
				}

				else if (command == "tabs"){
					numberOfTabs = Tabs (document);    //outputs the number of tabs in the file
					OutputTabs(filename,numberOfTabs); //outputs a statement about how many tabs in the file were found
					totalNumberOfTabs += numberOfTabs; //adds this instance of tabs to the total amount of tabs found
				}

				else if (command == "alpha"){
					numberOfLetters = Alpha (document);      //counts the number of letters in the file
					OutputAlpha(filename,numberOfLetters);   //outputs a statement about how many letters in the file were found
					totalNumberOfLetters += numberOfLetters; //adds this instance letters total to the total amount of letters found
				}

				else if (command == "chars"){
					numberOfChars = Chars (document);    //counts the number of characters in the file
					OutputChars(filename,numberOfChars); //outputs a statement about how many characters in the file were found
					totalNumberOfChars += numberOfChars; //adds this instance of character total to the total amount of characters found
				}

				else if (command == "strings"){
					numberOfWords = Strings(document);     //counts the number of words in the file
					OutputStrings(filename,numberOfWords); //outputs a statement about how many words in the file were found
					totalNumberOfWords += numberOfWords;   //adds this instance word total to the total amount of words found
				}

				else if (command == "lines"){
					numberOfLines = Lines (document);    //counts the number of lines in the file
					OutputLines(filename,numberOfLines); //outputs a statement about how many lines in the file were found
					totalNumberOfLines += numberOfLines; //adds this instance line total to the total amount of lines found
				}

				else if (command == "word" || command == "words"){
					recurrenceOfWord = Words (document, searchString);   //outputs the number of occurrences of a given word in the file
					OutputWords(filename,recurrenceOfWord,searchString); //outputs a statement about how many occurrences of a word in the file were found
					totalRecurrenceOfWord += recurrenceOfWord;           //adds this instance a recurring word total to the total amount of words that reoccurred
				}

				else if (command == "substr"){
					recurrenceOfSubstring = Substr (document, searchSubstring);   //outputs the number of occurrences of a substring in the file
					OutputSubstr(filename,recurrenceOfSubstring,searchSubstring); //outputs a statement about how many occurrences of a substring in the file were found
					totalRecurrenceOfSubstring += recurrenceOfSubstring;          //adds this instance a recurring substring total to the total amount of substrings that reoccurred
				}


				document.close(); //close the file after performing one of the commands on it

				//stores the filename and command from a line of the trials file
				trials >> filename >> command;
			}
		}
	}

	cout << endl;
	OutputTotalResults(totalRecurrenceOfLetter,totalNumberOfSpaces,totalNumberOfTabs,totalNumberOfLetters,totalNumberOfChars,totalNumberOfWords,totalNumberOfLines,totalRecurrenceOfWord,totalRecurrenceOfSubstring);
	
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//clears the console of any text
void ClearScreen(){
	
	//creates 80 line breaks
	cout << string(80, '\n');
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
void OpenTrials (ifstream & trials, bool & trialsSuccess){

	//opens file which contains a list of trials
	//*files must be in the program's directory
	trials.open(TRIALS.c_str());
	
	//tests to make sure the file was opened
	if(!trials) {
		cout << endl << "ERROR: Failed to open " << "'"<< TRIALS <<"'." << endl
		<< "*please make sure you have the file '" << TRIALS <<"' " << "in the same directory as this program." <<endl << endl;
		
		trialsSuccess = false;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CheckExtraArgument (ifstream&trials, string&command, char&searchLetter, string&searchString, string&searchSubstring){

	//stores the argument if one exists
	if (command == "letters"){
		trials >> searchLetter;
	}
	
	else if (command == "word"){
		trials >> searchString;
	}
	
	else if (command == "substr"){
		trials >> searchSubstring;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OpenFilename(ifstream&document, string filename, bool&filenameSuccess){
	
	//opens file for analysis
	//*files must be in the program's directory
	document.open(filename.c_str());
	
	//tests to make sure the file was opened
	if(!document) {
		cout << endl << "ERROR: Failed to open " << "'"<< filename <<"'." << endl
		<< "*please make sure you have the file '" << filename <<"' " << "in the same directory as this program." <<endl << endl;
		filenameSuccess = false; //if the file does not open, skip doing any actions on that file
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Letters (ifstream & document, char searchLetter){
	
	/*although this holds useless data, information is stored into this variable so that
	the procedure can continue through and eventually reach the end of the file being analyzed */
	string uslessStringHolder;
	
	//holds the amount of words found in the file
	int counter = 0;
	
	//the position to start looking for a word
	int startpos = 0;
	
	while(!document.eof()) {
		
		getline (document,uslessStringHolder);
		startpos = uslessStringHolder.find_first_of(searchLetter);
		while (startpos != -1){
			counter++;
			startpos=uslessStringHolder.find_first_of(searchLetter,startpos+1);
		}
	}

	return counter;
				

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Spaces (ifstream & document){

	/*although this holds useless data, information is stored into this variable so that
	the procedure can continue through and eventually reach the end of the file being analyzed */
	string uslessStringHolder;
	
	//holds the amount of words found in the file
	int counter = 0;
	
	//the position to start looking for a word
	int startpos = 0;
	
	while(!document.eof()) {
		
		getline (document,uslessStringHolder);
		startpos = uslessStringHolder.find_first_of(" ");
		while (startpos != -1){
			counter++;
			startpos=uslessStringHolder.find_first_of(" ",startpos+1);
		}
	}
	
	return counter;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Tabs (ifstream & document){

	/*although this holds useless data, information is stored into this variable so that
	the procedure can continue through and eventually reach the end of the file being analyzed */
	string uslessStringHolder;
	
	//holds the amount of words found in the file
	int counter = 0;
	
	//the position to start looking for a word
	int startpos = 0;
	
	while(!document.eof()) {
		
		getline (document,uslessStringHolder);
		startpos = uslessStringHolder.find_first_of("\t");
		while (startpos != -1){
			counter++;
			startpos=uslessStringHolder.find_first_of("\t",startpos+1);
		}
	}
	
	return counter;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Alpha (ifstream & document){

	/* although this holds useless data, information is stored into this variable so that
	the procedure can continue through and eventually reach the end of the file being analyzed */
	string uslessStringHolder;
	
	//holds the amount of words found in the file
	int length = 0;

	//holds the current length of the word
	int wordLength;

	//inputs the current string and increments the counter
	document >> uslessStringHolder;
	
	while(!document.eof()) {
		length+= uslessStringHolder.length();
		wordLength= uslessStringHolder.length();
		
		//inputs the current string and increments the counter
		document >> uslessStringHolder;
	}


	return length;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Chars (ifstream & document){

	/* although this holds useless data, information is stored into this variable so that
	the procedure can continue through and eventually reach the end of the file being analyzed */
	string uslessStringHolder;
	
	//holds the amount of words found in the file
	int length = 0;
	
	//holds the current length of the word
	int wordLength;
	
	
	while(!document.eof()) {
		//takes in a line from the file and calculates it length
		getline (document,uslessStringHolder);
		length+= uslessStringHolder.length();
		wordLength= uslessStringHolder.length();
	}
	
	return length;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Strings (ifstream & document){

	/* although this holds useless data, information is stored into this variable so that
	the procedure can continue through and eventually reach the end of the file being analyzed */
	string uslessStringHolder;

	//holds the amount of words found in the file
	int counter = 0;

	//inputs the current string and increments the counter
	document >> uslessStringHolder;
	
	//while the end of the document is not reached..
	while(!document.eof()) {
		counter++;
		//inputs the current string and increments the counter
		document >> uslessStringHolder;
	}

	return counter;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Lines (ifstream & document){
	
	/* although this holds useless data, information is stored into this variable so that
	the procedure can continue through and eventually reach the end of the file being analyzed */
	string uslessStringHolder;
	
	//holds the amount of words found in the file
	int counter = 0;

	//inputs the current string and increments the counter
	getline (document,uslessStringHolder);

	//while the end of the document is not reached..
	while(!document.eof()) {
		counter++;
		//inputs the current string and increments the counter
		getline (document,uslessStringHolder);
	}

	return counter;


}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Words (ifstream & document, string searchString){
	
	/* although this holds useless data, information is stored into this variable so that
	the procedure can continue through and eventually reach the end of the file being analyzed */
	string uslessStringHolder;
	
	//holds the amount of words found in the file
	int counter = 0;


	//inputs the current string and increments the counter
	document >> uslessStringHolder;
	
	while(!document.eof()) {
		if (uslessStringHolder == searchString){
			counter++;
		}
	//inputs the current string and increments the counter
	document >> uslessStringHolder;
		
	}


	return counter;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Substr (ifstream & document, string searchSubstring){

	/*although this holds useless data, information is stored into this variable so that
	the procedure can continue through and eventually reach the end of the file being analyzed */
	string uslessStringHolder;
	
	//holds the amount of words found in the file
	int counter = 0;
	
	//the position to start looking for a word
	int startpos = 0;
	
	while(!document.eof()) {
		
		getline (document,uslessStringHolder);
		startpos = uslessStringHolder.find(searchSubstring);
		while (startpos != -1){
			counter++;
			startpos=uslessStringHolder.find(searchSubstring,startpos+1);
		}
	}
	
	return counter;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputLetters(string&filename,int recurrenceOfLetter, char searchLetter){
	
	//displays the number of occurrences of a non-white space letter from the file
	cout << "'" << filename << "' contained the letter '" << searchLetter <<"' " << Commas(recurrenceOfLetter) << " time";
	if (recurrenceOfLetter != 1) {
		cout << "s";
	}
	cout << "." << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputSpaces(string&filename,int numberOfSpaces){
	
	cout << "'" << filename << "' contained " << Commas(numberOfSpaces) << " space";
	if (numberOfSpaces != 1) {
		cout << "s";
	}
	cout << "." << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputTabs(string&filename,int numberOfTabs){

	cout << "'" << filename << "' contained " << Commas(numberOfTabs) << " tab";
	if (numberOfTabs != 1) {
		cout << "s";
	}
	cout << "." << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputAlpha(string&filename,int numberOfLetters){

	cout << "'" << filename << "' contained " << Commas(numberOfLetters) << " letter";
	if (numberOfLetters != 1) {
		cout << "s";
	}
	cout << "." << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputChars(string&filename,int numberOfChars){
	
	cout << "'" << filename << "' contained " << Commas(numberOfChars) << " character";
	if (numberOfChars != 1) {
		cout << "s";
	}
	cout << "." << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputStrings(string&filename,int numberOfWords){

	cout << "'" << filename << "' contained " << Commas(numberOfWords) << " word";
	if (numberOfWords != 1) {
		cout << "s";
	}
	cout << "." << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputLines(string&filename,int numberOfLines){
	
	cout << "'" << filename << "' contained " << Commas(numberOfLines) << " line";
	if (numberOfLines != 1) {
		cout << "s";
	}
	cout << "." << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputWords(string&filename,int recurrenceOfWord, string searchString){

	cout << "'" << filename << "' contained the word '" << searchString <<"' " << Commas(recurrenceOfWord) << " time";
	if (recurrenceOfWord != 1) {
		cout << "s";
	}
	cout << "." << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputSubstr(string&filename,int recurrenceOfSubstring, string searchSubstring){

	cout << "'" << filename << "' contained the substring '" << searchSubstring <<"' " << Commas(recurrenceOfSubstring) << " time";
	if (recurrenceOfSubstring != 1) {
		cout << "s";
	}
	cout << "." << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OutputTotalResults(int totalRecurrenceOfLetter, int totalNumberOfSpaces, int totalNumberOfTabs, int totalNumberOfLetters, int totalNumberOfChars, int totalNumberOfWords, int totalNumberOfLines, int totalRecurrenceOfWord, int totalRecurrenceOfSubstring){

	cout << " Recurring Letters: " << Commas(totalRecurrenceOfLetter) << endl;
	cout << "            Spaces: " << Commas(totalNumberOfSpaces) << endl;
	cout << "              Tabs: " << Commas(totalNumberOfTabs) << endl;
	cout << "           Letters: " << Commas(totalNumberOfLetters) << endl;
	cout << "        Characters: " << Commas(totalNumberOfChars) << endl;
	cout << "             Words: " << Commas(totalRecurrenceOfWord) << endl;
	cout << "        Substrings: " << Commas(totalRecurrenceOfSubstring) << endl << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////