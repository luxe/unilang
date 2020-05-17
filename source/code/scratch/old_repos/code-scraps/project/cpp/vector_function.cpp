//put this in jstd eventually

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

std::vector<std::string> StringToVector(std::string const& str, char const delimiter);

int main(){
	
	std::string str{"1 2     3 4  5 6    "};
	std::vector<std::string> vec{StringToVector(str, ' ')};
	
	
	//print the vector
	for(std::string const& item : vec){
		std::cout << "[" << item << "]";
	}
	
	
	return EXIT_SUCCESS;
}

std::vector<std::string> StringToVector(std::string const& str, char const delimiter){
	
	std::vector<std::string> vec;
	std::string element;
	
	
	//we are going to loop through each character of the string slowly building an element string.
	//whenever we hit a delimiter, we will push the element into the vector, and clear it to get ready for the next element
	for_each(begin(str),end(str),[&](char const ch){
		if(ch!=delimiter){
			element+=ch;
		}
		else{
			if (element.length()>0){
			vec.push_back(element);
			element.clear();
			}
		}
	});
	
	
	//push in the last element if the string does not end with the delimiter
	if (element.length()>0){
		vec.push_back(element);
	}
	
	
	return vec;
}