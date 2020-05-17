#include <iostream>


template <typename T>
void foo(T x)
{
    printf( "foo( other)\n");
}


template <>
void foo<bool>( bool x)
{
    printf( "foo( bool)\n");
}


template <>
void foo<unsigned int>( unsigned int x)
{
    printf( "foo( unsigned int)\n");
}


template <>
void foo<int>( int x)
{
    printf( "foo( int)\n");
}



int main () 
{
    foo( true);
    foo( false);
    foo( static_cast<unsigned int>( 0));
    foo( 0U);
    foo( 1U);
    foo( 2U);
    foo( 0);
    foo( 1);
    foo( 2);
    foo("test");
}
