#include <fstream>

template <char> void foo(std::string const &);      // no implementation

template <> void foo<'a'>(std::string const & s) {return;} 
template <> void foo<'b'>(std::string const & s) {return;}


int main(){
	
	const char ch = 'c';
	
	foo<'c'>("hello world");
	
	return 0;
}
