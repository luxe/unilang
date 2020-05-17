#include <iostream>
#include <vector>

using namespace std;

template<typename T> class Vector : std::vector<T> {
    using vector<T>::vector; // inherit all constructors
    // ... 
};

int main(){
	
	Vector<int> v;
}
