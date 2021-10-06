#include <iostream>

using namespace std;

int main(){
	
	int* ptr = new int();
	delete ptr;
	cout << "test" <<endl;
	//valgrind --error-limit=no --verbose --num-callers=50 --freelist-vol=2000000 --leak-check=yes --leak-resolution=high --error-limit=no --cachesim=yes  ./driver.exe
	
	//TOO MUCH OUTPUT(DOES NOT EFFECT ERROR CATCH ABILITY?): --trace-syscalls=yes --trace-signals=yes --trace-sched=yes --trace-symtab=yes --trace-malloc=yes
	//DOES NOT WORK: --trace-pthread=all
	return 0;
}