#include <iostream>
#include <typeinfo>
#include <cassert>



class Thing{
	public: void do_it(){return;}
};

class Ping{
	public: void do_it(){return;}
};


#define CUSTOM_STRONG_TYPEDEF(OLD, NEW) \
template<typename T=OLD>            \
struct NEW##_SUFFIX{                  \
    using impl = T; \
}; \
using NEW = NEW##_SUFFIX<>::impl;



CUSTOM_STRONG_TYPEDEF(Thing,Boob)
CUSTOM_STRONG_TYPEDEF(Boob,Tube)






int main(){

	Boob hello;
	Tube tello;
	hello.do_it();
	tello.do_it();

	Thing thing;
	Ping ping;
	assert(typeid(hello) == typeid(tello));
}



//CUSTOM_STRONG_TYPEDEF(Thing,Boob)
//CUSTOM_STRONG_TYPEDEF(Boob,Noob)



//Noob n;
//n.do_it();




/*
//a user defined type
template<typename T>
class Base{
	public: void do_it(){return;}
};
using Widget = Base<float>;


#define CUSTOM_STRONG_TYPEDEF(T, D) \
struct D##_SUFFIX{}; \
using D = Base<D##_SUFFIX>;


CUSTOM_STRONG_TYPEDEF(int, boob)


boob hi;
*/


//try a custom strong def that compiles typedef
//CUSTOM_STRONG_TYPEDEF(Widget, Gadget)

//a function that takes the user defined type
/*
void function (Widget w){ 
	w.do_it();
	std::cout << "w" <<std::endl;
	return;
}
void function (Gadget w){ 
	w.do_it();
	std::cout << "g" <<std::endl;
	return;
}
*/
/*
int main(){


    //make the two "different types"
    //Widget w;
    //Gadget g;

    //call the function that should ONLY accept widgets
    //function(w);
    //function(g); //<- still compiles, but shouldn't
}
*/

/*


class Bae{};
CUSTOM_STRONG_TYPEDEF(Bae, Yo)


*/