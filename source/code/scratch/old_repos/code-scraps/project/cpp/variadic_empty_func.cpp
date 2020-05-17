#include <string>
#include <iostream>
 
void Output() {return;}
 
template<typename First, typename ... Strings>
void Output(First arg, const Strings&... rest) {
    std::cout<<arg<<" ";
    Output(rest...);
}
 
int main() {
    Output("I","am","a","sentence");
    Output("Let's","try",1,"or",2,"digits");
    return 0;
}