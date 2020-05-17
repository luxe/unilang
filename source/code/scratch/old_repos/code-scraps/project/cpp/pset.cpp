#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

void RemoveDuplicates(std::vector<std::string> & vec);
template <typename T> void ShowVector(std::vector<T> vec);

struct FormatSettingsT{
	std::string rightBracket;
	std::string leftBracket;
	std::string comma;
	std::string space;
	
	FormatSettingsT(void):
	rightBracket("}"),
	leftBracket("{"),
	comma(","),
	space(" ")
	{}
};

int main(int argc, char** argv){
	using namespace std;
	
	FormatSettingsT formatSettings;
	
	///turn all parameters into a single string
	string currentSet;
	for (int i = 1; i < argc-1; ++i){
		currentSet += argv[i];currentSet += " ";
	}
	currentSet += argv[argc-1];
	
	///parse string and store each element of the set into a vector
	vector<string> vec;
	string element;
	for (unsigned i(0); i < currentSet.length(); ++i){
		if (currentSet[i] != ','){
			element+= currentSet[i];
		}
		else{
			vec.push_back(element);
			element = "";
		}
	}
	vec.push_back(element);
	
	///Although it is mathematically legal to describe a Set containing duplicate elements,
	///they should be removed so that the Power Set generated does not contain these duplicates
	///NOTE: you know what, take a flag- make duplicates should be optional
	RemoveDuplicates(vec);
	
	///Build all subsets
	/*
	string subsets("{");
	auto s1 = vec.begin();
	auto e1 = vec.begin() + 1;
	auto s2 = s1, e2 = e1;
	
	for (unsigned i(0); i < vec.size(); ++i){
		for(unsigned j(0); j < i+1; ++j){    ///variadic length amount
				subsets+=*s2 + ',';
				++s2;
		}
	}*/
	

	
	
	
	
	
	
	
	
	
	string subsets("{");
	auto s1 = vec.begin();
	auto e1 = vec.begin() + 1;
	auto s2 = s1, e2 = e1;
	int i(0);
	
	while (e1 != vec.end()){ ///variadic length
		while (e2 != vec.end()+1){
			
			subsets+='{';
			while (s2 != e2){    ///variadic length amount
				subsets+=*s2 + ',';
				++s2;
			}
			subsets+="\b},";
			
			
			
			++i;
			s2 = s1; e2 = e1;
			s2+=i; e2+=i;
		}
		i = 0;
		++e1;
		s2 = s1, e2 = e1;
	}
	subsets+= "\b}";
	cout << subsets << endl;
	
	
	
	
	
	
	return EXIT_SUCCESS;
}

void RemoveDuplicates(std::vector<std::string> & vec){
	vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
	return;
}
template <typename T> void ShowVector(std::vector<T> vec){
	using namespace std;
	for (auto it = vec.begin(); it != vec.end(); ++it){
		cout << "[" << *it << "]";
	}
	
	return;
}
	