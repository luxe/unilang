#include <iostream>
#include <string>

using namespace std;


bool IsRotation(const string & s1, const string & s2) {
	return (s1.length() == s2.length()) && ((s1+s1).find(s2) != string::npos);
}


int main(){
	
	string s1 = "rotation";
	string s2 = "nrotatio";
	
	cout << boolalpha;
	cout << IsRotation(s1,s2) << endl;
	
	return 0;
}