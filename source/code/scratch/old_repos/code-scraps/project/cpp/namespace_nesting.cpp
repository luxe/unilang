#include <iostream>
#include <string>
using namespace std;
/*
// first name space
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
   // second name space
   inline namespace first_space{
      void func2(){
         cout << "Inside second_space" << endl;
      }
   }
}
*/



/*
namespace A{
namespace A_in{}
}
namespace B{
	namespace test{}
}
namespace C{
	void function(){
		std::cout << "hello world" << std::endl;
		return;
	}
}

namespace C{
	using namespace B::test;
}


*/

namespace A{namespace a{}}
namespace B{namespace b{}}





namespace A{
	namespace a{
		//A and B
	}
}

namespace B{
	namespace b{
		//A and B
	}
}


int main (){
	
   
   return 0;
}