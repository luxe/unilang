#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;





int main(){
	
	
	return 0;
}

int GetTotalNumberOfSquaresInNbyNGrid(int n);/**
pre: the length and width of a square are passed in as the same variable
post: the number of unique squares that can be made are returned.

For Example:
+---+---+ passing in 2
|   |   | will return 5
+---+---+ all the squares together
|   |   | count as a square also
+---+---+

+---+---+---+---+
|   |   |   |   | In This Example:
+---+---+---+---+ 4 is passed in
|   |   |   |   | and 30 is returned
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
*/
int GetTotalNumberOfSquaresInNbyNGrid(int n){
	n+=1;
	int totalNumberOfSquares = 0;
	
	for(int i = 0; i < n; i++){
		totalNumberOfSquares+= pow(i,2);
	}
	
	return totalNumberOfSquares;
}
bool IsPrime1(double x) {
	if (x < 1) return false;
	int i;
	double y, z;
	
	y = sqrt(x);
	for (i = 2; i <= y; i++)
		if (modf(x / i, &z) == 0)
			return false;
		if (i <= y) return false;
		else return true;
}

bool IsPrime2(unsigned long long x)
{
	bool prime = x == 2 || x == 3 || (x > 3 && x % 2 != 0 && x % 3 != 0);
	unsigned long long sqrt = static_cast<unsigned long long>(std::sqrt(static_cast<double>(x)));
	
	for (unsigned long long i = 5; i <= sqrt; i += 6)
	{
		if (x % i == 0)
		{
			prime = false;
			break;
		}
		else if (x % (i + 2) == 0)
		{
			prime = false;
			break;
		}
	}
	
	return prime;
}

void PrintPrimeNumbers( int userInput1,  int userInput2){
	for ( int i = userInput1; i < userInput2+1; i++){
		if (is_it_prime(i)){
			cout << i << endl;
		}
	}
}


bool is_it_prime( int n){
	if (n <=1){return false;}
	for( int i = 2; i <= sqrt(n); i++){
		if ((n % i) == 0){return false;} //divides evenly- NOT PRIME!
	}
	return true; //no numbers divided evenly- PRIME!
}

static bool IsPrime3(int x){
	for (int i=2; i < x; i++){
		if (x%i == 0 && x%i ==1) return false;
	}
	return true;
}

unsigned int CountTrailingFactorialZeros(const unsigned int & number){
	
	int numberOfZeros = 0;
	const int BASE = 5;
	int raise = 1;
	int divider;
	
	while (pow(BASE,raise) <= number){
		divider = pow(BASE,raise);
		
		numberOfZeros+= number/divider;
		raise++;
	}
	
	return numberOfZeros;
}
unsigned int NumberOfTrailingFactorialZeros(const unsigned int & number){
	
	int numberOfZeros = 0;
	const int BASE = 5;
	int raise = 1;
	int divider;
	
	while (pow(BASE,raise) <= number){
		divider = pow(BASE,raise);
		
		numberOfZeros+= number/divider;
		raise++;
	}
	
	return numberOfZeros;
}
unsigned int CountTrailingZerosForFactorialNumber(const unsigned int & number){
	
	int numberOfZeros = 0;
	const int BASE = 5;
	int raise = 1;
	int divider;
	
	while (pow(BASE,raise) <= number){
		divider = pow(BASE,raise);
		
		numberOfZeros+= number/divider;
		raise++;
	}
	
	return numberOfZeros;
}
unsigned int NumberOfTrailingZerosForFactorialNumber(const unsigned int & number){
	
	int numberOfZeros = 0;
	const int BASE = 5;
	int raise = 1;
	int divider;
	
	while (pow(BASE,raise) <= number){
		divider = pow(BASE,raise);
		
		numberOfZeros+= number/divider;
		raise++;
	}
	
	return numberOfZeros;
}



















Conversions


template <class T, class U> U RandomNumberBetweenAndIncluding(T min, U max); //<cstdlib> srand (time(NULL));
template <class T> IsPalindrome(const T & phrase);

	ostringstream s;
	s << t;
	
	for (int i=0; i < phrase.length()-1; i++){
		if (tolower(phrase[i]) != tolower(phrase[phrase.length()-(i+1)]))
			{
				return false;
			}
		}
	return true;
	}
	
	template <class T> IsPalindrome(const T & phrase){
		
		ostringstream s;
		s << t;
		
		for (int i=0; i < phrase.length()-1; i++){
			if (tolower(phrase[i]) != tolower(phrase[phrase.length()-(i+1)]))
			{
				return false;
			}
		}
		return true;
	}
	
//number functions
template <class T> bool IsEven(T number);
template <class T> bool IsOdd(T number);
template <class T> T factorial(T number);
template <class T> T NumberOfDigits(T number);

//╔════════════════════════════════════╗
//║          STRING FUNCTIONS          ║
//╚════════════════════════════════════╝
//╔═════════╗
//║ Testers ║
//╚═════════╝
bool IsStringAllCapital(const string & str);
bool IsStringAllLowercase(const string & str);
bool IsStringAllLetters(const string & str);
bool IsStringAllDigits(const string & str);
bool IsStringAllSymbols(const string & str);

//╔══════════╗
//║ Counters ║
//╚══════════╝
int NumberOfCapitalLetters(string str);
int NumberOfLowercaseLetters(string str);
int NumberOfDigitCharacters(string str);
int NumberOfPunctuationCharacters(string str);
long NumberOfSubstringOccurances(string str, string substr, ...);

//╔════════════╗
//║ Converters ║
//╚════════════╝
string& CapitalizeFirstChar(string & str);
string& LowercaseFirstChar(string & str);
string& ConvertToAllCaps(string & str);
string& ConvertToAllLowercase(string & str);
string& ConvertToPigLatin(string & str);

//╔══════════════╗
//║ Transformers ║
//╚══════════════╝


//character functions

//conversions
template<class T> string AnythingToString(const T& t);
string TXTtoButtonCombination(string txt);
template<class T> string AddCommasToNumber(const T & initial);

int is_power(int x)
{
	return !((x-1) & x);
}


template <class T, class U> U RandomNumberBetweenAndIncluding(T min, U max){
	
	int randomNumber; //the returned number which is either the min, the max, or a number found in between
	int difference;  //the numerical magnitude found between the min and the max
	
	//to avoid dividing by zero, just return zero if the min and the max are both zero
	if ((max == 0) && (min == 0)){return 0;}
	
	//find the difference
	if ((max >= 0) && (min >= 0)){
		difference = max - min;
	}
	else if ((max >= 0) && (min < 0)){
		difference = (min*-1) + max;
	}
	else if ((max < 0) && (min < 0)){
		difference = (min*-1) - (max*-1);
	}
	
	randomNumber = (rand() % difference);

	if (randomNumber == 0){
		randomNumber = rand() %2;
		
		if (randomNumber == 1){
			randomNumber = difference;
		}
	}
	
	randomNumber = max - randomNumber;

	return randomNumber;
}


bool IsEven(int number){
	return (!(number & 1));
}
template <class T> bool IsEven(T number){
	return (!(number & 1));
}
template <class T> bool IsOdd(T number){
	return (!number & 1);
}
template <class T> T factorial(T number){
	return (number == 1 || number == 0) ? 1 : factorial(number - 1) * number;
}

string TXTtoButtonCombination(string txt){
	string buttonCombination;
	
	for (int i = 0; i < txt.length(); i++){
		
		if ((txt[i] < 97) && (txt[i] != 32)){
			buttonCombination+="*";
			txt[i] +=32;
		}
		
		switch(txt[i]){
			case ' ': buttonCombination+="#"; break;
			case 'c': buttonCombination+="2";
			case 'b': buttonCombination+="2";
			case 'a': buttonCombination+="2"; break;
			case 'f': buttonCombination+="3";
			case 'e': buttonCombination+="3";
			case 'd': buttonCombination+="3"; break;
			case 'i': buttonCombination+="4";
			case 'h': buttonCombination+="4";
			case 'g': buttonCombination+="4"; break;
			case 'l': buttonCombination+="5";
			case 'k': buttonCombination+="5";
			case 'j': buttonCombination+="5"; break;
			case 'o': buttonCombination+="6";
			case 'n': buttonCombination+="6";
			case 'm': buttonCombination+="6"; break;
			case 's': buttonCombination+="7";
			case 'r': buttonCombination+="7";
			case 'q': buttonCombination+="7";
			case 'p': buttonCombination+="7"; break;
			case 'v': buttonCombination+="8";
			case 'u': buttonCombination+="8";
			case 't': buttonCombination+="8"; break;
			case 'z': buttonCombination+="9";
			case 'y': buttonCombination+="9";
			case 'x': buttonCombination+="9";
			case 'w': buttonCombination+="9"; break;
		}
	}
	
	return buttonCombination;
}

template<class T> string AnythingToString(const T& t){
	ostringstream s;
	s << t;
	return s.str();
}

int NumberOfCapitalLetters(string str){
	int counter = 0;
	
	for (int i =0; i < str.length(); i++){
		if (str[i] >= 65 && str[i] <= 90){
			counter++;
		}
	}
	
	return counter;
}
int NumberOfLowercaselLetters(string str){
	int counter = 0;
	
	for (int i =0; i < str.length(); i++){
		if (str[i] >= 97 && str[i] <= 122){
			counter++;
		}
	}
	
	return counter;
}

bool IsStringAllDigits(const string & str){
	
	for (int i = 0; i < str.length(); i++){
		if !(str[i] >= '0' && str[i] <= '9'){
			return false;
		}
	}
	return true;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
