#include <type_traits>

//a data type which provides a matching interface that of floating point primitives.
//it takes a floating point primitive as a template argument, and rewraps its funcunality
//in a class-like structure as apposed to built-in type. We do this so that we can inherit 
//from it later since inheriting from built-in types is not a language feature.

//recheck all the references and consts.  I believe some are wrong(found when referencing +=)
namespace inherit_primitives_implementation{
	template<typename T>
	class Floating_Point_Type{
	private: T primitive;
	public:

		using type = T;

		//constructors
		explicit Floating_Point_Type(){}
	    explicit Floating_Point_Type(T const& var): primitive(var){}

	    //deduce to the type when needed
	    operator T (){return primitive;}

	    //assignment operator
		T& operator = (T const& var){primitive = var;return primitive;}

	    //arithmetic operators
	    const T   operator +  (const T & y) const {return primitive + y;}
		const T   operator -  (const T & y) const {return primitive - y;}
		const T   operator *  (const T & y) const {return primitive * y;}
		const T   operator /  (const T & y) const {return primitive / y;}
		const T   operator +  (           ) const {return +primitive;}
		const T   operator -  (           ) const {return -primitive;}
		const T & operator ++ (           )       {return ++primitive;}
		const T   operator ++ (int        )       {auto temp = primitive; ++primitive; return temp;}
		const T & operator -- (           )       {return --primitive;}
		const T   operator -- (int        )       {auto temp = primitive; --primitive; return temp;}

		//comparison/relational operators
		const bool operator == (const T & y) const {return primitive == y;}
		const bool operator != (const T & y) const {return primitive != y;}
		const bool operator <  (const T & y) const {return primitive < y;}
		const bool operator >  (const T & y) const {return primitive > y;}
		const bool operator <= (const T & y) const {return primitive <= y;}
		const bool operator >= (const T & y) const {return primitive >= y;}

		//logical operators
		const bool operator ! (           ) {return !primitive;}
		const bool operator &&(const T & y) {return primitive&&y;}
		const bool operator ||(const T & y) {return primitive||y;}

		//compound assignment oerators
		const T & operator += (const T & y){return primitive+=y;}
		const T & operator -= (const T & y){return primitive-=y;}
		const T & operator *= (const T & y){return primitive*=y;}
		const T & operator /= (const T & y){return primitive/=y;}

		//allocation/deallocation
		//void* operator new(size_t x);
		//void* operator new[](size_t x);
		//void operator delete(void* x);
		//void operator delete[](void* x);
		
		//yes it is an operator lol
		//const Primitive operator ,(const T & y);
	};
}

//a data type which provides a matching interface that of integral primitives.
//it takes an integral primitive as a template argument, and rewraps its funcunality
//in a class-like structure as apposed to built-in type. We do this so that we can inherit 
//from it later since inheriting from built-in types is not a language feature.
namespace inherit_primitives_implementation{
	template<typename T>
	class Integral_Type{
	private: T primitive;
	public:

		using type = T;

		//constructors
		explicit Integral_Type(){}
	    explicit Integral_Type(T const& var): primitive(var){}

	    //deduce to the type when needed
	    operator T (){return primitive;}

	    //assignment operator
		T& operator = (T const& var){primitive = var;return primitive;}

	    //arithmetic operators
	    const T   operator +  (const T & y) const {return primitive + y;}
		const T   operator -  (const T & y) const {return primitive - y;}
		const T   operator *  (const T & y) const {return primitive * y;}
		const T   operator /  (const T & y) const {return primitive / y;}
		const T   operator +  (           ) const {return +primitive;}
		const T   operator -  (           ) const {return -primitive;}
		const T & operator ++ (           )       {return ++primitive;}
		const T   operator ++ (int        )       {auto temp = primitive; ++primitive; return temp;}
		const T & operator -- (           )       {return --primitive;}
		const T   operator -- (int        )       {auto temp = primitive; --primitive; return temp;}

		//comparison/relational operators
		const bool operator == (const T & y) const {return primitive == y;}
		const bool operator != (const T & y) const {return primitive != y;}
		const bool operator <  (const T & y) const {return primitive < y;}
		const bool operator >  (const T & y) const {return primitive > y;}
		const bool operator <= (const T & y) const {return primitive <= y;}
		const bool operator >= (const T & y) const {return primitive >= y;}

		//logical operators
		const bool operator ! (           ) {return !primitive;}
		const bool operator &&(const T & y) {return primitive&&y;}
		const bool operator ||(const T & y) {return primitive||y;}

		//compound assignment oerators
		const T & operator += (const T & y){return primitive+=y;}
		const T & operator -= (const T & y){return primitive-=y;}
		const T & operator *= (const T & y){return primitive*=y;}
		const T & operator /= (const T & y){return primitive/=y;}

		//integral specific
		const T   operator %  (const T & y) const {return primitive % y;}
		const T operator ~(){return ~primitive;}
		const T operator &(const T & y){return primitive & y;}
		const T operator |(const T & y){return primitive | y;}
		const T operator ^(const T & y){return primitive ^ y;}
		const T operator <<(const T & y){return primitive << y;}
		const T operator >>(const T & y){return primitive >> y;}
		const T & operator %= (const T & y){return primitive%=y;}
		const T & operator &= (const T & y){return primitive&=y;}
		const T & operator |= (const T & y){return primitive|=y;}
		const T & operator ^= (const T & y){return primitive^=y;}
		const T & operator <<= (const T & y){return primitive<<=y;}
		const T & operator >>= (const T & y){return primitive>>=y;}

		//allocation/deallocation
		//void* operator new(size_t x);
		//void* operator new[](size_t x);
		//void operator delete(void* x);
		//void operator delete[](void* x);
		
		//yes it is an operator lol
		//const Primitive operator ,(const T & y);
	};
}
//a type that contains a type based on the type passed in. Using type-traits we can set 
//a composed type to be one of the ones above (Floating_Point_Type or Integral_Type).
//you'll notice we have a third option which just represents an undefined state for 
//when a non-primitive type is accidently passed in. If a non-primitive type is passed in,
//the type will be undefined resulting in a compiler error.
namespace inherit_primitives_implementation{

	//this ensures that if anything other than 
	//a floating point or integral type is passed in,
	//the Extract_Out_Inheritable_Primitive type will be undefined
	template<class T, class Enable = void>
	class Extract_Out_Inheritable_Primitive;
	
	//choose this one if the template parameter 
	//is a floating point type
	template <typename T>
	class Extract_Out_Inheritable_Primitive<T, typename std::enable_if<std::is_floating_point<T>::value>::type>{
	public: using type = Floating_Point_Type<T>;};

	//choose this one if the template parameter 
	//is a integral type
	template <typename T>
	class Extract_Out_Inheritable_Primitive<T, typename std::enable_if<std::is_integral<T>::value>::type>{
	public: using type = Integral_Type<T>;};
}

//this is a template alias for a type that when given a primitive type,
//will contain an inheritable prmitive type which becomes the alias.
//essentially, this will be used by a client class to inherit "most" of the functionality
//from a given primitive.  It is used like this:
//class Class_Name: public Inherit_From<int>{/* more functionaility */};
//of course, you could choose a different primitive than int.
template <typename T>
using Inherit_From = typename
inherit_primitives_implementation::Extract_Out_Inheritable_Primitive<T>::type;

//by default, C++ will not inherit constructors or assignment operators.
//since both the class name and the inherited type must be eplicitly stated to make these,
//we have no choice but to use a macro to save the client the trouble of
//re-implementing these functions themselves.  Using this macro should provide a perfect
//inheritence if the inherit statement and this macro are both used together with the appropiate values.
#define FULLY_MATCH_PRIMITIVE(CLASS, PRIMITIVE)                \
public: using Inherit_From< PRIMITIVE >::Inherit_From;          \
CLASS (Inherit_From< PRIMITIVE >::type const& rhs){*this = rhs;} \
public: CLASS & operator = (Inherit_From< PRIMITIVE >::type const& rhs){Inherit_From< PRIMITIVE >::operator=(rhs);}private:


/*

In conclusion, here is an example of using this library
//-------------------------------------------------------
class Class: public Inherit_From<int>{

	FULLY_MATCH_PRIMITIVE(Class,int)

	//add your data and methods
	//use *this to reference the inherited primitive
};
//-------------------------------------------------------

 */
