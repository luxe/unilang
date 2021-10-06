#include <iostream>
#include <string>
#include <random>
#include <chrono>


//I'm testing to see if there is a directory depth limit because there is no rope long enough out of this growing code base.
//Conclusion: No, there does not appear to be.  HOWEVER, there is a limit when you use the 'tree' command.
std::string random_name(void){
	
	static unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	static std::default_random_engine generator(seed1);
	std::uniform_int_distribution<int> letter(65,90);
	std::uniform_int_distribution<int> size(1,16);
	
	int amount = size(generator);
	std::string str;
	char c;
	for (int i = 0; i < amount; ++i){
		c = (char)letter(generator);
		str+=c;
	}

	return str;
}

int main(){
	
	std::string path = "HOLYCOWBRO";
	for (int i = 0; i < 996; ++i){
		path+="/"+random_name();
	}
	
	system(("mkdir -p " + path).c_str());
}