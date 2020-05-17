#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

char GetRandomASCII(void);
string ASCIIRepresentation(const char & randomChar);

int main(){
	srand (time(NULL));
	char randomChar = GetRandomASCII();
	int guess;
	int rounds;
	
	cout << "how many rounds? ";
	cin >> rounds;
	
	for (int i = 0; i < rounds; i++){
		cout << "[" << i << "] " << randomChar << ": ";
		cin >> guess;
		while (guess != randomChar){
			cout << "[" << i << "] " << randomChar << ": ";
			cin >> guess;
		}
		randomChar = GetRandomASCII();
	}




	return 0;
}

char GetRandomASCII(void){
	char randomChar = rand() % 128;
	return randomChar;
}
string ASCIIRepresentation(const char & randomChar){

	string ASCIIRepresentation = "";
	
	switch(randomChar){
		case 0: ASCIIRepresentation = "NUL (null)"; break;
		case 1: ASCIIRepresentation = "SOH (start of heading)"; break;
		case 2: ASCIIRepresentation = "STX (start of text)"; break;
		case 3: ASCIIRepresentation = "ETX (end of text)"; break;
		case 4: ASCIIRepresentation = "EOT (end of transmission)"; break;
		case 5: ASCIIRepresentation = "ENQ (enquiry)"; break;
		case 6: ASCIIRepresentation = "ACK (acknowledge)"; break;
		case 7: ASCIIRepresentation = "BEL (bell)"; break;
		case 8: ASCIIRepresentation = "BS (backspace)"; break;
		case 9: ASCIIRepresentation = "TAB (horizontal tab)"; break;
		case 10: ASCIIRepresentation = "LF (NL line feed, new line)"; break;
		case 11: ASCIIRepresentation = "VT (vertical tab)"; break;
		case 12: ASCIIRepresentation = "FF (NP form feed, new page)"; break;
		case 13: ASCIIRepresentation = "CR (carriage return)"; break;
		case 14: ASCIIRepresentation = "SO (shift out)"; break;
		case 15: ASCIIRepresentation = "SI (shift in)"; break;
		case 16: ASCIIRepresentation = "DLE (data link escape)"; break;
		case 17: ASCIIRepresentation = "DC1 (device control 1)"; break;
		case 18: ASCIIRepresentation = "DC2 (device control 2)"; break;
		case 19: ASCIIRepresentation = "DC3 (device control 3)"; break;
		case 20: ASCIIRepresentation = "DC4 (device control 4)"; break;
		case 21: ASCIIRepresentation = "NAK (negative acknowledge)"; break;
		case 22: ASCIIRepresentation = "SYN (synchronous idle)"; break;
		case 23: ASCIIRepresentation = "ETB (end of trans. block)"; break;
		case 24: ASCIIRepresentation = "CAN (cancel)"; break;
		case 25: ASCIIRepresentation = "EM (end of medium)"; break;
		case 26: ASCIIRepresentation = "SUB (substitute)"; break;
		case 27: ASCIIRepresentation = "ESC (escape)"; break;
		case 28: ASCIIRepresentation = "FS (file separator)"; break;
		case 29: ASCIIRepresentation = "GS (group separator)"; break;
		case 30: ASCIIRepresentation = "RS (record separator)"; break;
		case 31: ASCIIRepresentation = "US (unit separator)"; break;
		case 32: ASCIIRepresentation = "Space"; break;
		case 127: ASCIIRepresentation = "DEL"; break;
		default: ASCIIRepresentation += randomChar; break;
	}

	return ASCIIRepresentation;
}





