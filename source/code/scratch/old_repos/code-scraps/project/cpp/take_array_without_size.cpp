#include <iostream>
#include <string>
#include <cstdlib>

template<std::size_t A, std::size_t B>
void Take_2D_Array( int (&a)[A][B]){

    return;
}

int main(){

    int a[100][100] = {};
    Take_2D_Array(a);


    return 0;
}
