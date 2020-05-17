#include <iostream>
#include <iomanip>
#include <type_traits>

//THE BATTLE OF TRYING TO WRITE:
//Void_Ptr_To_T_Ptr<T>(v) but also have it preserve constness
//final result?
//A small set of template type converter machinery and a macro

//this is now solved with a few type modifiers and an auto deducing template function
//typename added so it can be used in generic contexts


//TODO: remove when the standard has implemented this:
namespace std{
    
    //conjunction copy and pasted in
    template<class...> struct conjunction : std::true_type { };
    template<class B1> struct conjunction<B1> : B1 { };
    template<class B1, class... Bn>
    struct conjunction<B1, Bn...> : std::conditional_t<B1::value != false, conjunction<Bn...>, B1>  {};
    
    //bool constant copied and pasted in
    template <bool B>
    using bool_constant = integral_constant<bool, B>;

    //negation copy and pasted in
    template<class B>
    struct negation : std::bool_constant<!B::value> { };
}

//individual calls
namespace individual_calls{
  template<class T>       T*      t   (      void*      v){std::cout << __FUNCTION__ << '\n'; return static_cast<      T*     >(v);}
  template<class T> const T*      ct  (const void*      v){std::cout << __FUNCTION__ << '\n'; return static_cast<const T*     >(v);}
  template<class T>       T*const tc  (      void*const v){std::cout << __FUNCTION__ << '\n'; return static_cast<      T*const>(v);}
  template<class T> const T*const ctc (const void*const v){std::cout << __FUNCTION__ << '\n'; return static_cast<const T*const>(v);}
}

namespace type_traits{
    
    //BASIC:  
    
    //is_const
    template <class T> using          is_const   = std::is_const<T>;
    template <class T> constexpr bool is_const_v = is_const<T>::value;
    
    //is_not_const
    template <class T> using          is_not_const   = std::negation<is_const<T>>;
    template <class T> constexpr bool is_not_const_v = is_not_const<T>::value;
    
    //is_ptr
    template <class T> using          is_ptr   = std::is_pointer<T>;
    template <class T> constexpr bool is_ptr_v = is_ptr<T>::value;
    
    //is_not_ptr
    template <class T> using          is_not_ptr   = std::negation<is_ptr<T>>;
    template <class T> constexpr bool is_not_ptr_v = is_not_ptr<T>::value;
    
    
    //NOT FULLY SPECIFIC:
    
    //is_ptr_to_const
    template <class T> using          is_ptr_to_const   = std::conjunction<is_ptr<T>, is_const<std::remove_pointer_t<T>>>;
    template <class T> constexpr bool is_ptr_to_const_v = is_ptr_to_const<T>::value;
    
    //is_ptr_to_not_const
    template <class T> using          is_ptr_to_not_const   = std::conjunction<is_ptr<T>, std::negation<is_const<std::remove_pointer_t<T>>>>;
    template <class T> constexpr bool is_ptr_to_not_const_v = is_ptr_to_not_const<T>::value;
    
    //is_const_ptr
    template <class T> using          is_const_ptr   = std::conjunction<is_ptr<T>, is_const<T>>;
    template <class T> constexpr bool is_const_ptr_v = is_const_ptr<T>::value;
    
    //is_not_const_ptr
    template <class T> using          is_not_const_ptr   = std::conjunction<is_ptr<T>, is_not_const<T>>;
    template <class T> constexpr bool is_not_const_ptr_v = is_not_const_ptr<T>::value;
    
    //FULLY SPECIFIC:
    
    //is_const_ptr_to_const
    template <class T> using          is_const_ptr_to_const   = std::conjunction<is_const_ptr<T>, is_ptr_to_const<T>>;
    template <class T> constexpr bool is_const_ptr_to_const_v = is_const_ptr_to_const<T>::value;
    
    //is_not_const_ptr_to_const
    template <class T> using          is_not_const_ptr_to_const   = std::conjunction<is_not_const_ptr<T>, is_ptr_to_const<T>>;
    template <class T> constexpr bool is_not_const_ptr_to_const_v = is_not_const_ptr_to_const<T>::value;
    
    //is_const_ptr_to_not_const
    template <class T> using          is_const_ptr_to_not_const   = std::conjunction<is_const_ptr<T>, is_ptr_to_not_const<T>>;
    template <class T> constexpr bool is_const_ptr_to_not_const_v = is_const_ptr_to_not_const<T>::value;
    
    //is_not_const_ptr_to_not_const
    template <class T> using          is_not_const_ptr_to_not_const   = std::conjunction<is_not_const_ptr<T>, is_ptr_to_not_const<T>>;
    template <class T> constexpr bool is_not_const_ptr_to_not_const_v = is_not_const_ptr_to_not_const<T>::value;
    

}


//template type changing
template< class T, class U> struct convert_ptr_type                       {typedef       U        type;};
template< class T, class U> struct convert_ptr_type<      T*,       U>    {typedef       U*       type;};
template< class T, class U> struct convert_ptr_type<      T* const, U>    {typedef       U* const type;};
template< class T, class U> struct convert_ptr_type<const T*,       U>    {typedef const U*       type;};
template< class T, class U> struct convert_ptr_type<const T* const, U>    {typedef const U* const type;};

#define VOID_PTR_TO_T_PTR(t,v) static_cast<convert_ptr_type<decltype(v),t>::type>(v)


/*
template<class T, class V>
auto Void_Ptr_To_T_Ptr(V v)
-> typename std::enable_if_t<type_traits::is_not_const_ptr_to_not_const_v<V>,T*>
{
  return static_cast<T*>(v);
}
*/

//can I use enable_if but still get return type deduction?

//template<class T, class V> auto same(V* v) -> std::enable_if_t<type_traits::is_not_const_ptr_to_not_const_v<decltype(v)>,T*> {return individual_calls::t<T>(v);}
//template<class T, class V> auto same(V*const v) -> std::enable_if_t<type_traits::is_const_ptr_to_not_const_v<decltype(v)>,T*const> {return individual_calls::tc<T>(v);}
//template<class T> auto same() -> auto {return individual_calls::ct<T>(v);}
//template<class T> auto same() -> auto {return individual_calls::ctc<T>(v);}


int triple (int x){
    return x*3;
}

float triple (float x){
    return x*3;
}

int main(){
    std::cout << std::boolalpha;
    
    int hello = 4;
    void* hi = &hello;
    void*const hi2 = &hello;
    const void*const hi3 = &hello;
    
    //convert_ptr_type<decltype(hi),int>::type o = static_cast<convert_ptr_type<decltype(hi),int>::type>(hi);
    //convert_ptr_type<decltype(hi2),int>::type o3 = nullptr;
    
    std::cout << type_traits::is_ptr_to_const_v<decltype(VOID_PTR_TO_T_PTR(int,hi))> << '\n';
    std::cout << type_traits::is_ptr_to_const_v<decltype(VOID_PTR_TO_T_PTR(int,hi2))> << '\n';
    std::cout << type_traits::is_ptr_to_const_v<decltype(VOID_PTR_TO_T_PTR(int,hi3))> << '\n';
    //convert_ptr_type<void,int>(hi)::type o;
    
    //std::cout << type_traits::is_not_const_ptr_to_not_const_v<decltype(hi)> << '\n';
    //same<int>(hi);
    //same<int>(hi2);
    
    //std::cout << type_traits::t<const int*>::value << std::endl;
    //std::cout << type_traits::is_ptr_to_const_v<const int*> << '\n';
    //std::cout << type_traits::is_ptr_to_const_v<const int*const> << '\n';
    //std::cout << type_traits::is_ptr_to_const_v<int*> << '\n';
    //std::cout << type_traits::is_ptr_to_const_v<int*const> << '\n';
    //std::cout << type_traits::is_ptr_to_const_v<const int> << '\n';
    
    //std::cout << type_traits::ptr_v<const int*> << '\n';
    //std::cout << type_traits::ptr_v<const int*const> << '\n';
    //std::cout << type_traits::ptr_v<int*> << '\n';
    //std::cout << type_traits::ptr_v<int*const> << '\n';
    
    
    //std::cout << std::is_same<void,typename std::remove_pointer<void*>::type>::value << '\n';
}
