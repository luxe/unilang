#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

bool IsPalindrome(std::string str);
int main(int argc, char** argv, char** env){
	using namespace std;
	cout << boolalpha;
	
	///TRUE
	cout << IsPalindrome("") << '\n';
	cout << IsPalindrome("l") << '\n';
	cout << IsPalindrome("lol") << '\n';
	cout << IsPalindrome("lool") << '\n';
	cout << IsPalindrome("ll") << '\n';
	cout << IsPalindrome("racecar") << '\n';
	cout << IsPalindrome("Racecar") << '\n';
	cout << IsPalindrome("Race Car") << "\n\n";
	
	///FALSE
	cout << IsPalindrome("loll") << '\n';
	cout << IsPalindrome("llol") << '\n';
	cout << IsPalindrome("ololk") << '\n';
	cout << IsPalindrome("bad") << '\n';
	cout << IsPalindrome("test") << '\n';
	cout << IsPalindrome("lololo") << '\n';
	cout << IsPalindrome("zx") << '\n';
	
	return EXIT_SUCCESS;
}
bool IsPalindrome(std::string str){

	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	return std::equal(str.cbegin(),str.cbegin() + str.size()/2,str.crbegin(),[](const char& a, const char& b){return tolower(a) == tolower(b);});
}