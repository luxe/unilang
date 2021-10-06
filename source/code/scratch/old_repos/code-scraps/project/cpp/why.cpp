//assk about how to fix accumulate implicit casting warning lost in the STL
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

template<class InputIt, class T>
T my_accumulate(InputIt first, InputIt last, T init)
{
    for (; first != last; ++first) {
        init = init + *first;
    }
    return init;
}
 
 
int main() {

//std::vector<double> d{0.5,0.5};
//double r = my_accumulate(d.begin(),d.end(),0);
//std::cout << r << std::endl;

std::array<int> array{1, 2, 1, 1, 2, 3, 1, 2, 3}
std::sort(array.begin(),array.end());

int most_frequent = 0;
int current = 0;
int count = 0;
for (auto it: array){
	if (it == current){
		++count;
	}
	else{
		
		if (count > most_frequent)
	}
}

}
