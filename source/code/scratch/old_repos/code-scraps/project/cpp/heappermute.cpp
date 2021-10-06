#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
     
     
//output a vector
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
	std::for_each(v.begin(), v.end(), [&os] (const T& t) { os << t << " "; });
	return os;
}
    

//heap permute
template <class T>
void HeapPermute(int n, T& t){
	if (n == 1)
		std::cout << t << '\n';
	else {
		for (int i = 0; i < n; i++) {
			HeapPermute(n-1, t);
		if (n % 2 == 1)
			std::swap(t[0], t[n-1]);
		else
			std::swap(t[i], t[n-1]);
		}
	}
	
	return;
}

//run heap permute
int main(){
	std::vector<int> v = { 1, 2, 3, 4};
	HeapPermute(v.size(), v);
	return 0;
}