#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stack>





void Add_To_Combos(std::vector<std::string> & combos, std::vector<std::string> const& temp){
	
	std::string str;
	for (auto const& it: temp){
		//str+= it + "&";
		str+=it;
	}
	//combos.push_back(str.substr(0, str.size()-1));
	combos.push_back(str);
	return;
}


std::vector<std::string> Combonize(std::vector<std::string> const& folders){
	
	
	std::vector<std::string> combos;
	std::vector<std::string> temp;
	

	for (int size = 1; size < folders.size()+1; ++size){
		for (int start_pos = 0; start_pos < folders.size()-1; ++start_pos){
			for (int i = start_pos; i < folders.size(); ++i){
				if (temp.size() < size){
					temp.push_back(folders[i]);
				}
				if (temp.size() == size){
					//add it to combos
					Add_To_Combos(combos,temp);
					
					temp.pop_back();
				}
			}
			temp.clear();
		}
	}
	
	
	return combos;
}


int main(){
	
	std::vector<std::string> v {"1","2","3","4"};
	auto combos = Combonize(v);
	
	for (auto it: combos){
		std::cout << it << std::endl;
	}
	

	

}
