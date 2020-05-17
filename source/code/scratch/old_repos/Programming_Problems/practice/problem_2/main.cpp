#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;


vector<int> Get_Knows();
void output(vector<vector<bool>> const& grid);
vector<bool> Get_Row(unsigned int const& length);
void Fill(vector<bool> & row, vector<int> const& knows);


int main() {
	
	unsigned number_of_lemons = 0;
	unsigned amount = 0;
	vector<vector<bool>> grid;
	
	cin >> number_of_lemons >> amount;
	decltype(Get_Knows()) knows;
	decltype(Get_Row(number_of_lemons)) row;
	for (int i = 0; i < number_of_lemons; ++i) {
		knows = Get_Knows();
		row = Get_Row(number_of_lemons);
		Fill(row, knows);
		grid.push_back(row);
		
		
		
		//process and hopefully BALL OUT early
		//code ...
		
	}
	
	output(grid);
	
	
	
	
	
	
	
	
	return EXIT_SUCCESS;
}

vector<int> Get_Knows() {
	vector<int> get_knows;
	int num;
	cin >> num;
	while (num != -1) {
		get_knows.push_back(num);
		cin >> num;
	}
	
	return get_knows;
}

void output(vector<vector<bool>> const& grid) {
	for (auto it: grid) {
		for (auto it2: it) {
			cout <<  it2 << " ";
		}
		std::cout <<  endl;
	}
	return;
};
vector<bool> Get_Row(unsigned int const& length) {
	vector<bool> row;
	for (int i = 0; i < length; ++i) {
		row.push_back(false);
	}
	
	return row;
}

void Fill(vector<bool> & row, vector<int> const& knows) {
	
	for (auto const& it: knows) {
		row[it] = true;
	}
	
	return;
}
	
