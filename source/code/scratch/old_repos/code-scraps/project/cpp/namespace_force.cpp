//Using the capability of symbolically linked directories,
//How can we force relationships based on directory layout?

#include <iostream>

//=========================================================================================
namespace FILE_D{
namespace FILE_D_obj{
}
namespace obj = FILE_D_obj;
//using namespace FILE_D_obj;
//namespace D_using = obj;
//using namespace D_using;
class D{public: void go(void);};void D::go(void){std::cout << "D" << std::endl;return;}
}
//=========================================================================================

//=========================================================================================
namespace FILE_E{
namespace FILE_E_obj{
}
namespace obj = FILE_E_obj;
//using namespace FILE_E_obj;
//namespace E_using = obj;
//using namespace E_using;
class E{public: void go(void);};void E::go(void){std::cout << "E" << std::endl;return;}
}
//=========================================================================================

//=========================================================================================
namespace FILE_C{
namespace FILE_C_obj{
	using namespace FILE_D;
	using namespace FILE_E;
}
namespace obj = FILE_C_obj;
//using namespace FILE_C_obj;
//namespace C_using = obj;
//using namespace C_using;
class C{public: void go(void);};void C::go(void){std::cout << "C" << std::endl;return;}
}
//=========================================================================================

//=========================================================================================
namespace FILE_A{
namespace FILE_A_obj{
	using namespace FILE_C;
	using namespace FILE_D;
}
namespace obj = FILE_A_obj;
//using namespace FILE_A_obj;
//namespace A_using = obj;
//using namespace A_using;
class A{public: void go(void);};void A::go(void){std::cout << "A" << std::endl;return;}
}
//=========================================================================================

//=========================================================================================
namespace FILE_B{
namespace FILE_B_obj{
	using namespace FILE_C;
}
namespace obj = FILE_B_obj;
//using namespace obj;
//using namespace FILE_B_obj;
//namespace B_using = obj;
//using namespace B_using;
class B{public: void go(void);};void B::go(void){std::cout << "B" << std::endl;return;}
}
//=========================================================================================


namespace FILE_main_obj{
	using namespace FILE_A;
	using namespace FILE_B;
}
namespace obj = FILE_main_obj;
//using namespace obj;
//using namespace FILE_main_obj;
//namespace main_using = obj;
//using namespace main_using;
int main(){
	std::cout << "hello" << std::endl;
	obj::A a;
	//obj::B b;
	//obj::C c;
	//obj::A a;
	//obj::B b;
}

