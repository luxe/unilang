#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

class CombinatoricsT{

	public:

		///This Is The Function That Must Be Called (It will call the second two)
		template<typename ...T>
		static void GenerateCombinations(T...containers);
		
	protected:
		
	private:

		///Recursive
		template<typename T0, typename ...T>
		static void Output(const std::string &row, const T0& cont0, T...cont_rest);
		
		///Output Each Individual Combination
		static void Output(const std::string &row);
};
template<class ...T> void CombinatoricsT::GenerateCombinations(T...containers) {
	
	Output("", containers...);
	return;
}
template<class T0, class ...T> void CombinatoricsT::Output(const std::string &row, const T0& cont0, T...cont_rest) {
	
	for (auto i = cont0.begin(); i != cont0.end(); ++i) {
		std::stringstream ss;
		ss << row << *i;
		Output(ss.str(), cont_rest...);
	}
	
	return;
}
void CombinatoricsT::Output(const std::string &row) {
	std::cout << row << " ";
}



int main(int argc, const char* argv []){


	vector< vector<string> > all;

	for (int i = 1; i < argc; ++i){

		all.push_back(vector<string>());
		
		
		//argv[i];
	}
	
	vector<string> v1 = {"1","2","3","4","5","6"}, v2 = {"a", "b", "c"}, v3 = {"H", "T", "H"};
	CombinatoricsT::GenerateCombinations(v1,v2,v3);
	
	return EXIT_SUCCESS;
}

